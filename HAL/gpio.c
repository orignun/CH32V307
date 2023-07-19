/*
 * gpio.c
 *
 *  Created on: 2023Äê5ÔÂ21ÈÕ
 *      Author: zhengshengbing
 */

#include "debug.h"
#include "gpio.h"

void LCD_Reset_GPIO_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure={0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA,GPIO_Pin_15);

    GPIO_ResetBits(GPIOA,GPIO_Pin_15);
    Delay_Ms(100);
    GPIO_SetBits(GPIOA,GPIO_Pin_15);
}

void POWER_GPIO_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure={0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void GPIO_ALL_Init(void)
{
    LCD_Reset_GPIO_Init();
    POWER_GPIO_Init();
}
