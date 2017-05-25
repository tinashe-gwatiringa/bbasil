#include "led_stm32f0.h"

void led_init(GPIO_TypeDef *port, uint8_t pin)
{
	clock_enable(port);
	set_mode(port, pin, OUTPUT);
}


void led_init_multi(GPIO_TypeDef *port, uint8_t* pin, uint8_t n_elements)
{
	for (int i = 0; i < n_elements; i++)
	{
		led_init(port, pin[i]);
	}
}
