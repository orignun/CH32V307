/*
 * usart.h
 *
 *  Created on: 2023Äê5ÔÂ20ÈÕ
 *      Author: zhengshengbing
 */

#ifndef HAL_USART_H_
#define HAL_USART_H_

extern char usart_receive_data[128];
extern volatile char usart_receive_complete;


void USARTx_CFG(void);
void send(char *w);

#endif /* HAL_USART_H_ */
