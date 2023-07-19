#include "set_file.h"

_lvgl_set_file set_file;

static void event_handler_back(lv_event_t *e)
{
    lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};
    lv_pm_open_page(3, &newpage);
}

void set_file_onLoad(lv_obj_t *page)
{
    lv_obj_clear_flag(page,LV_OBJ_FLAG_SCROLLABLE);

    set_file.cont = lv_obj_create(page);
    lv_obj_set_size(set_file.cont, lv_pct(100), 200);
    lv_obj_align(set_file.cont, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_flex_flow(set_file.cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_all(set_file.cont,0,0);
    lv_obj_set_style_pad_row(set_file.cont,0,0);
    lv_obj_set_style_pad_column(set_file.cont,0,0);
    lv_obj_set_style_radius(set_file.cont,0,0);
    lv_obj_set_style_outline_width(set_file.cont,0,0);
    lv_obj_set_scroll_dir(set_file.cont,LV_DIR_VER);
    lv_obj_set_style_pad_right(set_file.cont,-3,LV_PART_SCROLLBAR);

    lv_obj_t *panel = lv_obj_create(set_file.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    lv_obj_t *obj = lv_label_create(panel);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_label_set_text(obj,"最大储藏时间");

    obj = lv_dropdown_create(panel);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_obj_set_style_text_font(lv_dropdown_get_list(obj),&ui_font_Font4,0);
    lv_obj_set_style_text_font(obj,&lv_font_montserrat_14,LV_PART_INDICATOR);
    lv_dropdown_set_options(obj,"无限制\n"
                                "1天\n"
                                "7天\n"
                                "15天\n"
                                "1月\n"
                                "3月");
    lv_obj_align(obj,LV_ALIGN_RIGHT_MID,-10,0);

    panel = lv_obj_create(set_file.cont);
    lv_obj_set_size(panel, lv_pct(100), 80);  
    lv_obj_set_style_outline_width(panel,0,0);
    lv_obj_set_style_border_side(panel,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel,1,0);
    lv_obj_set_style_border_color(panel,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel,0,0);

    obj = lv_label_create(panel);
    lv_obj_align(obj,LV_ALIGN_LEFT_MID,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"单日最大数量");

    obj = lv_dropdown_create(panel);
    // lv_obj_set_style_bg_color(obj,lv_color_hex(0x000000),0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_obj_set_style_text_font(lv_dropdown_get_list(obj),&ui_font_Font4,0);
    lv_obj_set_style_text_font(obj,&lv_font_montserrat_14,LV_PART_INDICATOR);
    lv_dropdown_set_options(obj, "无限制\n"
                                "5\n"
                                "10\n"
                                "25\n"
                                "50\n"
                                "100");
    lv_obj_align(obj,LV_ALIGN_RIGHT_MID,-10,0);

    status_bar_init(page);

    obj = lv_imgbtn_create(page);
    lv_obj_set_size(obj,20,20);
    lv_img_set_src(obj,"D:6.bin");
    lv_obj_align(obj, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_event_cb(obj,event_handler_back,LV_EVENT_CLICKED,NULL);

    seton_Animation(set_file.cont,100);
    leftpon_Animation(obj,0);

}
void set_file_unLoad(lv_obj_t *page)
{
     
}
