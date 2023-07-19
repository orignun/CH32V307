#include "set_camera.h"

_lvgl_set_camera set_camera;

static void enableMotion_event(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
        send("enableMotion?1");
        set_camera.enableMotion_value = 1;
    }
    else {
        send("enableMotion?0");
        set_camera.enableMotion_value = 0;
    }
}

static void record_event(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
        send("record?1");
        set_camera.record_value = 1;
    }
    else {
        send("record?0");
        set_camera.record_value = 0;
    }
}

static void motionVal_event(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[16];
    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_slider_get_value(slider));
    lv_label_set_text(set_camera.motionVal_label, buf);
    lv_obj_align_to(set_camera.motionVal_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_snprintf(buf, sizeof(buf), "motionVal?%d", (int)lv_slider_get_value(slider));
    send(buf);
    set_camera.motionVal_value = (int)lv_slider_get_value(slider);
}

static void minf_event(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[16];
    lv_snprintf(buf, sizeof(buf), "%ds", (int)lv_slider_get_value(slider));
    lv_label_set_text(set_camera.minf_label, buf);
    lv_obj_align_to(set_camera.minf_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_snprintf(buf, sizeof(buf), "minf?%d", (int)lv_slider_get_value(slider));
    send(buf);
    set_camera.minf_value = (int)lv_slider_get_value(slider);
}

static void change_camera_event(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
        send("change_camera?1");
        set_camera.change_camera_value = 1;
    }
    else {
        send("change_camera?0");
        set_camera.change_camera_value = 0;
    }
}

void motion_detect(lv_obj_t *page)
{
    if(lv_obj_is_valid(set_camera.cont))
        lv_obj_del(set_camera.cont);

    set_camera.cont = lv_obj_create(page);
    lv_obj_set_size(set_camera.cont, 280, lv_pct(100));
    lv_obj_align(set_camera.cont, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_flex_flow(set_camera.cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_all(set_camera.cont,0,0);
    lv_obj_set_style_pad_row(set_camera.cont,0,0);
    lv_obj_set_style_pad_column(set_camera.cont,0,0);
    lv_obj_set_style_radius(set_camera.cont,0,0);
    lv_obj_set_style_outline_width(set_camera.cont,0,0);
    lv_obj_set_scroll_dir(set_camera.cont,LV_DIR_VER);
    lv_obj_set_style_pad_right(set_camera.cont,-3,LV_PART_SCROLLBAR);
    lv_obj_add_flag(set_camera.cont,LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t *panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    lv_obj_t * obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"运动检测");

    set_camera.enableMotion = lv_switch_create(panel);
    lv_obj_align(set_camera.enableMotion,LV_ALIGN_RIGHT_MID,-10,0);
    if(set_camera.enableMotion_value)lv_obj_add_state(set_camera.enableMotion,LV_STATE_CHECKED);
    else lv_obj_clear_state(set_camera.enableMotion,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_camera.enableMotion, enableMotion_event,LV_EVENT_VALUE_CHANGED,NULL);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 120);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_TOP_LEFT,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"灵敏度");

    set_camera.motionVal_slider = lv_slider_create(panel);
    lv_obj_center(set_camera.motionVal_slider);
    lv_obj_set_width(set_camera.motionVal_slider,200);
    lv_slider_set_range(set_camera.motionVal_slider, 1, 10);
    lv_obj_add_event_cb(set_camera.motionVal_slider, motionVal_event, LV_EVENT_VALUE_CHANGED, NULL);
    set_camera.motionVal_label = lv_label_create(panel);

    lv_label_set_text_fmt(set_camera.motionVal_label, "%d",set_camera.motionVal_value);
    lv_obj_align_to(set_camera.motionVal_label, set_camera.motionVal_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_slider_set_value(set_camera.motionVal_slider,set_camera.motionVal_value,LV_ANIM_ON);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 120);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_TOP_LEFT,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"最小时间");

    set_camera.minf_slider = lv_slider_create(panel);
    lv_obj_center(set_camera.minf_slider);
    lv_obj_set_width(set_camera.minf_slider,200);
    lv_slider_set_range(set_camera.minf_slider, 0, 20);
    lv_obj_add_event_cb(set_camera.minf_slider, minf_event, LV_EVENT_VALUE_CHANGED, NULL);
    set_camera.minf_label = lv_label_create(panel);
    lv_label_set_text_fmt(set_camera.minf_label, "%ds",set_camera.minf_value);
    lv_obj_align_to(set_camera.minf_label, set_camera.minf_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_slider_set_value(set_camera.minf_slider,set_camera.minf_value,LV_ANIM_ON);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"录像保存");

    set_camera.record = lv_switch_create(panel);
    lv_obj_align(set_camera.record,LV_ALIGN_RIGHT_MID,-10,0);
    if(set_camera.record_value)lv_obj_add_state(set_camera.record,LV_STATE_CHECKED);
    else lv_obj_clear_state(set_camera.record,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_camera.record, record_event,LV_EVENT_VALUE_CHANGED,NULL);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"夜晚切换");

    set_camera.change_camera_obj = lv_switch_create(panel);
    lv_obj_align(set_camera.change_camera_obj,LV_ALIGN_RIGHT_MID,-10,0);
    if(set_camera.change_camera_value)lv_obj_add_state(set_camera.change_camera_obj,LV_STATE_CHECKED);
    else lv_obj_clear_state(set_camera.change_camera_obj,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_camera.change_camera_obj, change_camera_event,LV_EVENT_VALUE_CHANGED,NULL);

    camera_Animation(set_camera.cont, 0);
}







static void framesize_event(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    char buf[16];
    lv_snprintf(buf, sizeof(buf), "framesize?%d", (int)lv_dropdown_get_option_cnt(obj));
    send(buf);
    set_camera.framesize_value = (int)lv_dropdown_get_option_cnt(obj);
}

static void special_effect_event(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    char buf[16];
    lv_snprintf(buf, sizeof(buf), "special_effect?%d", (int)lv_dropdown_get_option_cnt(obj));
    send(buf);
    set_camera.special_effect_value = (int)lv_dropdown_get_option_cnt(obj);
}

static void hmirror_event(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
        send("hmirror?1");
        set_camera.hmirror_value = 1;
    }
    else {
        send("hmirror?0");
        set_camera.hmirror_value = 0;
    }
}

static void vflip_event(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
        send("vflip?1");
        set_camera.vflip_value = 1;
    }
    else {
        send("vflip?0");
        set_camera.vflip_value = 0;
    }
}

static void brightness_event(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[16];
    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_slider_get_value(slider));
    lv_label_set_text(set_camera.brightness_label, buf);
    lv_obj_align_to(set_camera.brightness_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_snprintf(buf, sizeof(buf), "brightness?%d", (int)lv_slider_get_value(slider));
    send(buf);
    set_camera.brightness_value = (int)lv_slider_get_value(slider);
}

static void contrast_event(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[16];
    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_slider_get_value(slider));
    lv_label_set_text(set_camera.contrast_label, buf);
    lv_obj_align_to(set_camera.contrast_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_snprintf(buf, sizeof(buf), "contrast?%d", (int)lv_slider_get_value(slider));
    send(buf);
    set_camera.contrast_value = (int)lv_slider_get_value(slider);
}

static void saturation_event(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[16];
    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_slider_get_value(slider));
    lv_label_set_text(set_camera.saturation_label, buf);
    lv_obj_align_to(set_camera.saturation_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_snprintf(buf, sizeof(buf), "saturation?%d", (int)lv_slider_get_value(slider));
    send(buf);
    set_camera.saturation_value = (int)lv_slider_get_value(slider);
}

void camera_contrl(lv_obj_t *page)
{

    if(lv_obj_is_valid(set_camera.cont))
        lv_obj_del(set_camera.cont);

    set_camera.cont = lv_obj_create(page);
    lv_obj_set_size(set_camera.cont, 280, lv_pct(100));
    lv_obj_align(set_camera.cont, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_flex_flow(set_camera.cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_all(set_camera.cont,0,0);
    lv_obj_set_style_pad_row(set_camera.cont,0,0);
    lv_obj_set_style_pad_column(set_camera.cont,0,0);
    lv_obj_set_style_radius(set_camera.cont,0,0);
    lv_obj_set_style_outline_width(set_camera.cont,0,0);
    lv_obj_set_scroll_dir(set_camera.cont,LV_DIR_VER);
    lv_obj_set_style_pad_right(set_camera.cont,-3,LV_PART_SCROLLBAR);

    lv_obj_t *panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    lv_obj_t * obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"分辨率");

    set_camera.framesize = lv_dropdown_create(panel);
    lv_dropdown_set_options(set_camera.framesize, "96x96\n"
                                "160x120\n"
                                "176x144\n"
                                "240x176\n"
                                "240x240\n"
                                "320x240\n"
                                "400x296\n"
                                "480x320\n"
                                "680x480\n"
                                "800x600");
    lv_obj_align(set_camera.framesize,LV_ALIGN_RIGHT_MID,-10,0);
    lv_dropdown_set_selected(set_camera.framesize,set_camera.framesize_value);
    lv_obj_add_event_cb(set_camera.framesize, framesize_event,LV_EVENT_VALUE_CHANGED,NULL);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"特殊效果");

    set_camera.special_effect = lv_dropdown_create(panel);
    // lv_obj_set_style_bg_color(obj,lv_color_hex(0x000000),0);
    lv_obj_set_style_text_font(set_camera.special_effect,&ui_font_Font4,0);
    lv_obj_set_style_text_font(lv_dropdown_get_list(set_camera.special_effect),&ui_font_Font4,0);
    lv_obj_set_style_text_font(set_camera.special_effect,&lv_font_montserrat_14,LV_PART_INDICATOR);
    lv_dropdown_set_options(set_camera.special_effect, "无\n"
                                "反转\n"
                                "灰度\n"
                                "红色\n"
                                "绿色\n"
                                "蓝色");
    lv_obj_align(set_camera.special_effect,LV_ALIGN_RIGHT_MID,-10,0);
        lv_dropdown_set_selected(set_camera.special_effect,set_camera.special_effect_value);
    lv_obj_add_event_cb(set_camera.special_effect, special_effect_event,LV_EVENT_VALUE_CHANGED,NULL);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"水平翻转");

    set_camera.hmirror = lv_switch_create(panel);
    lv_obj_align(set_camera.hmirror,LV_ALIGN_RIGHT_MID,-10,0);
    if(set_camera.hmirror_value)lv_obj_add_state(set_camera.hmirror,LV_STATE_CHECKED);
    else lv_obj_clear_state(set_camera.hmirror,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_camera.hmirror, hmirror_event,LV_EVENT_VALUE_CHANGED,NULL);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"镜像翻转");

    set_camera.vflip = lv_switch_create(panel);
    lv_obj_align(set_camera.vflip,LV_ALIGN_RIGHT_MID,-10,0);
    if(set_camera.vflip_value)lv_obj_add_state(set_camera.vflip,LV_STATE_CHECKED);
    else lv_obj_clear_state(set_camera.vflip,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_camera.vflip, vflip_event,LV_EVENT_VALUE_CHANGED,NULL);



    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 120);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_TOP_LEFT,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"亮度");

    set_camera.brightness_slider = lv_slider_create(panel);
    lv_obj_center(set_camera.brightness_slider);
    lv_obj_set_width(set_camera.brightness_slider,200);
    lv_slider_set_range(set_camera.brightness_slider, -2, 2);
    lv_obj_add_event_cb(set_camera.brightness_slider, brightness_event, LV_EVENT_VALUE_CHANGED, NULL);
    set_camera.brightness_label = lv_label_create(panel);
    lv_label_set_text_fmt(set_camera.brightness_label, "%d", set_camera.brightness_value);
    lv_obj_align_to(set_camera.brightness_label, set_camera.brightness_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_slider_set_value(set_camera.brightness_slider,set_camera.brightness_value,LV_ANIM_ON);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 120);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_TOP_LEFT,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"对比度");

    set_camera.contrast_slider = lv_slider_create(panel);
    lv_obj_center(set_camera.contrast_slider);
    lv_obj_set_width(set_camera.contrast_slider,200);
    lv_slider_set_range(set_camera.contrast_slider, -2, 2);
    lv_obj_add_event_cb(set_camera.contrast_slider, contrast_event, LV_EVENT_VALUE_CHANGED, NULL);
    set_camera.contrast_label = lv_label_create(panel);
    lv_label_set_text_fmt(set_camera.contrast_label, "%d", set_camera.contrast_value);
    lv_obj_align_to(set_camera.contrast_label, set_camera.contrast_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_slider_set_value(set_camera.contrast_slider,set_camera.contrast_value,LV_ANIM_ON);

    panel = lv_obj_create(set_camera.cont);
    lv_obj_set_size(panel, lv_pct(100), 120);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_TOP_LEFT,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"饱和度");

    set_camera.saturation_slider = lv_slider_create(panel);
    lv_obj_center(set_camera.saturation_slider);
    lv_obj_set_width(set_camera.saturation_slider,200);
    lv_slider_set_range(set_camera.saturation_slider, -2, 2);
    lv_obj_add_event_cb(set_camera.saturation_slider, saturation_event, LV_EVENT_VALUE_CHANGED, NULL);
    set_camera.saturation_label = lv_label_create(panel);
    lv_label_set_text_fmt(set_camera.saturation_label, "%d", set_camera.saturation_value);
    lv_obj_align_to(set_camera.saturation_label, set_camera.saturation_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_slider_set_value(set_camera.saturation_slider,set_camera.saturation_value,LV_ANIM_ON);
}

static void event_handler_switch_btn2(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_add_state(set_camera.btn2,LV_STATE_CHECKED);
    if(lv_obj_has_state(obj,LV_STATE_CHECKED))
    {
        lv_obj_clear_state(set_camera.btn3,LV_STATE_CHECKED);
        motion_detect(set_camera.page);
    }
}

static void event_handler_switch_btn3(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_add_state(set_camera.btn3,LV_STATE_CHECKED);
    if(lv_obj_has_state(obj,LV_STATE_CHECKED))
    {
        lv_obj_clear_state(set_camera.btn2,LV_STATE_CHECKED);
        camera_contrl(set_camera.page);
    }
}

static void event_handler_quit(lv_event_t *e)
{
    if(photo_sign == 1)
    {    
        lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};
        lv_pm_open_page(1, &newpage);
    }
    else
    {    
        lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};
        lv_pm_open_page(3, &newpage);
    }
}

void set_camera_onLoad(lv_obj_t *page)
{

    // lv_obj_t * obj = lv_obj_create(page);
    // lv_obj_set_size(obj, lv_pct(100), lv_pct(100));
    // lv_obj_align(obj, LV_ALIGN_BOTTOM_MID, 0, 0);
    // lv_obj_set_style_pad_all(obj,0,0);
    // lv_obj_set_style_pad_row(obj,0,0);
    // lv_obj_set_style_pad_column(obj,0,0);
    // lv_obj_set_style_radius(obj,0,0);
    // lv_obj_set_style_outline_width(obj,0,0);
    // lv_obj_set_scroll_dir(obj,LV_DIR_VER);
    // lv_obj_set_style_pad_right(obj,-3,LV_PART_SCROLLBAR);

    send("getcameraconfig?1");

    set_camera.btn1 = lv_btn_create(page);
    lv_obj_set_size(set_camera.btn1, 40, lv_pct(33));
    lv_obj_align(set_camera.btn1, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_radius(set_camera.btn1,0,0);
    // lv_obj_add_flag(set_camera.btn1,LV_OBJ_FLAG_CHECKABLE);
    // lv_obj_add_state(set_camera.btn1,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_camera.btn1,event_handler_quit,LV_EVENT_CLICKED,NULL);

    set_camera.btn2 = lv_btn_create(page);
    lv_obj_set_size(set_camera.btn2, 40, lv_pct(33));
    lv_obj_align_to(set_camera.btn2, set_camera.btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_set_style_radius(set_camera.btn2,0,0);
    lv_obj_add_flag(set_camera.btn2,LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_state(set_camera.btn2,LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_camera.btn2,event_handler_switch_btn2,LV_EVENT_VALUE_CHANGED,NULL);

    set_camera.btn3 = lv_btn_create(page);
    lv_obj_set_size(set_camera.btn3, 40, lv_pct(34));
    lv_obj_align_to(set_camera.btn3, set_camera.btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_set_style_radius(set_camera.btn3,0,0);
    lv_obj_add_flag(set_camera.btn3,LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(set_camera.btn3,event_handler_switch_btn3,LV_EVENT_VALUE_CHANGED,NULL);

    set_camera.page = page;


    motion_detect(page);

}
void set_camera_unLoad(lv_obj_t *page)
{
     
}
