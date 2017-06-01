#ifndef BBASIL_H
#define BBASIL_H

#include "stm32f0xx.h"
#include "adc_stm32f0.h"
#include "lcd_stm32f0.h"
#include "led_stm32f0.h"
#include "tim_stm32f0.h"

#define PROG_BAR_SIZE 	14
#define DIRECT_SUN 		128
#define SUN_PER_DAY 	(10)

void splash(void);
void init(void);
void status_update(void);
char* getProgressBar(float percentage);

uint8_t is_enough_sun(uint8_t adc_value);



#endif
