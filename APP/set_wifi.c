#include "set_wifi.h"

_lvgl_set_wifi set_wifi={.ap_ssid="ch32",.ap_password=""};
LV_FONT_DECLARE(ui_font_Font4);

static void draw_part_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_param(e);
    /*If the cells are drawn...*/
    if(dsc->part == LV_PART_ITEMS) {
        uint32_t row = dsc->id /  lv_table_get_col_cnt(obj);
        uint32_t col = dsc->id - row * lv_table_get_col_cnt(obj);

        /*Make the texts in the first cell center aligned*/
//        if(row == 0) {
//            dsc->label_dsc->align = LV_TEXT_ALIGN_CENTER;
//            dsc->rect_dsc->bg_color = lv_color_mix(lv_palette_main(LV_PALETTE_BLUE), dsc->rect_dsc->bg_color, LV_OPA_20);
//            dsc->rect_dsc->bg_opa = LV_OPA_COVER;
//        }
//        /*In the first column align the texts to the right*/
//        else
            if(col == 0) {
            dsc->label_dsc->align = LV_TEXT_ALIGN_CENTER;
        }

        /*MAke every 2nd row grayish*/
        if((row != 0 && row % 2) == 0) {
            dsc->rect_dsc->bg_color = lv_color_mix(lv_palette_main(LV_PALETTE_GREY), dsc->rect_dsc->bg_color, LV_OPA_10);
            dsc->rect_dsc->bg_opa = LV_OPA_COVER;
        }
    }
}
static void lvgl_kb_event_cb(lv_event_t *event)
{
	lv_obj_t *obj = lv_event_get_target(event);
		if (event->code == LV_EVENT_CANCEL)
		{
      lv_obj_del(set_wifi.keyboard);
      lv_obj_del(set_wifi.textarea);
		}
		else if (event->code == LV_EVENT_READY)
		{

          char wifi_name[64];
          sprintf(wifi_name,"ST_Pass?%s",(char *)lv_textarea_get_text(set_wifi.textarea));
          send(wifi_name);
          printf(wifi_name);

          lv_obj_del(set_wifi.keyboard);
          lv_obj_del(set_wifi.textarea);

		}
}
static void defocused_event_cb(lv_event_t *event)
{
    lv_obj_del(set_wifi.keyboard);
    lv_obj_del(set_wifi.textarea);
}
static void change_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    uint16_t col;
    uint16_t row;
    lv_table_get_selected_cell(obj, &row, &col);
//    set_wifi.ssid = lv_table_get_cell_value(obj,row,col);
    char wifi_name[64];
    sprintf(wifi_name,"ST_SSID?%s",lv_table_get_cell_value(obj,row,col));
    send(wifi_name);
    printf(wifi_name);

    if(lv_obj_is_valid(set_wifi.textarea))
      lv_obj_del(set_wifi.textarea);
       
      set_wifi.textarea = lv_textarea_create(lv_layer_top());
      lv_textarea_set_one_line(set_wifi.textarea,true);    
      lv_obj_align(set_wifi.textarea,LV_ALIGN_CENTER,0,-30);
      lv_obj_add_event_cb(set_wifi.textarea,defocused_event_cb,LV_EVENT_DEFOCUSED,NULL);
        lv_obj_add_state(set_wifi.textarea,LV_STATE_FOCUSED);
    

    if(lv_obj_is_valid(set_wifi.keyboard))
    lv_obj_del(set_wifi.keyboard);
        
      set_wifi.keyboard = lv_keyboard_create(lv_layer_top());
      lv_obj_align(set_wifi.keyboard,LV_ALIGN_BOTTOM_MID,0,0);
      lv_keyboard_set_textarea(set_wifi.keyboard,set_wifi.textarea);
      lv_obj_add_event_cb(set_wifi.keyboard,lvgl_kb_event_cb,LV_EVENT_ALL,NULL);
    

}

static void text_input_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
  if (e->code == LV_EVENT_FOCUSED) 
  {
    if(lv_obj_is_valid(set_wifi.textarea))
      lv_obj_del(set_wifi.textarea);
    if(lv_obj_is_valid(set_wifi.keyboard))
      lv_obj_del(set_wifi.keyboard);
    set_wifi.keyboard = lv_keyboard_create(lv_layer_top());
    lv_keyboard_set_textarea(set_wifi.keyboard,obj);
    lv_obj_align(set_wifi.keyboard, LV_ALIGN_BOTTOM_MID, 0, 0);
    set_wifi.current_x = lv_obj_get_scroll_y(set_wifi.cont);
    if(!lv_obj_is_valid(set_wifi.table))    
      lv_obj_set_size(set_wifi.panel2, 320, 120);     
    lv_obj_scroll_to_y(set_wifi.cont,40,LV_ANIM_ON);


  }
  else if (e->code == LV_EVENT_DEFOCUSED) 
  {
      char buf[48];
      if(obj == set_wifi.ap_ssid_obj)
      {
          strcpy(set_wifi.ap_ssid,(char *)lv_textarea_get_text(obj));
          sprintf(buf,"AP_SSID?%s",set_wifi.ap_ssid);
          send(buf);
      }
      else
      {
          strcpy(set_wifi.ap_password,(char *)lv_textarea_get_text(obj));
          sprintf(buf,"AP_Pass?%s",set_wifi.ap_password);
          send(buf);
      }

    lv_obj_del(set_wifi.keyboard);
    if(!lv_obj_is_valid(set_wifi.table))
      lv_obj_set_size(set_wifi.panel2, 320, 80); 
    lv_obj_scroll_to_y(set_wifi.cont,set_wifi.current_x,LV_ANIM_ON);
  }
}

static void del_event_cb(lv_event_t * e)
{
  if(lv_obj_is_valid(set_wifi.keyboard))
    lv_obj_del(set_wifi.keyboard);
  if(lv_obj_is_valid(set_wifi.textarea))
    lv_obj_del(set_wifi.textarea);
}

static void sta_switch_event_cb(lv_event_t * e)
{
  lv_obj_t * obj = lv_event_get_target(e);
  if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
    lv_obj_set_size(set_wifi.panel2, 320, 300); 
    set_wifi.table = lv_table_create(set_wifi.panel2);
    lv_obj_set_size(set_wifi.table, 200, 210);    
    lv_table_set_col_cnt(set_wifi.table, 1);
    lv_obj_clear_flag(set_wifi.table,LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(set_wifi.table,0,0);
    lv_table_set_col_cnt(set_wifi.table,1);
//    for(int i = 0; i < 5; i++) {
//        lv_table_set_cell_value_fmt(set_wifi.table, i, 0, "Item %"LV_PRIu32, i + 1);
//        lv_table_set_col_width(set_wifi.table,i,200);
//    }
    lv_obj_align(set_wifi.table,LV_ALIGN_BOTTOM_MID,0,0);
    lv_obj_add_event_cb(set_wifi.table, draw_part_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_obj_add_event_cb(set_wifi.table, change_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    send("allowSTA?1");
    set_wifi.start_sta = 1;
  }
  else
  {
    if(lv_obj_is_valid(set_wifi.table))
        lv_obj_del(set_wifi.table);
    lv_obj_set_size(set_wifi.panel2, 320, 80); 
    lv_obj_scroll_to_y(set_wifi.cont,0,LV_ANIM_ON);
    send("allowSTA?0");
    set_wifi.start_sta = 0;
  }
}

static void event_handler_AP(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_obj_has_state(obj, LV_STATE_CHECKED)){
        send("allowAP?1");
        set_wifi.start_ap = 1;
    }
    else {
        send("allowAP?0");
        set_wifi.start_ap = 0;
    }
}

static void event_handler_back(lv_event_t *e)
{
    lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};
    lv_pm_open_page(3, &newpage);
}

void set_wifi_onLoad(lv_obj_t *page)
{


    send("getwificonfig?0");

    lv_obj_clear_flag(page,LV_OBJ_FLAG_SCROLLABLE);

    set_wifi.cont = lv_obj_create(page);
    lv_obj_set_size(set_wifi.cont, lv_pct(100), 200);
    lv_obj_align(set_wifi.cont, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_flex_flow(set_wifi.cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_all(set_wifi.cont,0,0);
    lv_obj_set_style_pad_row(set_wifi.cont,0,0);
    lv_obj_set_style_pad_column(set_wifi.cont,0,0);
    lv_obj_set_style_radius(set_wifi.cont,0,0);
    lv_obj_set_style_outline_width(set_wifi.cont,0,0);
    lv_obj_set_scroll_dir(set_wifi.cont,LV_DIR_VER);
    // lv_obj_clear_flag(set_wifi.cont,LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_pad_right(set_wifi.cont,-3,LV_PART_SCROLLBAR);

    lv_obj_t *panel1 = lv_obj_create(set_wifi.cont);
    lv_obj_set_size(panel1, 320, 120);  
    lv_obj_set_style_outline_width(panel1,0,0);
    lv_obj_set_style_border_side(panel1,LV_BORDER_SIDE_BOTTOM,0); 
    lv_obj_set_style_border_width(panel1,1,0);
    lv_obj_set_style_border_color(panel1,lv_color_hex(0x505050),0);
    lv_obj_set_style_radius(panel1,0,0);
    lv_obj_add_event_cb(panel1, del_event_cb, LV_EVENT_FOCUSED, NULL);


    lv_obj_t *obj = lv_label_create(panel1);
    lv_obj_align(obj,LV_ALIGN_TOP_LEFT,10,0);
    lv_obj_set_style_text_font(obj,&ui_font_Font4,0);
    lv_label_set_text(obj,"热点");

    
    set_wifi.ap_switch = lv_switch_create(panel1);
    lv_obj_align(set_wifi.ap_switch,LV_ALIGN_TOP_RIGHT,-20,0);
    if(set_wifi.start_ap)
        lv_obj_add_state(set_wifi.ap_switch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(set_wifi.ap_switch, LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_wifi.ap_switch, event_handler_AP,LV_EVENT_VALUE_CHANGED,NULL);

    set_wifi.ap_ssid_obj = lv_textarea_create(panel1);
    lv_obj_set_width(set_wifi.ap_ssid_obj,120);
    lv_textarea_set_one_line(set_wifi.ap_ssid_obj,true);
    lv_obj_align(set_wifi.ap_ssid_obj,LV_ALIGN_BOTTOM_LEFT,5,0);
    lv_textarea_set_text(set_wifi.ap_ssid_obj,set_wifi.ap_ssid);
    lv_obj_add_event_cb(set_wifi.ap_ssid_obj, text_input_event_cb,LV_EVENT_ALL,NULL);
    

    set_wifi.ap_password_obj = lv_textarea_create(panel1);
    lv_obj_set_width(set_wifi.ap_password_obj,120);
    lv_textarea_set_one_line(set_wifi.ap_password_obj,true);
    lv_obj_align(set_wifi.ap_password_obj,LV_ALIGN_BOTTOM_RIGHT,-5,0);
    lv_textarea_set_text(set_wifi.ap_password_obj,set_wifi.ap_password);
    lv_obj_add_event_cb(set_wifi.ap_password_obj, text_input_event_cb,LV_EVENT_ALL,NULL);


    set_wifi.panel2 = lv_obj_create(set_wifi.cont);
    lv_obj_set_size(set_wifi.panel2, 320, 80); 
    lv_obj_set_style_outline_width(set_wifi.panel2,0,0); 
    lv_obj_set_style_radius(set_wifi.panel2,0,0);
    lv_obj_add_event_cb(set_wifi.panel2, del_event_cb, LV_EVENT_FOCUSED, NULL);


    obj = lv_label_create(set_wifi.panel2);
    lv_obj_align(obj,LV_ALIGN_TOP_LEFT,10,0);
    lv_label_set_text(obj,"WiFi");


    set_wifi.sta_switch = lv_switch_create(set_wifi.panel2);
    lv_obj_align(set_wifi.sta_switch,LV_ALIGN_TOP_RIGHT,-20,0);
    if(set_wifi.start_sta)
        lv_obj_add_state(set_wifi.sta_switch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(set_wifi.sta_switch, LV_STATE_CHECKED);
    lv_obj_add_event_cb(set_wifi.sta_switch, sta_switch_event_cb,LV_EVENT_VALUE_CHANGED,NULL);

    status_bar_init(page);

    obj = lv_imgbtn_create(page);
    lv_obj_set_size(obj,20,20);
    lv_img_set_src(obj,"D:6.bin");
    lv_obj_align(obj, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_event_cb(obj,event_handler_back,LV_EVENT_CLICKED,NULL);

    seton_Animation(set_wifi.cont,100);
    leftpon_Animation(obj,0);
}
void set_wifi_unLoad(lv_obj_t *page)
{
     
}
