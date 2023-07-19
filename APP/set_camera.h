#ifndef SET_CAMERA_H
#define SET_CAMERA_H

#include "lvgl.h"
#include "pm.h"
#include "photo.h"

typedef struct 
{
    lv_obj_t *cont;
    lv_obj_t *page;
    lv_obj_t *btn1;
    lv_obj_t *btn2;
    lv_obj_t *btn3;

    lv_obj_t *enableMotion;
    lv_obj_t *record;
    lv_obj_t *motionVal_slider;
    lv_obj_t *minf_slider;
    lv_obj_t *motionVal_label;
    lv_obj_t *minf_label;

    lv_obj_t *framesize;
    lv_obj_t *special_effect;
    lv_obj_t *brightness_slider;
    lv_obj_t *contrast_slider;
    lv_obj_t *saturation_slider;
    lv_obj_t *brightness_label;
    lv_obj_t *contrast_label;
    lv_obj_t *saturation_label;
    lv_obj_t *hmirror;
    lv_obj_t *vflip;
    lv_obj_t *change_camera_obj;


    int8_t enableMotion_value;
    int8_t record_value;
    int8_t motionVal_value;
    int8_t minf_value;
    int8_t framesize_value;
    int8_t special_effect_value;
    int8_t hmirror_value;
    int8_t vflip_value;
    int8_t brightness_value;
    int8_t contrast_value;
    int8_t saturation_value;
    int8_t change_camera_value;



    uint8_t current_x;
}_lvgl_set_camera;


void set_camera_onLoad(lv_obj_t *page);
void set_camera_unLoad(lv_obj_t *page);

#endif /*SET_CAMERA_H*/
