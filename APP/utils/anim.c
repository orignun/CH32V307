/*
 * anim.c
 *
 *  Created on: 2023Äê7ÔÂ17ÈÕ
 *      Author: zhengshengbing
 */
#include "lvgl.h"
#include "anim.h"

lv_style_t style;
lv_style_t style_pre;
lv_style_t style_line;

void style_init()
{
    lv_style_init(&style);
    lv_style_set_border_side(&style,LV_BORDER_SIDE_BOTTOM|LV_BORDER_SIDE_LEFT|LV_BORDER_SIDE_RIGHT);
    lv_style_set_border_width(&style,1);
    lv_style_set_bg_opa(&style,0);
    lv_style_set_border_side(&style,LV_BORDER_SIDE_BOTTOM|LV_BORDER_SIDE_LEFT|LV_BORDER_SIDE_RIGHT);
    lv_style_set_border_color(&style,lv_color_make(0x39,0x34,0x3c));
    lv_style_set_border_opa(&style,255);
    lv_style_init(&style_pre);
    lv_style_set_shadow_color(&style_pre,lv_color_hex(0xEE7B7B));
    lv_style_set_shadow_width(&style_pre,10);
    lv_style_set_shadow_spread(&style_pre,1);
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 2);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_PURPLE));
    lv_style_set_line_rounded(&style_line, true);
}

static void anim_y_cb(void * var, int32_t v)
{
    lv_obj_set_y(var, v);
}

static void anim_x_cb(void * var, int32_t v)
{
    lv_obj_set_x(var, v);
}

void anim_opa_cb(void * var, int32_t v)
{
    lv_obj_set_style_opa(var, v, 0);
}

void fadeon_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_y);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 300);
    lv_anim_set_values(&a1, -35, -50);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_out);
    lv_anim_set_delay(&a1, delay + 0);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 200);
    lv_anim_set_values(&a2, 0, 255);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay + 0);
    lv_anim_start(&a2);
}

void topon_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_y);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 300);
    lv_anim_set_values(&a1, -20, 0);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_out);
    lv_anim_set_delay(&a1, delay + 0);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 100);
    lv_anim_set_values(&a2, 0, 255);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay + 0);
    lv_anim_start(&a2);
}

void leftpon_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_x);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 500);
    lv_anim_set_values(&a1, -20, 10);
    lv_anim_set_path_cb(&a1, lv_anim_path_overshoot);
    lv_anim_set_delay(&a1, delay);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 200);
    lv_anim_set_values(&a2, 0, 255);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay);
    lv_anim_start(&a2);
}

void seton_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_y);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 300);
    lv_anim_set_values(&a1, 25, 0);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_out);
    lv_anim_set_delay(&a1, delay);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 200);
    lv_anim_set_values(&a2, 0, 255);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay);
    lv_anim_start(&a2);
}

void filelefton_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_x);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 300);
    lv_anim_set_values(&a1, -35, 0);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_out);
    lv_anim_set_delay(&a1, delay);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 250);
    lv_anim_set_values(&a2, 0, 255);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay);
    lv_anim_start(&a2);
}

void filerighton_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_x);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 300);
    lv_anim_set_values(&a1, 25, 0);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_out);
    lv_anim_set_delay(&a1, delay);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 250);
    lv_anim_set_values(&a2, 0, 255);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay);
    lv_anim_start(&a2);
}

void fadeoff_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_y);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 300);
    lv_anim_set_values(&a1, -50, -35);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_out);
    lv_anim_set_delay(&a1, delay);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 200);
    lv_anim_set_values(&a2, 255, 0);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay);
    lv_anim_start(&a2);
}

void topoff_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_y);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 300);
    lv_anim_set_values(&a1, 0, -20);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_out);
    lv_anim_set_delay(&a1, delay);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 100);
    lv_anim_set_values(&a2, 255, 0);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay);
    lv_anim_start(&a2);
}

void camera_Animation(lv_obj_t * TargetObject, int delay)
{

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 200);
    lv_anim_set_values(&a2, 0, 255);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay);
    lv_anim_start(&a2);
}

void leftoff_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_obj_set_x);
    lv_anim_set_var(&a1, TargetObject);
    lv_anim_set_time(&a1, 500);
    lv_anim_set_values(&a1, 10, -20);
    lv_anim_set_path_cb(&a1, lv_anim_path_overshoot);
    lv_anim_set_delay(&a1, delay);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t) anim_opa_cb);
    lv_anim_set_var(&a2, TargetObject);
    lv_anim_set_time(&a2, 200);
    lv_anim_set_values(&a2, 255, 0);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_out);
    lv_anim_set_delay(&a2, delay);
    lv_anim_start(&a2);
}
