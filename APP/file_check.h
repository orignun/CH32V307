#ifndef FILE_CHECK_H
#define FILE_CHECK_H

#include "lvgl.h"
#include "pm.h"
#include "status_bar.h"

typedef struct
{
	lv_obj_t * lv_list_left;
	lv_obj_t * lv_list_right;
    lv_obj_t * currentButton;

    char path_base[128];

}_lvgl_file_check;

extern _lvgl_file_check file_check;

void file_onLoad(lv_obj_t *page);
void file_unLoad(lv_obj_t *page);

#endif /*FILE_CHECK_H*/