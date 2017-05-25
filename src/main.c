//                    			BBASIL
//==================================================================
// WRITTEN BY:   	Tinashe Gwatiringa, Darryn Jordan
// DATE CREATED:	25 May 2017
// TARGET:	   	   	STMicroelectronics STM32F051C6
// DESCRIPTION:


//includes
#include "lcd_stm32f0.h"
#include "led_stm32f0.h"
#include "stm32f0xx.h"

#include <stdint.h>

//macros

//global variables

//function declarations
void delay(uint32_t cycles);

void main (void)
{
	lcd_init();							// Initialise lcd
	lcd_string("bbasil");				// Display string on line 1
	lcd_command(LCD_GOTO_LINE_2);		// Move cursor to line 2
	lcd_string("v0.0.1");				// Display string on line 2

	//initialise led's
	uint8_t pins[3] = {0, 1, 2};
	led_init_multi(GPIOB, pins, 3);

	GPIOB->ODR = 7;
	for(;;);							// Loop forever
}										// End of main

//function definitions
void delay(uint32_t cycles)
{
	volatile uint32_t count;

	for (count = 0; count < cycles; count++)
	{
		for (uint16_t i = 0; i < 4096; i++);
	}
}


