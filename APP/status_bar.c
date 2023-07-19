#include "status_bar.h"


/*Static Variable*/
lv_obj_t* status_bar;
static lv_obj_t* pad;
static lv_obj_t* label_time;
static lv_obj_t* wifi_sta_obj;
static lv_obj_t* wifi_ap_obj;
static lv_obj_t* charge_obj;
char last_charge_status=0;
char last_wifi_sta_status=0;
char last_wifi_ap_status=0;
char last_hour=0;
char last_min=0;
char last_electricity=0;

/*Static Function*/
static void status_bar_hidden_anim(void* var, int32_t value);

void update_status_bar(uint8_t hour, uint8_t min, uint8_t wifi_ap_status, uint8_t wifi_sta_status, uint8_t charge_status ,uint8_t electricity,uint8_t change)
{
    lv_obj_t *label;
    if((last_min!=min)||change)
    {
        last_hour = hour;last_min = min;
        if(lv_obj_is_valid(label_time))
        lv_label_set_text_fmt(label_time, "%02d:%02d", hour,min);
    }

    if((last_electricity!=electricity)||change)
    {
        last_electricity = electricity;
        if(lv_obj_is_valid(pad))
        {
                static int32_t cnt;
            if (electricity<20)
                lv_obj_set_style_bg_color(pad, lv_color_hex(0xff0000), 0);
            else
                lv_obj_set_style_bg_color(pad, lv_color_hex(0xff00), 0);

            cnt = electricity;

            //修改电量颜色obj宽度
            lv_obj_set_width(pad, electricity/2.1);

            //修改电池百分比
            lv_obj_t *text = lv_obj_get_child(lv_obj_get_parent(pad), -1);
            lv_label_set_text_fmt(text, "%d", electricity);
        }
    }

    if((last_charge_status!=charge_status)||change)
    {
        last_charge_status = charge_status;
        change = true;

        if(charge_status == OFF_CHARGE)
        {
            if(lv_obj_is_valid(charge_obj))
                // lv_obj_set_style_opa(charge_obj,0,0);
                lv_obj_del(charge_obj);

        }
        else if(charge_status == ON_CHARGE)
        {
            if(!lv_obj_is_valid(charge_obj))
            charge_obj = lv_img_create(status_bar);
            lv_obj_set_size(charge_obj,20,20);
            lv_img_set_src(charge_obj,"D:2.bin");
            lv_obj_align(charge_obj, LV_ALIGN_RIGHT_MID, -50, 0);

        }
    }

    if((last_wifi_sta_status!=wifi_sta_status)||change)
    {
        last_wifi_sta_status = wifi_sta_status;
        change = true;

        if(wifi_sta_status == WIFI_CLOSE)
        {
            if(lv_obj_is_valid(wifi_sta_obj))
                // lv_obj_set_style_opa(wifi_sta_obj,0,0);
                lv_obj_del(wifi_sta_obj);


            // lv_obj_set_style_opa(wifi_sta_obj,0,0);
        }
        else if(wifi_sta_status == WIFI_OPEN)
        {
            // printf("i am here");
            if(!lv_obj_is_valid(wifi_sta_obj))
            wifi_sta_obj = lv_img_create(status_bar);
            lv_obj_set_size(wifi_sta_obj,20,20);
            lv_img_set_src(wifi_sta_obj,"D:3.bin");
            if(charge_status)
                lv_obj_align_to(wifi_sta_obj, charge_obj, LV_ALIGN_OUT_LEFT_MID, 0, 0);
            else
                lv_obj_align(wifi_sta_obj, LV_ALIGN_RIGHT_MID, -55, 0);

        }
        else if(wifi_sta_status == WIFI_CONNECT)
        {
            if(!lv_obj_is_valid(wifi_sta_obj))
            wifi_sta_obj = lv_img_create(status_bar);
            lv_obj_set_size(wifi_sta_obj,20,20);
            lv_img_set_src(wifi_sta_obj,"D:4.bin");
            if(charge_status)
                lv_obj_align_to(wifi_sta_obj, charge_obj, LV_ALIGN_OUT_LEFT_MID, 0, 0);
            else
                lv_obj_align(wifi_sta_obj, LV_ALIGN_RIGHT_MID, -55, 0);

        }
    }

    if((last_wifi_ap_status!=wifi_ap_status)||change)
    {
        last_wifi_ap_status = wifi_ap_status;
        change = true;

        if(wifi_ap_status == WIFI_AP_CLOSE)
        {
            if(lv_obj_is_valid(wifi_ap_obj))
                // lv_obj_set_style_opa(wifi_ap_obj,0,0);
                lv_obj_del(wifi_ap_obj);

        }
        else if(wifi_ap_status == WIFI_AP_OPEN)
        {
            if(!lv_obj_is_valid(wifi_ap_obj))
            wifi_ap_obj = lv_img_create(status_bar);
            lv_obj_set_size(wifi_ap_obj,20,20);
            lv_img_set_src(wifi_ap_obj,"D:5.bin");
            if(wifi_sta_status)
                lv_obj_align_to(wifi_ap_obj, wifi_sta_obj, LV_ALIGN_OUT_LEFT_MID, -2, 0);
            else if(charge_status)
                lv_obj_align_to(wifi_ap_obj, charge_obj, LV_ALIGN_OUT_LEFT_MID, -2, 0);
            else
                lv_obj_align(wifi_ap_obj, LV_ALIGN_RIGHT_MID, -55, 0);

        }
    }
}

//void update_status_bar(uint8_t hour, uint8_t min, uint8_t wifi_ap_status, uint8_t wifi_sta_status, uint8_t charge_status , uint8_t electricity, uint8_t change)
//{
//    lv_obj_t *label;
//    if((last_min!=min)||change)
//    {
//        last_hour = hour;last_min = min;
//        lv_label_set_text_fmt(label_time, "%02d:%02d", hour,min);
//    }
//
//    if((last_electricity!=electricity)||change)
//    {
//        last_electricity = electricity;
//            static int32_t cnt;
//        if (electricity<20)
//            lv_obj_set_style_bg_color(pad, lv_color_hex(0xff0000), 0);
//        else
//            lv_obj_set_style_bg_color(pad, lv_color_hex(0xff00), 0);
//
//        cnt = electricity;
//
//        //修改电量颜色obj宽度
//        lv_obj_set_width(pad, electricity/2.1);
//
//        //修改电池百分比
//        lv_obj_t *text = lv_obj_get_child(lv_obj_get_parent(pad), -1);
//        lv_label_set_text_fmt(text, "%d", electricity);
//    }
//
//    if((last_charge_status!=charge_status)||change)
//    {
//        last_charge_status = charge_status;
//
//        if(charge_status == OFF_CHARGE)
//        {
//            if(lv_obj_is_valid(charge_obj))
//                lv_obj_del(charge_obj);
//        }
//        else if(charge_status == ON_CHARGE)
//        {
//            charge_obj = lv_img_create(status_bar);
//            lv_obj_set_size(charge_obj,20,20);
//            lv_img_set_src(charge_obj,"D:2.bin");
//            lv_obj_align(charge_obj, LV_ALIGN_RIGHT_MID, -50, 0);
//        }
//    }
//
//    if((last_wifi_sta_status!=wifi_sta_status)||change)
//    {
//        last_wifi_sta_status = wifi_sta_status;
//
//        if(wifi_sta_status == WIFI_CLOSE)
//        {
//            if(lv_obj_is_valid(wifi_sta_obj))
//                lv_obj_del(wifi_sta_obj);
//        }
//        else if(wifi_sta_status == WIFI_OPEN)
//        {
//            wifi_sta_obj = lv_img_create(status_bar);
//            lv_obj_set_size(wifi_sta_obj,20,20);
//            lv_img_set_src(wifi_sta_obj,"D:4.bin");
//            if(charge_status)
//                lv_obj_align_to(wifi_sta_obj, charge_obj, LV_ALIGN_OUT_LEFT_MID, 0, 0);
//            else
//                lv_obj_align(wifi_sta_obj, LV_ALIGN_RIGHT_MID, -55, 0);
//        }
//        else if(wifi_sta_status == WIFI_CONNECT)
//        {
//            wifi_sta_obj = lv_img_create(status_bar);
//            lv_obj_set_size(wifi_sta_obj,20,20);
//            lv_img_set_src(wifi_sta_obj,"D:3.bin");
//            if(charge_status)
//                lv_obj_align_to(wifi_sta_obj, charge_obj, LV_ALIGN_OUT_LEFT_MID, 0, 0);
//            else
//                lv_obj_align(wifi_sta_obj, LV_ALIGN_RIGHT_MID, -55, 0);
//        }
//    }
//
//    if((last_wifi_ap_status!=wifi_ap_status)||change)
//    {
//        last_wifi_ap_status = wifi_ap_status;
//
//        if(wifi_ap_status == WIFI_AP_CLOSE)
//        {
//            if(lv_obj_is_valid(wifi_ap_obj))
//                lv_obj_del(wifi_ap_obj);
//        }
//        else if(wifi_ap_status == WIFI_AP_OPEN)
//        {
//            wifi_ap_obj = lv_img_create(status_bar);
//            lv_obj_set_size(wifi_ap_obj,20,20);
//            lv_img_set_src(wifi_ap_obj,"D:5.bin");
//            if(wifi_sta_status)
//                lv_obj_align_to(wifi_ap_obj, wifi_sta_obj, LV_ALIGN_OUT_LEFT_MID, -2, 0);
//            else if(charge_status)
//                lv_obj_align_to(wifi_ap_obj, charge_obj, LV_ALIGN_OUT_LEFT_MID, -2, 0);
//            else
//                lv_obj_align(wifi_ap_obj, LV_ALIGN_RIGHT_MID, -55, 0);
//        }
//    }
//}

/**
 * @brief 
 * @param  
*/
void status_bar_init(lv_obj_t *page)
{
    if (lv_obj_is_valid(status_bar))
    {
//        printf("Error,Status Bar Exised!");
//        return;
        lv_obj_del(status_bar);
    }



    status_bar = lv_obj_create(page);
    lv_obj_set_size(status_bar, LV_PCT(100), 28);
    lv_obj_set_scrollbar_mode(status_bar, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_radius(status_bar, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(status_bar,0,LV_STATE_DEFAULT);
    lv_obj_clear_flag(status_bar,LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_opa(status_bar,0,0);

    // lv_obj_t *label = lv_label_create(status_bar);
    // lv_obj_align(label, LV_ALIGN_TOP_RIGHT, 0, -10);
    // lv_label_set_text_fmt(label, "%d%%", 100);

    label_time = lv_label_create(status_bar);
    lv_obj_align(label_time, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text_fmt(label_time, "12:00", 100);



    lv_obj_t *label = lv_obj_create(status_bar);
    lv_obj_set_style_border_width(label, 0, 0);
    lv_obj_set_size(label, 2, 10);
    lv_obj_set_style_bg_color(label,lv_color_hex(0x999999),0);
    lv_obj_align(label, LV_ALIGN_RIGHT_MID, 3, 0);


    lv_obj_t* outline = lv_obj_create(status_bar);

    //设置border和pading
    lv_obj_set_style_border_width(outline, 2, 0);
    lv_obj_set_style_pad_all(outline, 0, 0);
    lv_obj_set_style_border_color(outline,lv_color_hex(0x999999),0);

    //设置圆角
    lv_obj_set_style_radius(outline, 5, 0);

    //关闭滚动条
    lv_obj_clear_flag(outline, LV_OBJ_FLAG_SCROLLABLE);

    //设置宽高
    lv_obj_set_size(outline, 50, 20);

    //居中对齐
    lv_obj_align(outline, LV_ALIGN_RIGHT_MID, 0, 0);

    //电池电量填充obj
    pad = lv_obj_create(outline);


    //设置outline
    lv_obj_set_style_outline_width(pad, 0, 0);
    lv_obj_set_style_outline_pad(pad, 0, 0);
    lv_obj_set_style_border_width(pad, 0, 0);
    //设置背景色
    lv_obj_set_style_bg_color(pad, lv_color_hex(0xff0000), 0);

    //设置宽高
    lv_obj_set_size(pad, 50, 20-4);
    lv_obj_set_style_border_width(pad, 0, 0);

    //设置圆角
    lv_obj_set_style_radius(pad, 3, 0);

    //居中对齐
    lv_obj_align(pad, LV_ALIGN_LEFT_MID, 0, 0);

    //关闭滚动条
    lv_obj_clear_flag(pad, LV_OBJ_FLAG_SCROLLABLE);

    //电池百分比
    label = lv_label_create(outline);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);



    // label = lv_imgbtn_create(status_bar);
    // lv_obj_set_size(label,20,20);
    // lv_img_set_src(label,"D:3.png");
    // lv_obj_align(label, LV_ALIGN_RIGHT_MID, -70, 0);
    // lv_obj_set_style_img_recolor(label, lv_color_hex(0xFF0000), 0);
    // lv_obj_set_style_img_recolor_opa(label, 100, 0);


    update_status_bar(last_hour,last_min,last_wifi_ap_status,last_wifi_sta_status,last_charge_status,last_electricity,true);

    topon_Animation(status_bar,0);
}



void status_bar_uninit()
{
    last_charge_status=-1;
    last_wifi_sta_status=-1;
    last_wifi_ap_status=-1;
    last_hour=-1;
    last_min=-1;
    last_electricity=-1;
}

// /**
//  * @brief
//  * @param status_bar
//  * @param enable
// */
// void status_bar_hidden(bool enable)
// {
//     if (status_bar == NULL)
//     {
//         return;
//     }
//     lv_anim_t anim;
//     lv_anim_init(&anim);
//     lv_anim_set_var(&anim, status_bar);
//     lv_anim_set_time(&anim, 500);
//     lv_anim_set_exec_cb(&anim, status_bar_hidden_anim);
//     lv_anim_set_path_cb(&anim, lv_anim_path_linear);

//     if (enable)
//     {
//         lv_anim_set_values(&anim, 0, -lv_obj_get_height(status_bar));
//     }
//     else
//     {
//         lv_anim_set_values(&anim, -lv_obj_get_height(status_bar), 0);
//     }
//     lv_anim_start(&anim);
// }

// void status_bar_set_name(const char* app_name)
// {
//     lv_label_set_text(app_name_label, app_name);
// }

// void status_bar_set_opa(lv_opa_t value)
// {
//     lv_obj_set_style_bg_opa(status_bar, value, LV_PART_MAIN);
// }

// void status_bar_set_wifi_status(connect_status_t status)
// {
//     if (status == CONNECT)
//     {
//         lv_obj_clear_flag(wifi_status_img, LV_OBJ_FLAG_HIDDEN);
//     }
//     else
//     {
//         lv_obj_add_flag(wifi_status_img, LV_OBJ_FLAG_HIDDEN);
//     }
// }

// void status_bar_set_pc_status(connect_status_t status)
// {
//     if (status == CONNECT)
//     {
//         lv_obj_clear_flag(pc_status_img, LV_OBJ_FLAG_HIDDEN);
//     }
//     else
//     {
//         lv_obj_add_flag(pc_status_img, LV_OBJ_FLAG_HIDDEN);
//     }
// }


// /**
//  * @brief
//  * @param var
//  * @param value
// */
// static void status_bar_hidden_anim(void* var, int32_t value)
// {
//     lv_obj_move_to(var, 0, value);
// }
