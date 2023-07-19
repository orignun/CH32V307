/*
 * adc.c
 *
 *  Created on: 2023Äê7ÔÂ4ÈÕ
 *      Author: zhengshengbing
 */
#include "debug.h"
#include "adc.h"

s16 Calibrattion_Val = 0;

void ADC_Function_Init(void)

{

    ADC_InitTypeDef ADC_InitStructure={0};

    GPIO_InitTypeDef GPIO_InitStructure={0};



    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE );

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE );

    RCC_ADCCLKConfig(RCC_PCLK2_Div8);



    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;

    GPIO_Init(GPIOC, &GPIO_InitStructure);



    ADC_DeInit(ADC1);

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;

    ADC_InitStructure.ADC_ScanConvMode = DISABLE;

    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;

    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;

    ADC_InitStructure.ADC_NbrOfChannel = 1;

    ADC_Init(ADC1, &ADC_InitStructure);



    ADC_DMACmd(ADC1, ENABLE);

    ADC_Cmd(ADC1, ENABLE);



    ADC_BufferCmd(ADC1, DISABLE);   //disable buffer

    ADC_ResetCalibration(ADC1);

    while(ADC_GetResetCalibrationStatus(ADC1));

    ADC_StartCalibration(ADC1);

    while(ADC_GetCalibrationStatus(ADC1));

    Calibrattion_Val = Get_CalibrationValue(ADC1);



    ADC_BufferCmd(ADC1, ENABLE);   //enable buffer

}

u16 Get_ADC_Val(u8 ch)

{

    u16 val;



    ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );

    ADC_SoftwareStartConvCmd(ADC1, ENABLE);



    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));

    val = ADC_GetConversionValue(ADC1);



    return val;

}



u16 Get_ConversionVal(s16 val)

{

    if((val+Calibrattion_Val)<0) return 0;

    if((Calibrattion_Val+val)>4095||val==4095) return 4095;

    return (val+Calibrattion_Val);

}

u16 Get_ADC()
{
    return Get_ConversionVal(Get_ADC_Val(ADC_Channel_14));
}
