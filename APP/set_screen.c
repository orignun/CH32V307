#include "set_screen.h"
#include "backlight.h"

_lvgl_set_screen set_screen;
uint8_t blanking_time = 15;

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[8];
    lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_slider_get_value(slider));
    lv_label_set_text(set_screen.label, buf);
    lv_obj_align_to(set_screen.label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

    Backlight_SetGradual((int)lv_slider_get_value(slider)*10, 500);
}

static void dropdown_event_cb(lv_event_t * e)
{
    lv_obj_t * dropdown = lv_event_get_target(e);
    char buf[128];
    lv_dropdown_get_selected_str(dropdown,buf,128);
    blanking_time = atoi(buf);
}

static void event_handler_back(lv_event_t *e)
{
    lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};
    lv_pm_open_page(3, &newpage);
}

void set_screen_onLoad(lv_obj_t *page)
{
    lv_obj_clear_flag(page,LV_OBJ_FLAG_SCROLLABLE);

    set_screen.cont = lv_obj_create(page);
    lv_obj_set_size(set_screen.cont, lv_pct(100), 200);
    lv_obj_align(set_screen.cont, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_flex_flow(set_screen.cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_all(set_screen.cont,0,0);
    lv_obj_set_style_pad_row(set_screen.cont,0,0);
    lv_obj_set_style_pad_column(set_screen.cont,0,0);
    lv_obj_set_style_radius(set_screen.cont,0,0);
    lv_obj_set_style_outline_width(set_screen.cont,0,0);
    lv_obj_set_scroll_dir(set_screen.cont,LV_DIR_VER);


    lv_obj_set_style_pad_right(set_screen.cont,-3,LV_PART_SCROLLBAR);

    lv_obj_t *panel1 = lv_obj_create(set_screen.cont);
    lv_obj_set_size(panel1, 320, 80);  
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);


    lv_obj_t *obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"熄屏时间");

    
    obj = lv_dropdown_create(panel1);
    lv_dropdown_set_options(obj, "15s\n"
                                "30s\n"
                                "45s\n"
                                "60s");
    lv_obj_align(obj,LV_ALIGN_RIGHT_MID,-20,0);
    lv_obj_add_event_cb(obj, dropdown_event_cb, LV_EVENT_VALUE_CHANGED, NULL);


    panel1 = lv_obj_create(set_screen.cont);
    lv_obj_set_size(panel1, 320, 120);  
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);


    obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_TOP_LEFT,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"亮度");

    lv_obj_t * slider = lv_slider_create(panel1);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    set_screen.label = lv_label_create(panel1);
    lv_label_set_text_fmt(set_screen.label, "%d%%",Backlight_GetValue()/10);
    lv_obj_align_to(set_screen.label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_slider_set_range(slider, 1, 100);
    lv_slider_set_value(slider, Backlight_GetValue()/10, LV_ANIM_ON);
//    lv_obj_add_event_cb(slider, event_cb, filter, NULL);

    status_bar_init(page);

    obj = lv_imgbtn_create(page);
    lv_obj_set_size(obj,20,20);
    lv_img_set_src(obj,"D:6.bin");
    lv_obj_align(obj, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_event_cb(obj,event_handler_back,LV_EVENT_CLICKED,NULL);

    seton_Animation(set_screen.cont,100);
    leftpon_Animation(obj,0);
}
void set_screen_unLoad(lv_obj_t *page)
{
     
}
