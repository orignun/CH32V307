#ifndef MENU_H
#define MENU_H

#include "lvgl.h"
#include "pm.h"
#include "status_bar.h"

typedef struct
{
	lv_obj_t * photo_btn;
	lv_obj_t * file_btn;
    lv_obj_t * set_btn;

}_lvgl_menu_cont;

void menu_onLoad(lv_obj_t *page);
void menu_unLoad(lv_obj_t *page);

#endif /*MENU_H*/