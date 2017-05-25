#ifndef PORTS_STM32F0_H
#define PORTS_STM32F0_H

#include <stdint.h>
#include "stm32f0xx.h"

enum Mode {INPUT, OUTPUT, ALTERNATE, ANALOGUE};

void clock_enable(GPIO_TypeDef *port);
void set_mode(GPIO_TypeDef *port, uint32_t pin, uint8_t mode);

#endif
