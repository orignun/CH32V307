/*
 * rtc.h
 *
 *  Created on: 2023Äê7ÔÂ4ÈÕ
 *      Author: zhengshengbing
 */

#ifndef HAL_RTC_H_
#define HAL_RTC_H_

typedef struct
{
    vu8 hour;
    vu8 min;
    vu8 sec;

    vu16 w_year;
    vu8  w_month;
    vu8  w_date;
    vu8  week;
} _calendar_obj;

extern _calendar_obj calendar;
u8 RTC_Init(void);
u8 RTC_Set(u16 syear, u8 smon, u8 sday, u8 hour, u8 min, u8 sec);

#endif /* HAL_RTC_H_ */
