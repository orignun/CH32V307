#include "setting.h"

static lv_obj_t * cont_col;
static lv_obj_t *btn;

static void open_page(lv_timer_t * timer)
{
    lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};

    lv_pm_open_page(timer->user_data, &newpage);
    lv_timer_del(timer);
}
static lv_timer_t *timer;


static void event_handler_back(lv_event_t *e)
{
    leftoff_Animation(cont_col,0);
    leftoff_Animation(btn,0);
    timer = lv_timer_create(open_page,300,0);
}

static void set_wifi_event_handler(lv_event_t *e)
{
    leftoff_Animation(cont_col,0);
    leftoff_Animation(btn,0);
    timer = lv_timer_create(open_page,300,4);
}

static void set_screen_event_handler(lv_event_t *e)
{
    leftoff_Animation(cont_col,0);
    leftoff_Animation(btn,0);
    timer = lv_timer_create(open_page,300,5);
}

static void set_file_event_handler(lv_event_t *e)
{
    leftoff_Animation(cont_col,0);
    leftoff_Animation(btn,0);
    timer = lv_timer_create(open_page,300,6);
}

static void set_network_event_handler(lv_event_t *e)
{
    leftoff_Animation(cont_col,0);
    leftoff_Animation(btn,0);
    timer = lv_timer_create(open_page,300,7);
}

static void set_camera_event_handler(lv_event_t *e)
{
    leftoff_Animation(cont_col,0);
    leftoff_Animation(btn,0);
    timer = lv_timer_create(open_page,300,8);
    photo_sign = 0;
}

void setting_onLoad(lv_obj_t *page)
{
    cont_col = lv_obj_create(page);
    lv_obj_set_size(cont_col, 240, 200);
    lv_obj_align(cont_col, LV_ALIGN_BOTTOM_LEFT, 0, -5);
    lv_obj_set_flex_flow(cont_col, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_bg_opa(cont_col,0,0);
    lv_obj_set_style_border_width(cont_col,0,0);
    lv_obj_set_style_pad_row(cont_col, 10, 0);

    // lv_obj_set_style_border_width(cont_col,1,LV_PART_SCROLLBAR);
    lv_obj_set_style_pad_right(cont_col,-3,LV_PART_SCROLLBAR);

    btn = lv_imgbtn_create(page);
    lv_obj_set_size(btn, 20, 20);
    lv_obj_align(btn, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_img_set_src(btn,"D:6.bin");
    lv_obj_add_event_cb(btn,event_handler_back,LV_EVENT_CLICKED,NULL);


    lv_obj_t * obj;
    lv_obj_t * label;


    obj = lv_obj_create(cont_col);
    lv_obj_set_size(obj, LV_PCT(90), LV_PCT(25));
    lv_obj_add_style(obj,&style,0);
    lv_obj_add_style(obj,&style_pre,LV_STATE_PRESSED);
    label = lv_label_create(obj);
    lv_label_set_text_fmt(label, "WIFI");
    lv_obj_center(label);
    lv_obj_add_event_cb(obj,set_wifi_event_handler,LV_EVENT_CLICKED,NULL);


    obj = lv_obj_create(cont_col);
    lv_obj_set_size(obj, LV_PCT(90), LV_PCT(25));
    lv_obj_add_style(obj,&style,0);
    lv_obj_add_style(obj,&style_pre,LV_STATE_PRESSED);
    label = lv_label_create(obj);
    lv_obj_set_style_text_font(label,&ui_font_Font4,0);
    lv_label_set_text_fmt(label, "屏幕");
    lv_obj_center(label);
    lv_obj_add_event_cb(obj,set_screen_event_handler,LV_EVENT_CLICKED,NULL);

    obj = lv_obj_create(cont_col);
    lv_obj_set_size(obj, LV_PCT(90), LV_PCT(25));
    lv_obj_add_style(obj,&style,0);
    lv_obj_add_style(obj,&style_pre,LV_STATE_PRESSED);
    label = lv_label_create(obj);
    lv_obj_set_style_text_font(label,&ui_font_Font4,0);
    lv_label_set_text_fmt(label, "文件");
    lv_obj_center(label);
    lv_obj_add_event_cb(obj,set_file_event_handler,LV_EVENT_CLICKED,NULL);

    obj = lv_obj_create(cont_col);
    lv_obj_set_size(obj, LV_PCT(90), LV_PCT(25));
    lv_obj_add_style(obj,&style,0);
    lv_obj_add_style(obj,&style_pre,LV_STATE_PRESSED);
    label = lv_label_create(obj);
    lv_obj_set_style_text_font(label,&ui_font_Font4,0);
    lv_label_set_text_fmt(label, "网络");
    lv_obj_center(label);
    lv_obj_add_event_cb(obj,set_network_event_handler,LV_EVENT_CLICKED,NULL);

    obj = lv_obj_create(cont_col);
    lv_obj_set_size(obj, LV_PCT(90), LV_PCT(25));
    lv_obj_add_style(obj,&style,0);
    lv_obj_add_style(obj,&style_pre,LV_STATE_PRESSED);
    label = lv_label_create(obj);
    lv_obj_set_style_text_font(label,&ui_font_Font4,0);
    lv_label_set_text_fmt(label, "摄像头");
    lv_obj_center(label);
    lv_obj_add_event_cb(obj,set_camera_event_handler,LV_EVENT_CLICKED,NULL);

    leftpon_Animation(cont_col, 0);
    leftpon_Animation(btn, 100);
}

void setting_unLoad(lv_obj_t *page)
{

}
