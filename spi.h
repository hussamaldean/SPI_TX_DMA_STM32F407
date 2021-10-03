#ifndef __spi__h

#define __spi__h
#include "stm32f4xx.h"                  // Device header


void spi1_init(void);

void dma2_stream3_ch2_init(void);

void spi_transfer_dma(uint32_t src,uint32_t len);


#endif
