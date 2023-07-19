/*
 * tim.c
 *
 *  Created on: 2023年5月21日
 *      Author: zhengshengbing
 */

#include "debug.h"
#include "tim.h"
#include "lvgl.h"

volatile uint32_t SysTickCnt;

void TIM3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void Timer3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;   //定义结构体名字

    NVIC_InitTypeDef NVIC_InitStructure;                 //定义结构体名字

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  //使能定时器时钟

    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;      //定时其分频系数
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;  //模式选择向上计数
    TIM_TimeBaseInitStructure.TIM_Period=arr;                      //重装载
    TIM_TimeBaseInitStructure.TIM_Prescaler=psc;                   //预分频

    TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);             //定时器基础功能初始化

    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);                       //使能定时器更新中断

    NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;                  //中断通道
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;                  //通道使能
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;        //先优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;               //从优先级

    NVIC_Init(&NVIC_InitStructure);                                //中断初始化
    TIM_Cmd(TIM3,ENABLE);                                          //使能定时器

}

void Timer2_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;   //定义结构体名字

    NVIC_InitTypeDef NVIC_InitStructure;                 //定义结构体名字

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  //使能定时器时钟

    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;      //定时其分频系数
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;  //模式选择向上计数
    TIM_TimeBaseInitStructure.TIM_Period=arr;                      //重装载
    TIM_TimeBaseInitStructure.TIM_Prescaler=psc;                   //预分频

    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);             //定时器基础功能初始化

    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);                       //使能定时器更新中断

    NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;                  //中断通道
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;                  //通道使能
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;        //先优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;               //从优先级

    NVIC_Init(&NVIC_InitStructure);                                //中断初始化
    TIM_Cmd(TIM2,ENABLE);                                          //使能定时器

}
void TIM3_IRQHandler(void)
{
    SysTickCnt++;
    lv_tick_inc(1);
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update); // 清除掉 TIMx 的更新中断标志
}
