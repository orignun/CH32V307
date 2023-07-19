#ifndef SET_WIFI_H
#define SET_WIFI_H

#include "lvgl.h"
#include "pm.h"

typedef struct 
{
    lv_obj_t *cont;
    lv_obj_t *panel2;
    lv_obj_t *keyboard;
    lv_obj_t *table;
    lv_obj_t *textarea;
    lv_obj_t *ap_ssid_obj;
    lv_obj_t *ap_password_obj;
    lv_obj_t *ap_switch;
    lv_obj_t *sta_switch;


    uint8_t count;

    char ap_ssid[24];
    char ap_password[24];
    char ssid[24];

    bool start_ap;
    uint8_t start_sta;

    uint8_t current_x;
}_lvgl_set_wifi;


void set_wifi_onLoad(lv_obj_t *page);
void set_wifi_unLoad(lv_obj_t *page);

#endif /*SET_WIFI_H*/
