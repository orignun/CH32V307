/*
 * gt911.c
 *
 *  Created on: 2023Äê6ÔÂ30ÈÕ
 *      Author: zhengshengbing
 */
#include "i2c.h"
#include "ch32v30x_i2c.h"

void IIC_Init(u32 bound, u16 address)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    I2C_InitTypeDef  I2C_InitTSturcture = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_I2C1, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    I2C_InitTSturcture.I2C_ClockSpeed = bound;
    I2C_InitTSturcture.I2C_Mode = I2C_Mode_I2C;
    I2C_InitTSturcture.I2C_DutyCycle = I2C_DutyCycle_16_9;
    I2C_InitTSturcture.I2C_OwnAddress1 = address;
    I2C_InitTSturcture.I2C_Ack = I2C_Ack_Enable;
    I2C_InitTSturcture.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(I2C1, &I2C_InitTSturcture);

    I2C_Cmd(I2C1, ENABLE);

#if(I2C_MODE == HOST_MODE)
    I2C_AcknowledgeConfig(I2C1, ENABLE);

#endif
}

void AT24CXX_ReadOneByte(u16 ReadAddr, u8 *pBuffer, u16 NumToRead)
{
    u8 temp = 0;

    while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY) != RESET)
        ;
    I2C_GenerateSTART(I2C1, ENABLE);

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
        ;
    I2C_Send7bitAddress(I2C1, GT911_DIV_W, I2C_Direction_Transmitter);

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
        ;

#if(Address_Lenth == Address_8bit)
    I2C_SendData(I2C1, (u8)(ReadAddr & 0x00FF));
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        ;

#elif(Address_Lenth == Address_16bit)
    I2C_SendData(I2C1, (u8)(ReadAddr >> 8));
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        ;

    I2C_SendData(I2C1, (u8)(ReadAddr & 0x00FF));
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        ;

#endif

    I2C_GenerateSTART(I2C1, ENABLE);

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
        ;
    I2C_Send7bitAddress(I2C1, GT911_DIV_R, I2C_Direction_Receiver);

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
        ;
    while(I2C_GetFlagStatus(I2C1, I2C_FLAG_RXNE) == RESET)
        I2C_AcknowledgeConfig(I2C1, DISABLE);

    while(NumToRead)
    {
    *pBuffer++ = I2C_ReceiveData(I2C1);
    NumToRead--;
    }

    I2C_GenerateSTOP(I2C1, ENABLE);

}

void AT24CXX_WriteOneByte(u16 WriteAddr, u8 *pBuffer, u16 NumToWrite)
{
    while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY) != RESET)
        ;
    I2C_GenerateSTART(I2C1, ENABLE);

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
        ;
    I2C_Send7bitAddress(I2C1, GT911_DIV_W, I2C_Direction_Transmitter);

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
        ;

#if(Address_Lenth == Address_8bit)
    I2C_SendData(I2C2, (u8)(WriteAddr & 0x00FF));
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        ;

#elif(Address_Lenth == Address_16bit)
    I2C_SendData(I2C1, (u8)(WriteAddr >> 8));
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        ;

    I2C_SendData(I2C1, (u8)(WriteAddr & 0x00FF));
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        ;

#endif

    while(NumToWrite--)
    {
        if(I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE) != RESET)
        {
            I2C_SendData(I2C1, *pBuffer);
            pBuffer++;
        }
    }

    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        ;
    I2C_GenerateSTOP(I2C1, ENABLE);
}
