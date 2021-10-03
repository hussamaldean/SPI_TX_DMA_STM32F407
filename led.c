#include "led.h"

#define GPIOD_CLOCK    (1<<3)        		
//bits of the pins 
#define LED_red_BIT    (1U<<28)					
#define LED_green_BIT  (1U<<24)
#define LED_orange_BIT (1U<<26)
#define LED_blue_BIT   (1U<<30)
//LED port 
#define	LED_PORT		    GPIOD						
//bit possition for color
#define	LED_red		 		 (1U<<14)         
#define LED_green  		 (1U<<12)
#define LED_blue       (1U<<15)
#define LED_orange     (1U<<13)

	/*
	* @brief initialize the built-in LED of STM32F407-DISCO
  * @param  None	
  * @retval None		
		
*/

void led_init()
	{
	RCC->AHB1ENR |=GPIOD_CLOCK;
	GPIOD->MODER |= LED_red_BIT|LED_green_BIT|LED_orange_BIT|LED_blue_BIT;
	
	}