#include <gpio_stm32f0.h>

void clock_enable(GPIO_TypeDef *port)
{
	switch ((uint32_t)port)
	{
		case (uint32_t)GPIOA:
			RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
			break;
		case (uint32_t)GPIOB:
			RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
			break;
		case (uint32_t)GPIOC:
			RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
			break;
	}
}


void set_mode(GPIO_TypeDef *port, uint16_t pin, uint8_t mode)
{
	switch (mode)
	{
		case INPUT:
			port->MODER &= ~(GPIO_MODER_MODER0 << 2*pin);
			break;
		case OUTPUT:
			port->MODER |= (GPIO_MODER_MODER0_0 << 2*pin);
			break;
		case ALTERNATE:
			port->MODER |= (GPIO_MODER_MODER0_1 << 2*pin);
			break;
		case ANALOGUE:
			port->MODER |= (GPIO_MODER_MODER0 << 2*pin);
			break;
	}
}


void set_pull(GPIO_TypeDef *port, uint16_t pin, uint8_t pull)
{
	switch (pull)
	{
		case UP:
			port->PUPDR |= GPIO_PUPDR_PUPDR0_0 << 2*pin;
			break;
		case DOWN:
			port->MODER |= (GPIO_MODER_MODER0_1 << 2*pin);
			break;
	}
}
