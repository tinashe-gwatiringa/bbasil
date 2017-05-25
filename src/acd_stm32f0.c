#include "gpio_stm32f0.h"

void adc_init(GPIO_TypeDef *port, uint16_t pin)
{
	RCC->APB2ENR |= RCC_APB2ENR_ADCEN;			//enable clock for ADC

	clock_enable(port);
	set_mode(port, pin, ANALOGUE);

	ADC1->CHSELR |= ADC_CHSELR_CHSEL5; 			//channel 5
	ADC1->CFGR1 |= ADC_CFGR1_RES_1; 			//8-bit resolution
	ADC1->CR |= ADC_CR_ADEN; 					//set ADEN=1 in the ADC_CR register
	while((ADC1->ISR & ADC_ISR_ADRDY) == 0); 	//wait until ADRDY == 1 in ADC_ISR

	ADC1->CR |= ADC_CR_ADSTART;					//start adc sampling
}

