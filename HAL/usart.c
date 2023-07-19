/*
 * usart.c
 *
 *  Created on: 2023年5月20日
 *      Author: zhengshengbing
 */
#include "usart.h"
#include "debug.h"
#include "string.h"

void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

char usart_receive_data[128]={0};
volatile char usart_receive_complete=0;
extern void protocol_handle();


void USARTx_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    NVIC_InitTypeDef  NVIC_InitStructure = {0};

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 | RCC_APB1Periph_USART3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    /* USART2 TX-->A.2   RX-->A.3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    USART_InitStructure.USART_BaudRate = 3000000;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART2, &USART_InitStructure);
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel=USART2_IRQn;                  //中断通道
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;                  //通道使能
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;        //先优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;               //从优先级

    NVIC_Init(&NVIC_InitStructure);                                //中断初始化

    USART_Cmd(USART2, ENABLE);
}

void send(char *w)
{
//    printf("ss:%d\n",strlen(w));
    while( !USART_GetFlagStatus(USART2,USART_FLAG_TC));
    USART_SendData(USART2, 0x55);
    while( !USART_GetFlagStatus(USART2,USART_FLAG_TC));
    USART_SendData(USART2, 0xAA);
    while( !USART_GetFlagStatus(USART2,USART_FLAG_TC));
    USART_SendData(USART2, strlen(w)+1);
    while( !USART_GetFlagStatus(USART2,USART_FLAG_TC));
    for(int i=0;i<strlen(w)+1;i++)
    {
        USART_SendData(USART2, w[i]);
        while( !USART_GetFlagStatus(USART2,USART_FLAG_TC));
    }
}

void USART2_IRQHandler(void)
{
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {
        uint8_t rev = USART_ReceiveData(USART2);

        static int flag = 0;
        static int length = 0;
        static int count = 0;
        switch (flag)
        {
        case 0:
          if(rev==0x55)flag++;
          else {flag=0;count=0;length=0;}
          break;
        case 1:
          if(rev==0xAA)flag++;
          else {flag=0;count=0;length=0;}
          break;
        case 2:
          length = rev;  flag++;
          break;
        case 3:
            usart_receive_data[count]=(char)rev;count++;
          if(count == length) {
              protocol_handle();
//              printf("usart_receive_data:%s\n",usart_receive_data);
              usart_receive_complete=1;flag=0;count=0;length=0;}
          break;
        default :flag=0;count=0;length=0;break;
        }
    }
}
