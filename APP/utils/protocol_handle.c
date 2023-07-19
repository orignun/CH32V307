/*
 * protocol_handle.c
 *
 *  Created on: 2023Äê7ÔÂ8ÈÕ
 *      Author: zhengshengbing
 */
#include "debug.h"
#include "set_wifi.h"
#include "set_camera.h"
#include "set_network.h"
#include "photo.h"
#include "rtc.h"

extern char usart_receive_data[128];
extern _lvgl_set_wifi set_wifi;
extern _lvgl_set_camera set_camera;
extern _lvgl_set_network set_network;
extern _lvgl_photo photo;
char esp32_variable[64];
char esp32_value[64];

void protocol_handle()
{

    printf("%s\n",usart_receive_data);
    char* token;
    if(usart_receive_data[strlen(usart_receive_data)-1]!='?')
    {
      token = strtok(usart_receive_data, "?");strcpy(esp32_variable,token);
      token = strtok(NULL, "?");strcpy(esp32_value,token);
    }
    else
    {
      token = strtok(usart_receive_data, "?");strcpy(esp32_variable,token);
      strcpy(esp32_value,"");
    }



    if (strstr(esp32_variable,"wifi_scan_start")){
        set_wifi.count = 0;
    }

    else if (strstr(esp32_variable,"wifi_scaning")){

        lv_table_set_cell_value(set_wifi.table, set_wifi.count, 0, esp32_value);
        lv_table_set_col_width(set_wifi.table,set_wifi.count,200);

        set_wifi.count ++;

        lv_obj_set_size(set_wifi.panel2, 320, 80+40*set_wifi.count);
        lv_obj_set_size(set_wifi.table, 200, 40*set_wifi.count);

    }
    else if (strstr(esp32_variable,"wifi_connected")){
        set_wifi.start_sta = 2;
    }

    else if (strstr(esp32_variable,"Motioning")){

        photo.forceRecord_value = atoi(esp32_value);
        if(lv_obj_is_valid(photo.img))
        {
            if(atoi(esp32_value)) lv_obj_add_state(photo.img, LV_STATE_CHECKED);
            else lv_obj_clear_state(photo.img, LV_STATE_CHECKED);
        }
    }

    else if (strstr(esp32_variable,"enableMotion")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_camera.enableMotion))
                lv_obj_add_state(set_camera.enableMotion, LV_STATE_CHECKED);
            set_camera.enableMotion_value = 1;
        }
        else {
            if(lv_obj_is_valid(set_camera.enableMotion))
                lv_obj_clear_state(set_camera.enableMotion, LV_STATE_CHECKED);
            set_camera.enableMotion_value = 0;
        }
    }
    else if (strstr(esp32_variable,"record")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_camera.record))
                lv_obj_add_state(set_camera.record, LV_STATE_CHECKED);
            set_camera.record_value = 1;
        }
        else {
            if(lv_obj_is_valid(set_camera.record))
                lv_obj_clear_state(set_camera.record, LV_STATE_CHECKED);
            set_camera.record_value = 0;
        }
    }
    else if (strstr(esp32_variable,"motionVal")){
        set_camera.motionVal_value = atoi(esp32_value);
        if(lv_obj_is_valid(set_camera.motionVal_slider))
        {
            lv_label_set_text_fmt(set_camera.motionVal_label, "%d",set_camera.motionVal_value);
            lv_slider_set_value(set_camera.motionVal_slider,set_camera.motionVal_value,LV_ANIM_ON);
        }

    }
    else if (strstr(esp32_variable,"minf")){
        set_camera.minf_value = atoi(esp32_value);
        if(lv_obj_is_valid(set_camera.minf_slider))
        {
            lv_label_set_text_fmt(set_camera.minf_label, "%ds",set_camera.minf_value);
            lv_slider_set_value(set_camera.minf_slider,set_camera.minf_value,LV_ANIM_ON);
        }
    }
    else if (strstr(esp32_variable,"change_camera")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_camera.change_camera_obj))
                lv_obj_add_state(set_camera.change_camera_obj, LV_STATE_CHECKED);
            set_camera.change_camera_value = 1;
        }
        else {
            if(lv_obj_is_valid(set_camera.change_camera_obj))
                lv_obj_clear_state(set_camera.change_camera_obj, LV_STATE_CHECKED);
            set_camera.change_camera_value = 0;
        }
    }




    else if (strstr(esp32_variable,"framesize")){
        set_camera.framesize_value = atoi(esp32_value);
        if(lv_obj_is_valid(set_camera.framesize))
        lv_dropdown_set_selected(set_camera.framesize,set_camera.framesize_value);
    }
    else if (strstr(esp32_variable,"special_effect")){
        set_camera.special_effect_value = atoi(esp32_value);
        if(lv_obj_is_valid(set_camera.special_effect))
        lv_dropdown_set_selected(set_camera.special_effect,set_camera.special_effect_value);
    }
    else if (strstr(esp32_variable,"hmirror")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_camera.hmirror))
                lv_obj_add_state(set_camera.hmirror, LV_STATE_CHECKED);
            set_camera.hmirror_value = 1;
        }
        else {
            if(lv_obj_is_valid(set_camera.hmirror))
                lv_obj_clear_state(set_camera.hmirror, LV_STATE_CHECKED);
            set_camera.hmirror_value = 0;
        }
    }
    else if (strstr(esp32_variable,"vflip")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_camera.vflip))
                lv_obj_add_state(set_camera.vflip, LV_STATE_CHECKED);
            set_camera.vflip_value = 1;
        }
        else {
            if(lv_obj_is_valid(set_camera.vflip))
                lv_obj_clear_state(set_camera.vflip, LV_STATE_CHECKED);
            set_camera.vflip_value = 0;
        }
    }
    else if (strstr(esp32_variable,"brightness")){
        set_camera.brightness_value = atoi(esp32_value);
        if(lv_obj_is_valid(set_camera.brightness_slider))
        {
            lv_label_set_text_fmt(set_camera.brightness_label, "%ds",set_camera.brightness_value);
            lv_slider_set_value(set_camera.brightness_slider,set_camera.brightness_value,LV_ANIM_ON);
        }
    }
    else if (strstr(esp32_variable,"contrast")){
        set_camera.contrast_value = atoi(esp32_value);
        if(lv_obj_is_valid(set_camera.contrast_slider))
        {
            lv_label_set_text_fmt(set_camera.contrast_label, "%ds",set_camera.contrast_value);
            lv_slider_set_value(set_camera.contrast_slider,set_camera.contrast_value,LV_ANIM_ON);
        }
    }
    else if (strstr(esp32_variable,"saturation")){
        set_camera.saturation_value = atoi(esp32_value);
        if(lv_obj_is_valid(set_camera.saturation_slider))
        {
            lv_label_set_text_fmt(set_camera.saturation_label, "%ds",set_camera.saturation_value);
            lv_slider_set_value(set_camera.saturation_slider,set_camera.saturation_value,LV_ANIM_ON);
        }
    }

    else if (strstr(esp32_variable,"allowAP")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_wifi.ap_switch))
                lv_obj_add_state(set_wifi.ap_switch, LV_STATE_CHECKED);
            set_wifi.start_ap = 1;
        }
        else {
            if(lv_obj_is_valid(set_wifi.ap_switch))
                lv_obj_clear_state(set_wifi.ap_switch, LV_STATE_CHECKED);
            set_wifi.start_ap = 0;
        }
    }
    else if (strstr(esp32_variable,"allowSTA")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_wifi.sta_switch))
                lv_obj_add_state(set_wifi.sta_switch, LV_STATE_CHECKED);
            set_wifi.start_sta = atoi(esp32_value);
        }
        else {
            if(lv_obj_is_valid(set_wifi.sta_switch))
                lv_obj_clear_state(set_wifi.sta_switch, LV_STATE_CHECKED);
            set_wifi.start_sta = 0;
        }
    }
    else if (strstr(esp32_variable,"AP_SSID")){
        strcpy(set_wifi.ap_ssid,esp32_value);
        if(lv_obj_is_valid(set_wifi.ap_ssid_obj))
            lv_textarea_set_text(set_wifi.ap_ssid_obj, set_wifi.ap_ssid);

    }
    else if (strstr(esp32_variable,"AP_Pass")){
        if(strcmp(esp32_value,"NULL")==0)
            strcpy(set_wifi.ap_password,"");
        else
            strcpy(set_wifi.ap_password,esp32_value);
        if(lv_obj_is_valid(set_wifi.ap_password_obj))
            lv_textarea_set_text(set_wifi.ap_password_obj, set_wifi.ap_password);
    }

    else if (strstr(esp32_variable,"time")){
        u16 syear; u8 smon; u8 sday; u8 hour; u8 min; u8 sec;
        char* tokens;
        tokens = strtok(esp32_value, "/");syear = atoi(tokens);
        tokens = strtok(NULL, "/");smon = atoi(tokens);
        tokens = strtok(NULL, "/");sday = atoi(tokens);
        tokens = strtok(NULL, "/");hour = atoi(tokens);
        tokens = strtok(NULL, "/");min = atoi(tokens);
        tokens = strtok(NULL, "/");sec = atoi(tokens);

        RTC_Set(syear, smon, sday, hour, min, sec);
    }



    else if (strstr(esp32_variable,"network")){
        strcpy(set_network.network_value,esp32_value);
        if(lv_obj_is_valid(set_network.network_obj))
            lv_label_set_text_fmt(set_network.network_obj,"%s",set_network.network_value);
    }
    else if (strstr(esp32_variable,"smtp_open")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_network.smtp_open_obj))
                lv_obj_add_state(set_network.smtp_open_obj, LV_STATE_CHECKED);
            set_network.smtp_open_value = 1;
        }
        else {
            if(lv_obj_is_valid(set_network.smtp_open_obj))
                lv_obj_clear_state(set_network.smtp_open_obj, LV_STATE_CHECKED);
            set_network.smtp_open_value = 0;
        }
    }
    else if (strstr(esp32_variable,"smtp_email")){
        strcpy(set_network.smtp_value,esp32_value);
        if(lv_obj_is_valid(set_network.smtp_obj))
            lv_textarea_set_text(set_network.smtp_obj,set_network.smtp_value);
    }
    else if (strstr(esp32_variable,"ftp_open")){
        if(atoi(esp32_value)){
            if(lv_obj_is_valid(set_network.ftp_open_obj))
                lv_obj_add_state(set_network.ftp_open_obj, LV_STATE_CHECKED);
            set_network.ftp_open_value = 1;
        }
        else {
            if(lv_obj_is_valid(set_network.ftp_open_obj))
                lv_obj_clear_state(set_network.ftp_open_obj, LV_STATE_CHECKED);
            set_network.ftp_open_value = 0;
        }
    }
    else if (strstr(esp32_variable,"ftp_ssid")){
        strcpy(set_network.ftp_ssid_value,esp32_value);
        if(lv_obj_is_valid(set_network.ftp_ssid_obj))
            lv_textarea_set_text(set_network.ftp_ssid_obj,set_network.ftp_ssid_value);
    }
    else if (strstr(esp32_variable,"ftp_password")){
        strcpy(set_network.ftp_password_value,esp32_value);
        if(lv_obj_is_valid(set_network.ftp_password_obj))
            lv_textarea_set_text(set_network.ftp_password_obj,set_network.ftp_password_value);
    }
}
