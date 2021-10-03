#include "spi.h"
#include "debug.h"
#include "led.h"
char data[]={'A','B','C','D','E','F','G'};
volatile uint8_t finished=0;
void delayMs(int delay)

{

volatile int i;

for(; delay>0 ;delay--)

{

for(i =0; i<3195;i++);

}

}

int main(void)
	{
	printf("system init\r\n");
	led_init();
	spi1_init();
	dma2_stream3_ch2_init();
	printf("system init finished\r\n");
	
	while(1)

			{
			spi_transfer_dma((uint32_t)data,sizeof(data));
			while(finished==0){}
			finished=0;
			delayMs(10);
			
			}
	}
void DMA2_Stream3_IRQHandler(void)
		{
			
		if(DMA2->LISR&(DMA_LISR_TCIF3))
				{
					LED_PORT->ODR^=LED_blue;
					printf("finished transfered\r\n");
					finished=1;
					DMA2_Stream3->CR&=~DMA_SxCR_EN;
					DMA2->LIFCR |=DMA_LIFCR_CTCIF3;
				}
				
		if(DMA2->LISR&(DMA_LISR_HTIF3))
				{
					LED_PORT->ODR^=LED_green;
					printf("half transfered\r\n");
					DMA2->LIFCR |=DMA_LIFCR_CHTIF3;
				}
				
		
		if(DMA2->LISR&(DMA_LISR_TEIF3))
						{
						printf("transfer error interrupt\r\n");
						DMA2->LIFCR|=(DMA_LIFCR_CTEIF3);
						}
						
		if(DMA2->LISR&(DMA_LISR_DMEIF3))
						{
						printf("Direct mode interrupt error\r\n");
						DMA2->LIFCR|=(DMA_LIFCR_CDMEIF3);
						}
						
		if(DMA2->LISR&(DMA_LISR_FEIF3))
						{
						printf("FIFO error interrupt\r\n");
						DMA2->LIFCR|=(DMA_LIFCR_CFEIF3);
						}

			NVIC_ClearPendingIRQ(DMA2_Stream3_IRQn);
		}