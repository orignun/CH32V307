/*
 * anim.h
 *
 *  Created on: 2023Äê7ÔÂ17ÈÕ
 *      Author: zhengshengbing
 */

#ifndef APP_UTILS_ANIM_H_
#define APP_UTILS_ANIM_H_

#include "lvgl.h"

extern lv_style_t style;
extern lv_style_t style_pre;
extern lv_style_t style_line;

void style_init();
void fadeon_Animation(lv_obj_t * TargetObject, int delay);
void topon_Animation(lv_obj_t * TargetObject, int delay);
void leftpon_Animation(lv_obj_t * TargetObject, int delay);
void leftoff_Animation(lv_obj_t * TargetObject, int delay);
void seton_Animation(lv_obj_t * TargetObject, int delay);
void filelefton_Animation(lv_obj_t * TargetObject, int delay);
void filerighton_Animation(lv_obj_t * TargetObject, int delay);
void fadeoff_Animation(lv_obj_t * TargetObject, int delay);
void topoff_Animation(lv_obj_t * TargetObject, int delay);
void camera_Animation(lv_obj_t * TargetObject, int delay);

#endif /* APP_UTILS_ANIM_H_ */
