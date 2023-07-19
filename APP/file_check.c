#include "file_check.h"
#include "stdio.h"

/* 定义文件检查器的数据结构 */
_lvgl_file_check file_check = {.path_base = "D:/data"};

/* 点击事件回调函数 */
static void event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
//        LV_LOG_USER("Clicked: %s", lv_list_get_btn_text(file_check.lv_list_left, obj));

        /* 判断刚才点击的按钮和当前按钮是否一致，用于清除之前选中的状态 */
        if (file_check.currentButton == obj)
        {
            file_check.currentButton = NULL;
        }
        else
        {
            file_check.currentButton = obj;
        }
        lv_obj_t *parent = lv_obj_get_parent(obj);
        uint32_t i;
        for (i = 0; i < lv_obj_get_child_cnt(parent); i++)
        {
            lv_obj_t *child = lv_obj_get_child(parent, i);
            if (child == file_check.currentButton)
            {
                lv_obj_add_state(child, LV_STATE_CHECKED);
            }
            else
            {
                lv_obj_clear_state(child, LV_STATE_CHECKED);
            }
        }
//        printf("clicked:%s\n", lv_list_get_btn_text(file_check.lv_list_left, obj));
    }
}

/* 添加列表函数 */
void add_list()
{
    /* 清空之前的列表 */
    lv_obj_clean(file_check.lv_list_left);

    lv_obj_t *btn;
    char dirent[128];
    lv_fs_dir_t dir;

    /* 打开指定目录 */
    lv_fs_res_t res = lv_fs_dir_open(&dir, file_check.path_base);

//    /* 读取目录第一个文件或子目录 */
//    lv_fs_dir_read(&dir, dirent);
//
//    /* 创建第一个按钮并添加到列表中 */
//    btn = lv_btn_create(file_check.lv_list_left);
//    lv_obj_set_width(btn, lv_pct(100));
//    lv_obj_set_style_bg_color(btn, lv_color_hex(0x333333), 0);
//    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);
//
//    lv_obj_t *lab = lv_label_create(btn);
//
//    /* 如果是目录则显示目录图标，否则不显示 */
//    if (dirent[0] == '/')
//    {
//        /* 使用 LVGL 内置的目录图标 */
//        lv_label_set_text_fmt(lab, LV_SYMBOL_DIRECTORY "  %s", dirent + 1);
//    }
//    else
//    {
//        lv_label_set_text_fmt(lab, dirent);
//    }

    /* 循环读取目录下的其他文件及子目录并添加到列表中 */
    while (lv_fs_dir_read(&dir, dirent) == LV_FS_RES_OK)
    {
        btn = lv_btn_create(file_check.lv_list_left);
        lv_obj_set_width(btn, lv_pct(100));
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x333333), 0);
        lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

        lv_obj_t *lab = lv_label_create(btn);
        if (dirent[0] == '/')
        {
            lv_label_set_text_fmt(lab, LV_SYMBOL_DIRECTORY "  %s", dirent + 1);
        }
        else
        {
            lv_label_set_text_fmt(lab, dirent);
        }
    }

    /* 关闭目录 */
    lv_fs_dir_close(&dir);
}

/* 向上滚动事件回调函数 */
static void event_handler_top(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        if (file_check.currentButton == NULL)
            return;
        /* 滚动到列表的第一个元素位置 */
        lv_obj_scroll_to_view(lv_obj_get_child(file_check.lv_list_left, 0), LV_ANIM_ON);
    }
}

/* 向下滚动事件回调函数 */
static void event_handler_bottom(lv_event_t *e)
{
    const lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        if (file_check.currentButton == NULL)
            return;
        /* 滚动到列表的最后一个元素位置 */
        lv_obj_scroll_to_view(lv_obj_get_child(file_check.lv_list_left, -1), LV_ANIM_ON);
    }
}

/* 打开事件回调函数 */
static void event_handler_open(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        if (file_check.currentButton == NULL)
            return;
        if (strstr(lv_list_get_btn_text(file_check.lv_list_left, file_check.currentButton),"avi"))
            return ;
        char name[128];
        char name_end[128];

        /* 解析当前选中目录或文件的名称 */
        sscanf(lv_list_get_btn_text(file_check.lv_list_left, file_check.currentButton), LV_SYMBOL_DIRECTORY "  %s", name_end);
        sprintf(name, "%s/%s", file_check.path_base, name_end);

        /* 判断当前选中的是目录还是文件 */
        lv_fs_dir_t dir;
        lv_fs_res_t res = lv_fs_dir_open(&dir, name);
        if (res == 0)
        {
            /* 如果是目录，则切换目录并重新显示新目录下的文件和子目录 */
            strcpy(file_check.path_base, name);
            add_list();
            file_check.currentButton = NULL;
        }
        else
        {
            /* 如果是文件，则打开该文件并进行相应处理 */
            sprintf(name, "%s/%s", file_check.path_base, lv_list_get_btn_text(file_check.lv_list_left, file_check.currentButton));
            printf("path:%s\n", name);
        }
    }
}

/* 返回事件回调函数 */
static void event_handler_back(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if(strcmp(file_check.path_base,"D:/data")==0)return;
    if (code == LV_EVENT_CLICKED)
    {
        if (file_check.path_base == NULL)
            return;

        /* 找到最后一个 '\\' 的位置，以确定路径中上一级目录的位置 */
        char *last_slash = strrchr(file_check.path_base, '/');

        if (last_slash != NULL)
        {
            /* 将最后一个 '\\' 替换成 '\0'，即可得到上一级目录位置 */
            *last_slash = '\0';
        }
        printf("%s/n", file_check.path_base);
        add_list();
    }
}

void event_cb(lv_event_t *e)
{
    lv_obj_t * obj = lv_event_get_current_target(e);
    char buf[128];
    if(strcmp(lv_msgbox_get_active_btn_text(obj),"Yes")==0)
    {
        sprintf(buf,"delete?%s/%s", file_check.path_base + 2, lv_list_get_btn_text(file_check.lv_list_left, file_check.currentButton));
        send(buf);
        lv_obj_del(file_check.currentButton);
        lv_obj_del(obj);
    }
    if(strcmp(lv_msgbox_get_active_btn_text(obj),"No")==0)
        lv_obj_del(obj);
}
static void event_handler_delete(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        if(file_check.currentButton != NULL)
        {
            static const char * btns[] ={"Yes", "No"};

            lv_obj_t * mbox1 = lv_msgbox_create(lv_layer_top(), "Sure", "", btns, true);
            lv_obj_add_event_cb(mbox1, event_cb, LV_EVENT_VALUE_CHANGED, NULL);
            lv_obj_center(mbox1);
        }
    }
}

/* 退出事件回调函数 */
static void event_handler_quit(lv_event_t *event)
{
    /* 关闭当前页面 */
    lv_pm_open_options_t newpage = {
        .target = LV_PM_TARGET_SELF};
    lv_pm_open_page(0, &newpage);
}

/* 文件浏览器页面加载函数 */
void file_onLoad(lv_obj_t *page)
{
    /* 创建列表控件并设置样式 */
    file_check.lv_list_left = lv_list_create(page);
    lv_obj_set_size(file_check.lv_list_left, lv_pct(60), lv_pct(100));
    lv_obj_set_style_pad_row(file_check.lv_list_left, 5, 0);
    lv_obj_set_style_pad_top(file_check.lv_list_left, 5, 0);

    /* 添加文件和目录列表 */
    add_list();

    /* 默认选中第一个按钮 */
    file_check.currentButton = lv_obj_get_child(file_check.lv_list_left, 0);
    lv_obj_add_state(file_check.currentButton, LV_STATE_CHECKED);

    /* 创建操作列表 */
    file_check.lv_list_right = lv_list_create(page);
    lv_obj_set_size(file_check.lv_list_right, lv_pct(40), lv_pct(100));
    lv_obj_align(file_check.lv_list_right, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_flex_flow(file_check.lv_list_right, LV_FLEX_FLOW_COLUMN);

    /* 向上滚动按钮 */
    lv_obj_t *btn;
    btn = lv_list_add_btn(file_check.lv_list_right, LV_SYMBOL_UP, "Top");
    lv_obj_add_event_cb(btn, event_handler_top, LV_EVENT_ALL, NULL);
    lv_group_remove_obj(btn);

    /* 向下滚动按钮 */
    btn = lv_list_add_btn(file_check.lv_list_right, LV_SYMBOL_DOWN, "Bottom");
    lv_obj_add_event_cb(btn, event_handler_bottom, LV_EVENT_ALL, NULL);
    lv_group_remove_obj(btn);

    /* 返回按钮 */
    btn = lv_list_add_btn(file_check.lv_list_right, LV_SYMBOL_TRASH, "Delete");
    lv_obj_add_event_cb(btn, event_handler_delete, LV_EVENT_ALL, NULL);
    lv_group_remove_obj(btn);

    /* 打开按钮 */
    btn = lv_list_add_btn(file_check.lv_list_right, LV_SYMBOL_PLAY, "Open");
    lv_obj_add_event_cb(btn, event_handler_open, LV_EVENT_ALL, NULL);
    lv_group_remove_obj(btn);

    /* 返回按钮 */
    btn = lv_list_add_btn(file_check.lv_list_right, LV_SYMBOL_NEW_LINE, "Back");
    lv_obj_add_event_cb(btn, event_handler_back, LV_EVENT_ALL, NULL);
    lv_group_remove_obj(btn);

    /* 退出按钮 */
    btn = lv_list_add_btn(file_check.lv_list_right, LV_SYMBOL_SHUFFLE, "Quit");
    lv_obj_add_event_cb(btn, event_handler_quit, LV_EVENT_CLICKED, NULL);
    lv_group_remove_obj(btn);

    filelefton_Animation(file_check.lv_list_left, 0);
    filerighton_Animation(file_check.lv_list_right, 0);

    send("gettime?1");
}

/* 文件浏览器页面卸载函数 */
void file_unLoad(lv_obj_t *page)
{
}
