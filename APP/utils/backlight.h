/*
 * backlight.h
 *
 *  Created on: 2023Äê7ÔÂ3ÈÕ
 *      Author: zhengshengbing
 */

#ifndef APP_UTILS_BACKLIGHT_H_
#define APP_UTILS_BACKLIGHT_H_

void Backlight_Init();
void Backlight_SetGradual(uint32_t target, uint16_t time);
uint32_t Backlight_GetValue();
void Backlight_SetValue(int32_t val);

#endif /* APP_UTILS_BACKLIGHT_H_ */
