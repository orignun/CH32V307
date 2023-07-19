/*
 * backligth.c
 *
 *  Created on: 2023年7月3日
 *      Author: zhengshengbing
 */
#include "lvgl.h"
#include "backlight.h"
#include "pwm.h"
#include "debug.h"

static uint32_t backlightValue = 500;
/**
  * @brief  背光亮度渐变，受lv_anim控制
  * @param  obj:无用
  * @param  brightness:亮度值
  * @retval None
  */
static void Backlight_AnimCallback(void *obj, int32_t brightness)
{
    Backlight_SetValue(brightness);
//    TIM_SetCompare3(TIM9, brightness);
}

/**
  * @brief  背光初始化
  * @param  无
  * @retval 无
  */
void Backlight_Init()
{
    /*PWM初始化，1024级，5KHz频率*/
    TIM1_PWMOut_Init(1000-1, (SystemCoreClock/1000000)-1, 500 );
    TIM_SetCompare3(TIM9, 500);
    backlightValue = 500;
}

/**
  * @brief  背光设置，渐变效果
  * @param  target:目标亮度(0~1000 -> 0~100%)
  * @retval 无
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
  * @brief  获取背光亮度
  * @param  无
  * @retval 当前亮度(0~1000 -> 0~100%)
  */
uint32_t Backlight_GetValue()
{
    return backlightValue;
}

/**
  * @brief  设置背光亮度
  * @param  val: 亮度(0~1000 -> 0~100%)
  * @retval 无
  */
void Backlight_SetValue(int32_t val)
{
//    val = constrain(val, 0, 1024);
    backlightValue = val;
    val =   backlightValue;
    TIM_SetCompare3(TIM9, val);
}
