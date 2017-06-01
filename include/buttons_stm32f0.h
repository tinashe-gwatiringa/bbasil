#ifndef BUTTONS_STM32F0_H
#define BUTTONS_STM32F0_H

#include "gpio_stm32f0.h"
#include "stm32f0xx.h"

void button_init(GPIO_TypeDef *port, uint16_t pin);
void button_init_multi(GPIO_TypeDef *port, uint16_t* pin, uint8_t n_elements);
void button_config_interrupt(void);

#endif
