#include "bbasil.h"

void splash(void)
{
	lcd_string("bbasil");				// Display string on line 1
	lcd_command(LCD_GOTO_LINE_2);		// Move cursor to line 2
	lcd_string("v0.1.1");				// Display string on line 2
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
}

//interrupt handlers
void TIM14_IRQHandler(void)
{
	//led_heartbeat(GPIOB, 0);
	GPIOB->ODR = get_adc_sample(7);
	TIM14->SR &= ~TIM_SR_UIF;
}
