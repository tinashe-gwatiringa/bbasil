#ifndef LED_STM32F0_H
#define LED_STM32F0_H

#include "gpio_stm32f0.h"
#include "stm32f0xx.h"

void led_init(GPIO_TypeDef *port, uint16_t pin);
void led_init_multi(GPIO_TypeDef *port, uint16_t* pin, uint8_t n_elements);
void led_heartbeat(GPIO_TypeDef *port, uint16_t pin);


#endif
