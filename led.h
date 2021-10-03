#ifndef __led__h
#define __led__h
#include "stm32f4xx.h"                  // Device header
#define	LED_red		 		 (1U<<14)         
#define LED_green  		 (1U<<12)
#define LED_blue       (1U<<15)
#define LED_orange     (1U<<13)
#define	LED_PORT		    GPIOD	
void led_init();

#endif