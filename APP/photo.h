#ifndef PHOTO_H
#define PHOTO_H

#include "lvgl.h"
#include "pm.h"
#include "status_bar.h"

typedef struct 
{
    lv_obj_t *my_box;
    lv_obj_t *img;
    lv_obj_t *forceRecord;

    lv_coord_t box_x;
    lv_coord_t box_y;
    lv_coord_t box_w ;
    lv_coord_t box_h;

    int16_t x_count;
    int16_t y_count;

    uint8_t forceRecord_value;

    uint8_t eve;
}_lvgl_photo;

extern char photo_sign;

#define LV_DIR_TOP_LEFT 1
#define LV_DIR_TOP_RIGHT 2
#define LV_DIR_BOTTOM_LEFT 3
#define LV_DIR_BOTTOM_RIGHT 4


void photo_onLoad(lv_obj_t *page);
void photo_unLoad(lv_obj_t *page);

#endif /*PHOTO_H*/
