#ifndef TIM_STM32F0_H
#define TIM_STM32F0_H

#include "stm32f0xx.h"
#include <math.h>
#define BUS_FREQ 48e6

void tim_init(uint32_t period);

#endif
