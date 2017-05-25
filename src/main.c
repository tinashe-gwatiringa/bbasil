//                    			BBASIL
//==================================================================
// WRITTEN BY:   	Tinashe Gwatiringa, Darryn Jordan
// DATE CREATED:	25 May 2017
// TARGET:	   	   	STMicroelectronics STM32F051C6
// DESCRIPTION:


//includes
#include "stm32f0xx.h"

#include "adc_stm32f0.h"
#include "lcd_stm32f0.h"
#include "led_stm32f0.h"
#include "tim_stm32f0.h"

#include <stdint.h>

//macros

//global variables
uint8_t bitpattern = 0xAA;

//function declarations

void main (void)
{
	lcd_init();							// Initialise lcd
	lcd_string("bbasil");				// Display string on line 1
	lcd_command(LCD_GOTO_LINE_2);		// Move cursor to line 2
	lcd_string("v0.0.1");				// Display string on line 2

	//init led's
	uint16_t pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	led_init_multi(GPIOB, pins, 8);

	//init adc's
	adc_init(GPIOA, 5);

	//init timer
	init_TIM14(2);
	
  while(1)
	{

	}
}										// End of main

//interrupt handlers
void TIM14_IRQHandler(void)
{
	led_heartbeat(GPIOB, 0);
	GPIOB->ODR = get_adc_sample(5);
	TIM14->SR &= ~TIM_SR_UIF;
}
