/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

#include "debug.h"
#include "string.h"
#include "lcd.h"
#include "ch32v30x.h"
#include "lvgl.h"
#include "lcd.h"
#include "lv_port_disp.h"
#include "lv_examples.h"
#include "usart.h"
#include "spi.h"
#include "tim.h"
#include "pwm.h"
#include "rtc.h"
#include "adc.h"
#include "manager_page.h"
#include "Kalman.h"

extern char screen_sleep;
float adc_vbat;


int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SystemCoreClockUpdate();
	Delay_Init();
	USART_Printf_Init(115200);
	printf("SystemClk:%d\r\n",SystemCoreClock);
    printf("Slave Mode\r\n");
	Delay_Ms(1000);
	GPIO_ALL_Init();

    LCD_Init();
    USARTx_CFG();

	SPI_FullDuplex_Init();

    lv_init();
    lv_port_disp_init();
    Timer3_Int_Init(1000-1,(SystemCoreClock/1000000)-1);
    Timer2_Int_Init(10000-1,(SystemCoreClock/1000000)-1);
    // lv_example_scroll_6();

    app_start();
//    photo_onLoad(lv_layer_top());
//    setting_onLoad(lv_layer_top());
    Backlight_Init();
    RTC_Init();
    ADC_Function_Init();
    Kalman_Init();



//    SysTick_init();

//    lv_obj_t *    btn = lv_label_create(lv_layer_top());
//    lv_obj_set_style_text_color(btn,lv_color_white(),0);
//    lv_obj_set_style_text_font(btn,&lv_font_montserrat_32,0);
//    lv_label_set_text(btn, "ppp");


//    btn2 = lv_btn_create(lv_layer_top());
//    lv_obj_set_size(btn2, 50, 102);

    printf("start\r\n");
//    lv_timer_t * t = lv_timer_create(report_cb, 100, NULL);
	while(1)
	{
	    if(!screen_sleep) {
	    lv_task_handler();
	    }
//        delay_ms(1);
	    adc_vbat = KalmanFilter(&kfp,Get_ADC()/4096.0*3.3);

	}
}

