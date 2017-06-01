#include "buttons_stm32f0.h"

void button_init(GPIO_TypeDef *port, uint16_t pin)
{
	clock_enable(port);
	set_mode(port, pin, INPUT);
	set_pull(port, pin, UP);
}


void button_init_multi(GPIO_TypeDef *port, uint16_t* pin, uint8_t n_elements)
{
	for (int i = 0; i < n_elements; i++)
	{
		button_init(port, pin[i]);
	}
}


void button_config_interrupt(void)
{
	//enable irq
	NVIC_EnableIRQ(EXTI0_1_IRQn);

	//clock enable
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGCOMPEN;

	//map interrupts to SW1
	SYSCFG->EXTICR[1] |= SYSCFG_EXTICR1_EXTI1_PA;

	//falling edge
	EXTI->FTSR |= EXTI_FTSR_TR0;

	//unmask interrupt
	EXTI->IMR |= EXTI_IMR_MR0;
}

