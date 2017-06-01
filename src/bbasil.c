#include "bbasil.h"

char progress_bar[PROG_BAR_SIZE];
uint16_t sunlight;

void splash(void)
{
	lcd_two_line_write("bbasil", "v0.1.2");
	delay(1e6);
}


void init(void)
{
	//init lcd
	lcd_init();

	//init led's
	uint16_t pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	led_init_multi(GPIOB, pins, 8);

	//init adc's
	adc_init(GPIOA, 7); //B11

	//init timer
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
