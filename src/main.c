//                    			BBASIL
//==================================================================
// WRITTEN BY:   	Tinashe Gwatiringa, Darryn Jordan
// DATE CREATED:	25 May 2017
// TARGET:	   	   	STMicroelectronics STM32F051C6
// DESCRIPTION:


//includes
#include "stm32f0xx.h"
#include "bbasil.h"

//macros

//global variables

//function declarations

void main (void)
{
	init();
	splash();
	while(1)
	{
		status_update();
		check_water();
	}
}
