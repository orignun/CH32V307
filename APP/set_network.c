#include "set_network.h"

_lvgl_set_network set_network;

static void event_handler_back(lv_event_t *e)
{
    lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};
    lv_pm_open_page(3, &newpage);
}

static void text_input_event_cb(lv_event_t * e)
{
  lv_obj_t * obj = lv_event_get_target(e);
  if (e->code == LV_EVENT_FOCUSED)
  {
    if(lv_obj_is_valid(set_network.keyboard))
      lv_obj_del(set_network.keyboard);
    set_network.keyboard = lv_keyboard_create(lv_layer_top());
    lv_keyboard_set_textarea(set_network.keyboard,obj);
    lv_obj_align(set_network.keyboard, LV_ALIGN_BOTTOM_MID, 0, 0);
    set_network.current_x = lv_obj_get_scroll_y(set_network.cont);
    printf("%d\n",set_network.current_x);

    if (obj == set_network.smtp_obj)
        lv_obj_scroll_to_y(set_network.cont,160,LV_ANIM_ON);
    else if (obj == set_network.ftp_ssid_obj)
        {lv_obj_set_size(set_network.end_panel, 320, 200);lv_obj_scroll_to_y(set_network.cont,320,LV_ANIM_ON);}
    else
        {lv_obj_set_size(set_network.end_panel, 320, 200);lv_obj_scroll_to_y(set_network.cont,400,LV_ANIM_ON);}
  }
  else if (e->code == LV_EVENT_DEFOCUSED)
  {
    char buf[48];
       if(obj == set_network.smtp_obj)
       {
           sprintf(buf,"smtp_email?%s" ,lv_textarea_get_text(obj));
       }
       else if (obj == set_network.ftp_ssid_obj)
       {
          sprintf(buf,"ftp_ssid?%s" ,lv_textarea_get_text(obj));
       }
       else
       {
           sprintf(buf,"ftp_password?%s" ,lv_textarea_get_text(obj));
       }
       send(buf);


    lv_obj_del(set_network.keyboard);
    lv_obj_set_size(set_network.end_panel, 320, 0);
    lv_obj_scroll_to_y(set_network.cont,set_network.current_x,LV_ANIM_ON);
  }
}

static void ftp_open_event(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
        send("ftp_open?1");
        set_network.ftp_open_value = 1;
    }
    else {
        send("ftp_open?0");
        set_network.ftp_open_value = 0;
    }
}

static void smtp_open_event(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
        send("smtp_open?1");
        set_network.smtp_open_value = 1;
    }
    else {
        send("smtp_open?0");
        set_network.smtp_open_value = 0;
    }
}




void set_network_onLoad(lv_obj_t *page)
{
    send("getnetworkconfig?1");

    lv_obj_clear_flag(page,LV_OBJ_FLAG_SCROLLABLE);

    set_network.cont = lv_obj_create(page);
    lv_obj_set_size(set_network.cont, lv_pct(100), 200);
    lv_obj_align(set_network.cont, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_flex_flow(set_network.cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_all(set_network.cont,0,0);
    lv_obj_set_style_pad_row(set_network.cont,0,0);
    lv_obj_set_style_pad_column(set_network.cont,0,0);
    lv_obj_set_style_radius(set_network.cont,0,0);
    lv_obj_set_style_outline_width(set_network.cont,0,0);
    lv_obj_set_scroll_dir(set_network.cont,LV_DIR_VER);
    lv_obj_set_style_pad_right(set_network.cont,-3,LV_PART_SCROLLBAR);

    lv_obj_t *panel1 = lv_obj_create(set_network.cont);
    lv_obj_set_size(panel1, 320, 80);
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0);
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);


    lv_obj_t *obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"地址");


    set_network.network_obj = lv_label_create(panel1);
    lv_label_set_text_fmt(set_network.network_obj,"%s",set_network.network_value);
    lv_obj_align(set_network.network_obj,LV_ALIGN_RIGHT_MID,-20,0);

    panel1 = lv_obj_create(set_network.cont);
    lv_obj_set_size(panel1, 320, 80);
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0);
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);


    obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"SMTP");


    set_network.smtp_open_obj = lv_switch_create(panel1);
    lv_obj_align(set_network.smtp_open_obj,LV_ALIGN_RIGHT_MID,-20,0);
    if(set_network.smtp_open_value)lv_obj_add_state(set_network.smtp_open_obj,LV_STATE_CHECKED);
    else lv_obj_clear_state(set_network.smtp_open_obj,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_network.smtp_open_obj, smtp_open_event,LV_EVENT_VALUE_CHANGED,NULL);

    panel1 = lv_obj_create(set_network.cont);
    lv_obj_set_size(panel1, 320, 80);
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0);
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);


    obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"邮箱地址");


    set_network.smtp_obj = lv_textarea_create(panel1);
    lv_obj_set_size(set_network.smtp_obj,200,40);
    lv_obj_align(set_network.smtp_obj,LV_ALIGN_RIGHT_MID,-10,0);
    lv_textarea_set_text(set_network.smtp_obj,set_network.smtp_value);
    lv_obj_add_event_cb(set_network.smtp_obj, text_input_event_cb,LV_EVENT_ALL,NULL);

    panel1 = lv_obj_create(set_network.cont);
    lv_obj_set_size(panel1, 320, 80);  
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);


    obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"FTP");

    
    set_network.ftp_open_obj = lv_switch_create(panel1);
    lv_obj_align(set_network.ftp_open_obj,LV_ALIGN_RIGHT_MID,-20,0);
    if(set_network.ftp_open_value)lv_obj_add_state(set_network.ftp_open_obj,LV_STATE_CHECKED);
    else lv_obj_clear_state(set_network.ftp_open_obj,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_network.ftp_open_obj, ftp_open_event,LV_EVENT_VALUE_CHANGED,NULL);

    panel1 = lv_obj_create(set_network.cont);
    lv_obj_set_size(panel1, 320, 80);
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0);
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);


    obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"FTP账号");


    set_network.ftp_ssid_obj = lv_textarea_create(panel1);
    lv_obj_set_size(set_network.ftp_ssid_obj,200,40);
    lv_obj_align(set_network.ftp_ssid_obj,LV_ALIGN_RIGHT_MID,-10,0);
    lv_textarea_set_text(set_network.ftp_ssid_obj,set_network.ftp_ssid_value);
    lv_obj_add_event_cb(set_network.ftp_ssid_obj, text_input_event_cb,LV_EVENT_ALL,NULL);

    panel1 = lv_obj_create(set_network.cont);
    lv_obj_set_size(panel1, 320, 80);
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0);
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);


    obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"FTP密码");


    set_network.ftp_password_obj = lv_textarea_create(panel1);
    lv_obj_set_size(set_network.ftp_password_obj,200,40);
    lv_obj_align(set_network.ftp_password_obj,LV_ALIGN_RIGHT_MID,-10,0);
    lv_textarea_set_text(set_network.ftp_password_obj,set_network.ftp_password_value);
    lv_obj_add_event_cb(set_network.ftp_password_obj, text_input_event_cb,LV_EVENT_ALL,NULL);

    set_network.end_panel = lv_obj_create(set_network.cont);
    lv_obj_set_size(set_network.end_panel, 320, 0);
    lv_obj_set_style_outline_width(set_network.end_panel,0,0);
    lv_obj_set_style_border_side(set_network.end_panel,LV_BORDER_SIDE_BOTTOM,0);
    lv_obj_set_style_border_width(set_network.end_panel,1,0);
    lv_obj_set_style_border_color(set_network.end_panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(set_network.end_panel,0,0);


    status_bar_init(page);

    obj = lv_imgbtn_create(page);
    lv_obj_set_size(obj,20,20);
    lv_img_set_src(obj,"D:6.bin");
    lv_obj_align(obj, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_event_cb(obj,event_handler_back,LV_EVENT_CLICKED,NULL);

    seton_Animation(set_network.cont,100);
    leftpon_Animation(obj,0);
}

void set_network_unLoad(lv_obj_t *page)
{
     
}
