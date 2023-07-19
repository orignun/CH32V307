#include "menu.h"
#include "math.h"

_lvgl_menu_cont menu_cont;

static void photo_btn_event_cb(lv_event_t *event);
static void file_btn_event_cb(lv_event_t *event);
static void set_btn_event_cb(lv_event_t *event);

void menu_onLoad(lv_obj_t *page)
{

//    lv_obj_t *img = lv_img_create(page);
//    lv_img_set_src(img,"D:bj.bin");


    menu_cont.photo_btn = lv_btn_create(page);
    lv_obj_set_size(menu_cont.photo_btn,80,80);
    lv_obj_align(menu_cont.photo_btn,LV_ALIGN_BOTTOM_LEFT,10,-50);
    lv_obj_set_style_bg_img_src(menu_cont.photo_btn,"D:11.bin",0);
//    lv_img_set_src(menu_cont.photo_btn,"D:13.bin");
    lv_obj_set_style_bg_color(menu_cont.photo_btn,lv_color_white(),0);
    lv_obj_set_style_shadow_color(menu_cont.photo_btn,lv_color_hex(0x5875FF),LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_y(menu_cont.photo_btn,10,LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(menu_cont.photo_btn,20,LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(menu_cont.photo_btn,5,LV_STATE_PRESSED);
    lv_obj_add_event_cb(menu_cont.photo_btn,photo_btn_event_cb,LV_EVENT_CLICKED,NULL);


    menu_cont.file_btn = lv_btn_create(page);
    lv_obj_set_size(menu_cont.file_btn,80,80);
    lv_obj_align(menu_cont.file_btn,LV_ALIGN_BOTTOM_MID,0,-50);
    lv_obj_set_style_bg_img_src(menu_cont.file_btn,"D:12.bin",0);
//    lv_img_set_src(menu_cont.file_btn,"D:11.bin");
    lv_obj_set_style_bg_color(menu_cont.file_btn,lv_color_white(),0);
    lv_obj_set_style_shadow_color(menu_cont.file_btn,lv_color_hex(0x5875FF),LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_y(menu_cont.file_btn,10,LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(menu_cont.file_btn,20,LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(menu_cont.file_btn,5,LV_STATE_PRESSED);
    lv_obj_add_event_cb(menu_cont.file_btn,file_btn_event_cb,LV_EVENT_CLICKED,NULL);


    menu_cont.set_btn = lv_btn_create(page);
    lv_obj_set_size(menu_cont.set_btn,80,80);
    lv_obj_align(menu_cont.set_btn,LV_ALIGN_BOTTOM_RIGHT,-10,-50);
    lv_obj_set_style_bg_img_src(menu_cont.set_btn,"D:13.bin",0);
//    lv_img_set_src(menu_cont.set_btn,"D:15.bin");
    lv_obj_set_style_bg_color(menu_cont.set_btn,lv_color_white(),0);
    lv_obj_set_style_shadow_color(menu_cont.set_btn,lv_color_hex(0x5875FF),LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_y(menu_cont.set_btn,10,LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(menu_cont.set_btn,20,LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(menu_cont.set_btn,5,LV_STATE_PRESSED);
    lv_obj_add_event_cb(menu_cont.set_btn,set_btn_event_cb,LV_EVENT_CLICKED,NULL);

    status_bar_init(page);

    fadeon_Animation(menu_cont.photo_btn,0);
    fadeon_Animation(menu_cont.file_btn,50);
    fadeon_Animation(menu_cont.set_btn,100);
}

void menu_unLoad(lv_obj_t *page)
{
     
}
void open_page_1(lv_timer_t * timer)
{
    lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};

    lv_pm_open_page(timer->user_data, &newpage);
    lv_timer_del(timer);
}

lv_timer_t *timer;
static void photo_btn_event_cb(lv_event_t *event)
{
    topoff_Animation(status_bar, 0);
    fadeoff_Animation(menu_cont.photo_btn,100);
    fadeoff_Animation(menu_cont.file_btn,50);
    fadeoff_Animation(menu_cont.set_btn,0);
    timer = lv_timer_create(open_page_1,300,1);
}

static void file_btn_event_cb(lv_event_t *event)
{
    topoff_Animation(status_bar, 0);
    fadeoff_Animation(menu_cont.photo_btn,100);
    fadeoff_Animation(menu_cont.file_btn,50);
    fadeoff_Animation(menu_cont.set_btn,0);
    timer = lv_timer_create(open_page_1,300,2);
}

static void set_btn_event_cb(lv_event_t *event)
{
    topoff_Animation(status_bar, 0);
    fadeoff_Animation(menu_cont.photo_btn,100);
    fadeoff_Animation(menu_cont.file_btn,50);
    fadeoff_Animation(menu_cont.set_btn,0);
    timer = lv_timer_create(open_page_1,300,3);
}
