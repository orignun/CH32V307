/*
 * it.c
 *
 *  Created on: 2023年7月3日
 *      Author: zhengshengbing
 */
#include "debug.h"
#include "backlight.h"
#include "pm.h"
#include "rtc.h"
#include "adc.h"
#include "usart.h"
#include "status_bar.h"
#include "set_wifi.h"
#include "photo.h"

int old_Backlight;
char screen_sleep = 0;
extern uint8_t blanking_time;
extern float adc_vbat;
extern _lvgl_set_wifi set_wifi;
extern _lvgl_photo photo;
extern lv_obj_t* status_bar;
int count;

void TIM2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void TIM2_IRQHandler(void)
{
    char read = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1);
    static char flag = 0;

    switch(flag)
    {
        case 0:{if (!read) flag++;break;}
        case 1:{if (read) {
            printf("gpio");

        if(Backlight_GetValue()>0)
        {
            lv_pm_open_options_t newpage = {
                .target = LV_PM_TARGET_SELF};
            lv_pm_open_page(0, &newpage);

            old_Backlight = Backlight_GetValue();
//            Backlight_SetGradual(0,300);
            Backlight_SetValue(0);
        }
        else
        {
            Backlight_SetValue(old_Backlight);
            lv_disp_t * d;
            d          = lv_disp_get_default();
            d->last_activity_time = lv_tick_get();
            screen_sleep = 0;
        }

            flag=0;
        }break;}
    }

    count++;

    if(count%5==0)
        if(lv_obj_is_valid(photo.img))
            lv_obj_invalidate(photo.img);

    if(count%10==0)
    {

        if((lv_disp_get_inactive_time(NULL) > blanking_time*1000)&&(Backlight_GetValue()>0)) {
        old_Backlight = Backlight_GetValue();
        //old_Backlight(0,300);
        Backlight_SetValue(0);
        }


        if(count%50==0)
        {
//            printf("%d-%d\n",calendar.hour, calendar.min);printf("adc:%d",)
//            update_status_bar(calendar.hour, calendar.min,set_wifi.start_ap,set_wifi.start_sta,1,(int)((adc_vbat-1.0)*100),false);
            if(lv_obj_is_valid(status_bar))
                update_status_bar(calendar.hour, calendar.min,set_wifi.start_ap,set_wifi.start_sta,0,48,false);
//            printf("adc:%d\n",(int)(adc_vbat*1000));
//            printf("sta:%d\n",set_wifi.start_sta);


        }

    }


    if(Backlight_GetValue()==0)
    {
        screen_sleep = 1;
    }
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // 清除掉 TIMx 的更新中断标志
}
