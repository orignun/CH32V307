/*
 * backligth.c
 *
 *  Created on: 2023��7��3��
 *      Author: zhengshengbing
 */
#include "lvgl.h"
#include "backlight.h"
#include "pwm.h"
#include "debug.h"

static uint32_t backlightValue = 500;
/**
  * @brief  �������Ƚ��䣬��lv_anim����
  * @param  obj:����
  * @param  brightness:����ֵ
  * @retval None
  */
static void Backlight_AnimCallback(void *obj, int32_t brightness)
{
    Backlight_SetValue(brightness);
//    TIM_SetCompare3(TIM9, brightness);
}

/**
  * @brief  �����ʼ��
  * @param  ��
  * @retval ��
  */
void Backlight_Init()
{
    /*PWM��ʼ����1024����5KHzƵ��*/
    TIM1_PWMOut_Init(1000-1, (SystemCoreClock/1000000)-1, 500 );
    TIM_SetCompare3(TIM9, 500);
    backlightValue = 500;
}

/**
  * @brief  �������ã�����Ч��
  * @param  target:Ŀ������(0~1000 -> 0~100%)
  * @retval ��
  */
void Backlight_SetGradual(uint32_t target, uint16_t time)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) Backlight_AnimCallback);
    lv_anim_set_values(&a, Backlight_GetValue(), target);
    lv_anim_set_time(&a, time);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);

    lv_anim_start(&a);
}

/**
  * @brief  ��ȡ��������
  * @param  ��
  * @retval ��ǰ����(0~1000 -> 0~100%)
  */
uint32_t Backlight_GetValue()
{
    return backlightValue;
}

/**
  * @brief  ���ñ�������
  * @param  val: ����(0~1000 -> 0~100%)
  * @retval ��
  */
void Backlight_SetValue(int32_t val)
{
//    val = constrain(val, 0, 1024);
    backlightValue = val;
    val =   backlightValue;
    TIM_SetCompare3(TIM9, val);
}
