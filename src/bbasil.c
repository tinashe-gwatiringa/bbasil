#include "bbasil.h"

char progress_bar[PROG_BAR_SIZE];
uint16_t sunlight;
uint16_t g_water_level = MAX_WATER_LEVEL;
uint8_t gb_water_me = 0;

void splash(void)
{
	lcd_two_line_write("bbasil", "v0.1.2");
	delay(1e6);
}


void init(void)
{
	//init lcd
	lcd_init();

	//init buttons
	uint16_t buttons[4] = {0, 1, 2, 3};
	button_init_multi(GPIOA, buttons, 4);
	button_config_interrupt();

	//init led's
	uint16_t leds[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	led_init_multi(GPIOB, leds, 8);

	//init adc's
	adc_init(GPIOA, 7); //B11

	//init timer
	init_TIM2(WATER_PERIOD);
	init_TIM14(2);

	progress_bar[0] = '[';
	progress_bar[15] = ']';

	sunlight = 0;
}


char* getProgressBar(float percentage)
{
	uint8_t progress = (uint8_t)(PROG_BAR_SIZE*percentage);

	for (int i = 1; i <= PROG_BAR_SIZE; i++)
	{
		if (i <= progress)
			progress_bar[i] = '#';
		else
			progress_bar[i] = ' ';
	}

	return progress_bar;
}


void status_update()
{
	lcd_two_line_write("SUNLIGHT", getProgressBar((float)(sunlight)/SUN_PER_DAY));
	delay(1e6);
}


uint8_t is_enough_sun(uint8_t adc_value)
{
	if (adc_value >= DIRECT_SUN)
		return 1;
	else
		return 0;
}

void check_water(void)
{
	if (gb_water_me == 1)
	{
		led_heartbeat(GPIOB, 1);
	}
}

void TIM2_IRQHandler(void)
{
	if (g_water_level == 0)
	{
		gb_water_me = 1;
	}
	else
	{
		g_water_level--;
	}

	//ack interrupt
	TIM2->SR &= ~TIM_SR_UIF;
}

void TIM14_IRQHandler(void)
{
	if (is_enough_sun(get_adc_sample(7)))
	{
		led_heartbeat(GPIOB, 0);
		sunlight++;
	}

	//ack interrupt
	TIM14->SR &= ~TIM_SR_UIF;
}


void EXTI0_1_IRQHandler(void)
{
	delay(100);

	if ((GPIOA->IDR & GPIO_IDR_0) == 0)
	{
		GPIOB->ODR = (uint8_t)(((float)sunlight/SUN_PER_DAY)*8);
	}
	else if ((GPIOA->IDR & GPIO_IDR_1) == 0)
	{
		led_heartbeat(GPIOB, 1);
		g_water_level = MAX_WATER_LEVEL;
		gb_water_me = 0;
	}

	EXTI->PR |= EXTI_PR_PR1;
}
