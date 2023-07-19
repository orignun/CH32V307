#include "manager_page.h"

void app_start()
{
    style_init();
    lv_pm_init();

    lv_pm_page_t *page = lv_pm_create_page(0);
    page->onLoad = menu_onLoad;
    page->unLoad = menu_unLoad;

    page = lv_pm_create_page(1);
    page->onLoad = photo_onLoad;
    page->unLoad = photo_unLoad;

    page = lv_pm_create_page(2);
    page->onLoad = file_onLoad;
    page->unLoad = file_unLoad;

    page = lv_pm_create_page(3);
    page->onLoad = setting_onLoad;
    page->unLoad = setting_unLoad;


    page = lv_pm_create_page(4);
    page->onLoad = set_wifi_onLoad;
    page->unLoad = set_wifi_unLoad;


    page = lv_pm_create_page(5);
    page->onLoad = set_screen_onLoad;
    page->unLoad = set_screen_unLoad;

    page = lv_pm_create_page(6);
    page->onLoad = set_file_onLoad;
    page->unLoad = set_file_unLoad;

    page = lv_pm_create_page(7);
    page->onLoad = set_network_onLoad;
    page->unLoad = set_network_unLoad;

    page = lv_pm_create_page(8);
    page->onLoad = set_camera_onLoad;
    page->unLoad = set_camera_unLoad;

    lv_pm_open_page(0, NULL);
}
