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

void main (void)
{
	lcd_init();							// Initialise lcd
	lcd_string("bbasil");				// Display string on line 1
	lcd_command(LCD_GOTO_LINE_2);		// Move cursor to line 2
	lcd_string("v0.0.1");				// Display string on line 2

	//initialise led's
	uint16_t pins[3] = {0, 1, 2};
	led_init_multi(GPIOB, pins, 3);

	while(1)
	{
		led_heartbeat(GPIOB, 0);
		delay(1.5e6);
	}
}										// End of main



