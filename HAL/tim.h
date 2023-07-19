/*
 * tim.h
 *
 *  Created on: 2023Äê5ÔÂ21ÈÕ
 *      Author: zhengshengbing
 */

#ifndef HAL_TIM_H_
#define HAL_TIM_H_

extern volatile uint32_t SysTickCnt;

void Timer3_Int_Init(u16 arr,u16 psc);
void Timer2_Int_Init(u16 arr,u16 psc);

#endif /* HAL_TIM_H_ */
