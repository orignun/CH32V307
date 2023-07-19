#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef enum
{
    WIFI_CLOSE = 0,
    WIFI_OPEN,
    WIFI_CONNECT,
}connect_status_t;


#define WIFI_AP_CLOSE 0
#define WIFI_AP_OPEN 1

#define OFF_CHARGE 0
#define ON_CHARGE 1

extern lv_obj_t* status_bar;

void status_bar_init(lv_obj_t *page);
void status_bar_uninit();


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*STATUS_BAR_H*/
