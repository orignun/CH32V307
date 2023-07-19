#ifndef SET_FILE_H
#define SET_FILE_H

#include "lvgl.h"
#include "pm.h"

typedef struct 
{
    lv_obj_t *cont;
    lv_obj_t *panel1;
    lv_obj_t *panel2;
    lv_obj_t *label;

    uint8_t current_x;
}_lvgl_set_file;


void set_file_onLoad(lv_obj_t *page);
void set_file_unLoad(lv_obj_t *page);

#endif /*SET_FILE_H*/