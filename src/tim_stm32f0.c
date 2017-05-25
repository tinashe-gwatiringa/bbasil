#include "tim_stm32f0.h"

void init_TIM14(uint32_t period)
{
	NVIC_EnableIRQ(TIM14_IRQn);

	uint32_t psc = (period*BUS_FREQ)/((uint32_t)(pow(2,16)))+1;
	uint32_t arr = (period*BUS_FREQ)/psc;

	RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
	TIM14->PSC = psc;
	TIM14->ARR = arr;
	TIM14->DIER |= TIM_DIER_UIE;
	TIM14->CR1 |= TIM_CR1_CEN;
}


