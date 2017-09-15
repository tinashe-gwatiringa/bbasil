#ifndef BBASIL_H
#define BBASIL_H

#include "stm32f0xx.h"
#include "adc_stm32f0.h"
#include "lcd_stm32f0.h"
#include "led_stm32f0.h"
#include "tim_stm32f0.h"
#include "buttons_stm32f0.h"

#define PROG_BAR_SIZE 	14
#define DIRECT_SUN 		64
#define SUN_PER_DAY 	(4*60*60)
#define MAX_WATER_LEVEL 1440
#define WATER_PERIOD	60

void splash(void);
void init(void);
void status_update(void);
char* getProgressBar(float percentage);

uint8_t is_enough_sun(uint8_t adc_value);
void check_water(void);

#endif
