#include "photo.h"

_lvgl_photo photo={.box_h=135,.box_w=240,.box_x=10,.box_y=73};
char photo_sign;

static void button0_event_cb(lv_event_t *event);

char check_inbox(int16_t x,int16_t y,int16_t w,int16_t h)
{
    // printf("%d\n",x);
    if((x<10)||(y<73)||((x+w)>250)||((y+h)>208))return 1;
    if((w<20)||(h<20)||(w>240)||(h>135))return 1;
    return 0;
}

static void box_press_cb(lv_event_t *event)
{
    if(event->code == LV_EVENT_PRESSED) {
        lv_indev_t * indev = lv_indev_get_act();
        lv_point_t pos;
        lv_indev_get_point(indev, &pos);

        /* 计算相对于 my_box 的坐标 */
        lv_coord_t x = pos.x;
        lv_coord_t y = pos.y;

        /* 计算四个角的相对坐标 */
        photo.box_x = lv_obj_get_x(photo.my_box);
        photo.box_y = lv_obj_get_y(photo.my_box);
        photo.box_w = lv_obj_get_width(photo.my_box);
        photo.box_h = lv_obj_get_height(photo.my_box);
        photo.x_count=0,photo.y_count=0;

        if(x >= photo.box_x && x <= photo.box_x + 20 && y >= photo.box_y && y <= photo.box_y + 20) {
            photo.eve = LV_DIR_TOP_LEFT;printf("TOP_LEFT\n");
        } else if(x >= photo.box_x + photo.box_w - 20 && x <= photo.box_x + photo.box_w && y >= photo.box_y && y <= photo.box_y + 20) {
            photo.eve = LV_DIR_TOP_RIGHT;printf("TOP_RIGHT\n");
        } else if(x >= photo.box_x && x <= photo.box_x + 20 && y >= photo.box_y + photo.box_h - 20 && y <= photo.box_y + photo.box_h) {
            photo.eve = LV_DIR_BOTTOM_LEFT;printf("BOTTOM_LEFT\n");
        } else if(x >= photo.box_x + photo.box_w - 20 && x <= photo.box_x + photo.box_w && y >= photo.box_y + photo.box_h - 20 && y <= photo.box_y + photo.box_h) {
            photo.eve = LV_DIR_BOTTOM_RIGHT;printf("BOTTOM_RIGHT\n");
        }
        else {photo.eve=0;}
    }
    if(event->code == LV_EVENT_PRESSING) {
        lv_indev_t * indev = lv_indev_get_act();
        lv_point_t vect;
        lv_indev_get_vect(indev,&vect);
        // printf("%d\n",vect.x);

        photo.x_count+=vect.x;
        photo.y_count+=vect.y;
        // printf("%d,%d\n",photo.x_count,photo.y_count);
        /* 根据手势调整框的大小 */
        if(photo.eve == LV_DIR_TOP_LEFT) {
            if(check_inbox(photo.x_count + photo.box_x, photo.y_count + photo.box_y,photo.box_w - photo.x_count , photo.box_h - photo.y_count)) return;
            lv_obj_set_size(photo.my_box, photo.box_w - photo.x_count , photo.box_h - photo.y_count );
            lv_obj_set_pos(photo.my_box, photo.x_count + photo.box_x, photo.y_count + photo.box_y);
        } else if(photo.eve == LV_DIR_TOP_RIGHT) {
            if(check_inbox(photo.box_x, photo.y_count + photo.box_y, photo.box_w + photo.x_count, photo.box_h - photo.y_count)) return;
            lv_obj_set_size(photo.my_box, photo.box_w + photo.x_count, photo.box_h - photo.y_count);
            lv_obj_set_pos(photo.my_box, photo.box_x, photo.y_count + photo.box_y);
        } else if(photo.eve == LV_DIR_BOTTOM_RIGHT) {
            if(check_inbox(photo.box_x,photo.box_y, photo.box_w + photo.x_count , photo.box_h + photo.y_count)) return;
            lv_obj_set_size(photo.my_box, photo.box_w + photo.x_count , photo.box_h + photo.y_count );
        } else if(photo.eve == LV_DIR_BOTTOM_LEFT) {
            if(check_inbox(photo.box_x + photo.x_count, photo.box_y, photo.box_w - photo.x_count, photo.y_count + photo.box_h)) return;
            lv_obj_set_size(photo.my_box, photo.box_w - photo.x_count, photo.y_count + photo.box_h);
            lv_obj_set_pos(photo.my_box, photo.box_x + photo.x_count, photo.box_y);
        }

    }
    if(event->code == LV_EVENT_RELEASED) {
        photo.box_x = lv_obj_get_x(photo.my_box);
        photo.box_y = lv_obj_get_y(photo.my_box);
        photo.box_w = lv_obj_get_width(photo.my_box);
        photo.box_h = lv_obj_get_height(photo.my_box);
    }
}

static void box_event_cb(lv_event_t *event)
{
  lv_obj_t * obj = lv_event_get_target(event);
  if(lv_obj_has_state(obj, LV_STATE_CHECKED))
  {
    photo.my_box = lv_obj_create(lv_layer_top());
    lv_obj_set_size(photo.my_box,photo.box_w,photo.box_h);
    lv_obj_set_pos(photo.my_box,photo.box_x,photo.box_y);
    lv_obj_set_style_radius(photo.my_box,0,0);
    lv_obj_set_style_border_width(photo.my_box, 2, LV_STATE_DEFAULT);  // 设置边框宽度
    lv_obj_set_style_border_color(photo.my_box, lv_color_white(), LV_STATE_DEFAULT); // 设置边框颜色
    lv_obj_add_event_cb(photo.my_box, box_press_cb, LV_EVENT_ALL, NULL);  // 注册按下事件回调
    lv_obj_set_style_bg_color(photo.my_box,lv_color_hex(0xAAAAAA),0);
    lv_obj_set_style_bg_opa(photo.my_box,60,0);
    lv_obj_clear_flag(photo.my_box,LV_OBJ_FLAG_CHECKABLE);
  }
  else
  {
    lv_obj_del(photo.my_box);
  }
}

static void forceRecord_event_cb(lv_event_t *event)
{
  lv_obj_t * obj = lv_event_get_target(event);
  if(lv_obj_has_state(obj, LV_STATE_CHECKED))
  {
      send("forceRecord?1");
      photo.forceRecord_value = 1;
  }
  else
  {
      send("forceRecord?0");
      photo.forceRecord_value = 0;
  }
}

static void set_camera_event_handler(lv_event_t *e)
{
    lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};
    lv_pm_open_page(8, &newpage);
    photo_sign = 1;
}

void photo_onLoad(lv_obj_t *page)
{
    send("photo?1");

    photo.img = lv_obj_create(page);
    lv_obj_set_size(photo.img, 240, 135);
    lv_obj_set_style_bg_img_src(photo.img,"D:bj.bin",0);
    lv_obj_set_style_radius(photo.img,0,0);
    lv_obj_add_flag(photo.img, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_clear_flag(photo.img, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_shadow_color(photo.img, lv_color_hex(0xB048FF),LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(photo.img, 15,LV_STATE_CHECKED);
    lv_obj_set_style_shadow_spread(photo.img, 0,LV_STATE_CHECKED);
    lv_obj_align(photo.img, LV_ALIGN_LEFT_MID, 10, 20);



    // lv_obj_t *close = lv_img_create(page);
    // // lv_img_set_src(close, &CLOSE);
    // lv_obj_set_size(close,20,20);
    // lv_img_set_src(close,"D:6.bin");
    // lv_obj_align(close, LV_ALIGN_TOP_RIGHT, 0, 28);
    // lv_obj_add_event_cb(close, button0_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_t *close = lv_obj_create(page);
    lv_obj_set_size(close,20,20);
    lv_obj_align(close, LV_ALIGN_TOP_RIGHT, -5, 35);
    lv_obj_clear_flag(close,LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(close,0,0);
    lv_obj_set_style_border_width(close,0,0);
    lv_obj_set_style_bg_opa(close,0,0);
    lv_obj_add_event_cb(close, button0_event_cb, LV_EVENT_CLICKED, NULL);
    static lv_point_t line_points[] = { {1, 1}, {15, 10}, {1, 20} };

    /*Create a line and apply the new style*/
    lv_obj_t * line1;
    line1 = lv_line_create(close);
    lv_line_set_points(line1, line_points, 3);     /*Set the points*/
    lv_obj_add_style(line1, &style_line, 0);
    lv_obj_center(line1);


    photo.forceRecord = lv_btn_create(page);
    lv_obj_add_flag(photo.forceRecord,LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_size(photo.forceRecord,40,40);
    lv_obj_align(photo.forceRecord, LV_ALIGN_RIGHT_MID, -10, 20);
    lv_obj_add_event_cb(photo.forceRecord,forceRecord_event_cb,LV_EVENT_VALUE_CHANGED,NULL);

    lv_obj_t *obj = lv_btn_create(page);
    lv_obj_set_size(obj,20,20);
    lv_obj_set_style_bg_opa(obj,0,0);
    lv_obj_set_style_bg_opa(obj,0,LV_STATE_CHECKED);
    lv_obj_align(obj, LV_ALIGN_RIGHT_MID, -20, 80);
    lv_obj_add_flag(obj,LV_OBJ_FLAG_CHECKABLE);
    // lv_obj_set_style_bg_img_src(obj,"D:32.bin",LV_STATE_CHECKED);
    lv_obj_set_style_bg_img_src(obj,"D:32.bin",LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(obj,50,0);
    lv_obj_set_style_bg_img_opa(obj,255,LV_STATE_CHECKED);
    // lv_img_set_src(obj,"D:32.bin");
    // lv_obj_set_style_img_recolor(obj,lv_palette_main(LV_PALETTE_RED),0);
    // lv_obj_set_style_img_recolor_opa(obj, 100, 0);
    lv_obj_add_event_cb(obj,box_event_cb,LV_EVENT_VALUE_CHANGED,NULL);


    status_bar_init(page);

    obj = lv_obj_create(page);
    lv_obj_set_size(obj,80,80);
    lv_obj_set_pos(obj,-40,-40);
    lv_obj_set_style_radius(obj,80,0);
    lv_obj_set_style_bg_color(obj,lv_color_hex(0x9483F4),0);
    lv_obj_set_style_border_width(obj,0,0);

    lv_obj_set_style_shadow_color(obj,lv_color_hex(0xF82727),LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(obj,10,LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(obj,5,LV_STATE_PRESSED);
    // lv_obj_align(obj, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_event_cb(obj,set_camera_event_handler,LV_EVENT_CLICKED,NULL);

    obj = lv_img_create(obj);
    lv_obj_set_pos(obj,30,30);
    lv_img_set_src(obj,"D:31.bin");



}

void photo_unLoad(lv_obj_t *page)
{
    send("photo?0");
    // if(photo.my_box!=NULL)
    if(lv_obj_is_valid(photo.my_box))
    lv_obj_del(photo.my_box);

     
}

static void button0_event_cb(lv_event_t *event)
{
	lv_pm_open_options_t newpage = {
		.target = LV_PM_TARGET_SELF};

	lv_pm_open_page(0, &newpage);
}

