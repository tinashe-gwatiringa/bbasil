#include "led_stm32f0.h"
#include "lcd_stm32f0.h"

void led_init(GPIO_TypeDef *port, uint16_t pin)
{
	clock_enable(port);
	set_mode(port, pin, OUTPUT);
}


void led_init_multi(GPIO_TypeDef *port, uint16_t* pin, uint8_t n_elements)
{
	for (int i = 0; i < n_elements; i++)
	{
		led_init(port, pin[i]);
	}
}


void led_heartbeat(GPIO_TypeDef *port, uint16_t pin)
{
	port->ODR &= ~(uint16_t)(1 << pin);
	port->ODR |= (uint16_t)(1 << pin);
	delay(1e5);
	port->ODR &= ~(uint16_t)(1 << pin);
	delay(1e5);
	port->ODR |= (uint16_t)(1 << pin);
	delay(1e5);
	port->ODR &= ~(uint16_t)(1 << pin);
}
