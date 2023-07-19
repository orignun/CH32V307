/*
 * tim.c
 *
 *  Created on: 2023��5��21��
 *      Author: zhengshengbing
 */

#include "debug.h"
#include "tim.h"
#include "lvgl.h"

volatile uint32_t SysTickCnt;

void TIM3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void Timer3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;   //����ṹ������

    NVIC_InitTypeDef NVIC_InitStructure;                 //����ṹ������

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  //ʹ�ܶ�ʱ��ʱ��

    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;      //��ʱ���Ƶϵ��
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;  //ģʽѡ�����ϼ���
    TIM_TimeBaseInitStructure.TIM_Period=arr;                      //��װ��
    TIM_TimeBaseInitStructure.TIM_Prescaler=psc;                   //Ԥ��Ƶ

    TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);             //��ʱ���������ܳ�ʼ��

    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);                       //ʹ�ܶ�ʱ�������ж�

    NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;                  //�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;                  //ͨ��ʹ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;        //�����ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;               //�����ȼ�

    NVIC_Init(&NVIC_InitStructure);                                //�жϳ�ʼ��
    TIM_Cmd(TIM3,ENABLE);                                          //ʹ�ܶ�ʱ��

}

void Timer2_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;   //����ṹ������

    NVIC_InitTypeDef NVIC_InitStructure;                 //����ṹ������

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  //ʹ�ܶ�ʱ��ʱ��

    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;      //��ʱ���Ƶϵ��
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;  //ģʽѡ�����ϼ���
    TIM_TimeBaseInitStructure.TIM_Period=arr;                      //��װ��
    TIM_TimeBaseInitStructure.TIM_Prescaler=psc;                   //Ԥ��Ƶ

    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);             //��ʱ���������ܳ�ʼ��

    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);                       //ʹ�ܶ�ʱ�������ж�

    NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;                  //�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;                  //ͨ��ʹ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;        //�����ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;               //�����ȼ�

    NVIC_Init(&NVIC_InitStructure);                                //�жϳ�ʼ��
    TIM_Cmd(TIM2,ENABLE);                                          //ʹ�ܶ�ʱ��

}
void TIM3_IRQHandler(void)
{
    SysTickCnt++;
    lv_tick_inc(1);
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update); // ����� TIMx �ĸ����жϱ�־
}
