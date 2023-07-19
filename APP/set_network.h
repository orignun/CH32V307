#ifndef SET_NETWORK_H
#define SET_NETWORK_H

#include "lvgl.h"
#include "pm.h"

typedef struct 
{
    lv_obj_t *cont;
    lv_obj_t *end_panel;
    lv_obj_t *keyboard;
    lv_obj_t *smtp_obj;
    lv_obj_t *ftp_ssid_obj;
    lv_obj_t *ftp_password_obj;
    lv_obj_t *ftp_open_obj;
    lv_obj_t *smtp_open_obj;
    lv_obj_t *network_obj;

    char smtp_value[32];
    char ftp_ssid_value[24];
    char ftp_password_value[24];
    char network_value[24];
    bool ftp_open_value;
    bool smtp_open_value;

    uint16_t current_x;
}_lvgl_set_network;


void set_network_onLoad(lv_obj_t *page);
void set_network_unLoad(lv_obj_t *page);

#endif /*SET_NETWORK_H*/
