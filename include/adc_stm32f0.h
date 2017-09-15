#ifndef ADC_STM32F0_H
#define ADC_STM32F0_H

#include <stdint.h>
#include "stm32f0xx.h"

void adc_init(GPIO_TypeDef *port, uint16_t pin);
void adc_cont(void);

uint8_t get_adc_sample(uint8_t channel);


#endif
