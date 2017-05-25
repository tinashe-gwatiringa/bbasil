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
uint8_t bitpattern = 0xAA;

//function declarations
void init_TIM14(uint32_t delay);
void init_NVIC(void);

void main (void)
{
	lcd_init();							// Initialise lcd
	lcd_string("bbasil");				// Display string on line 1
	lcd_command(LCD_GOTO_LINE_2);		// Move cursor to line 2
	lcd_string("v0.0.1");				// Display string on line 2

	//initialise led's
	uint16_t pins[3] = {0, 1, 2};
	led_init_multi(GPIOB, pins, 3);
	init_TIM14(2);
	init_NVIC();

	while(1)
	{
		//led_heartbeat(GPIOB, 0);
		//delay(1.5e6);
	}
}										// End of main


//function calls
void init_TIM14(uint32_t delay)
{
	uint32_t psc = delay*735;
	uint32_t arr = 48e6/psc;
	RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
	TIM14->PSC = psc; //734;
	TIM14->ARR = arr; //65306;
	TIM14->DIER |= TIM_DIER_UIE;
	TIM14->CR1 |= TIM_CR1_CEN;
}

void init_NVIC(void)
{
	NVIC_EnableIRQ(TIM14_IRQn);
}

//interrupt service requests
void TIM14_IRQHandler(void)
{
	bitpattern = ~bitpattern;
	GPIOB->ODR = bitpattern;
	TIM14->SR &= ~TIM_SR_UIF;
}
