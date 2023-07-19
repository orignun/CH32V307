/*
 * spi.h
 *
 *  Created on: 2023Äê5ÔÂ20ÈÕ
 *      Author: zhengshengbing
 */

#ifndef HAL_SPI_H_
#define HAL_SPI_H_

void SPI_FullDuplex_Init(void);
void DMA_Rx_Init( DMA_Channel_TypeDef* DMA_CHx, u32 ppadr, u32 memadr, u32 bufsize );

#endif /* HAL_SPI_H_ */
