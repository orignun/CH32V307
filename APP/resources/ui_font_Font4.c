/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:\Users\zhengshengbing\Desktop\shuangche\lvgl\assets\Deng.ttf -o C:\Users\zhengshengbing\Desktop\shuangche\lvgl\assets\ui_font_Font4.c --format lvgl --symbols 热点熄屏时间亮度网络图像屏幕摄像头文件运动检测录像保存灵敏度分辨率水平翻转镜像对比度饱和度特殊效果灰度红色绿蓝反转无夜晚切换最小单日大数量月天个储藏无限制服务器邮箱账号密码打开关闭单次地址FTPSM125073 --no-compress --no-prefilter
 ******************************************************************************/

#include "lvgl.h"

#ifndef UI_FONT_FONT4
#define UI_FONT_FONT4 1
#endif

#if UI_FONT_FONT4

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0xd, 0x11, 0xc0,

    /* U+0031 "1" */
    0x31, 0x49, 0x4, 0x10, 0x41, 0x4, 0x10, 0x41,
    0x3f,

    /* U+0032 "2" */
    0x3c, 0x8d, 0x8, 0x10, 0x20, 0x82, 0x8, 0x20,
    0xc1, 0x7, 0xf0,

    /* U+0033 "3" */
    0x3c, 0x8d, 0x8, 0x10, 0x43, 0x1, 0x1, 0x2,
    0x85, 0x19, 0xe0,

    /* U+0035 "5" */
    0x7c, 0x81, 0x2, 0x7, 0xc8, 0xc0, 0x81, 0x2,
    0x85, 0x11, 0xc0,

    /* U+0037 "7" */
    0xfe, 0x8, 0x10, 0x40, 0x82, 0x4, 0x8, 0x20,
    0x40, 0x81, 0x0,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0x83, 0xe8, 0x20, 0x82, 0x8,
    0x20,

    /* U+004D "M" */
    0xc0, 0x78, 0xf, 0x1, 0xd0, 0x5a, 0xb, 0x22,
    0x64, 0x4c, 0x89, 0x8a, 0x31, 0x46, 0x28, 0xc2,
    0x10,

    /* U+0050 "P" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x2, 0x4, 0x0,

    /* U+0053 "S" */
    0x79, 0x8a, 0xc, 0xc, 0xe, 0x3, 0x1, 0x3,
    0x7, 0x1b, 0xe0,

    /* U+0054 "T" */
    0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10,

    /* U+4E2A "个" */
    0x1, 0x0, 0x6, 0x0, 0xa, 0x0, 0x26, 0x0,
    0x86, 0x2, 0x23, 0x18, 0x43, 0xe0, 0x80, 0x1,
    0x0, 0x2, 0x0, 0x4, 0x0, 0x8, 0x0, 0x10,
    0x0, 0x20, 0x0, 0x40, 0x0,

    /* U+4EAE "亮" */
    0x2, 0x0, 0xc, 0xf, 0xff, 0x80, 0x0, 0x3f,
    0xe0, 0x80, 0x83, 0xfe, 0x0, 0x0, 0xff, 0xfa,
    0x0, 0x28, 0xf8, 0x82, 0x20, 0x8, 0x80, 0x42,
    0x3e, 0xf, 0x80,

    /* U+4EF6 "件" */
    0x8, 0x20, 0x10, 0x40, 0x26, 0x80, 0x89, 0x1,
    0x1f, 0xc6, 0x44, 0x1c, 0x88, 0x69, 0x10, 0x10,
    0x20, 0x27, 0xfc, 0x40, 0x80, 0x81, 0x1, 0x2,
    0x2, 0x4, 0x4, 0x8, 0x0,

    /* U+4FDD "保" */
    0x8, 0x0, 0x13, 0xf8, 0x64, 0x10, 0x88, 0x23,
    0x10, 0x46, 0x3f, 0x9c, 0x10, 0x68, 0x20, 0x17,
    0xfc, 0x21, 0xc0, 0x43, 0xc0, 0x8a, 0xc1, 0x24,
    0xc2, 0x88, 0x44, 0x10, 0x0,

    /* U+50A8 "储" */
    0x18, 0x40, 0x28, 0x88, 0xd7, 0xd1, 0x12, 0x46,
    0x5, 0xd, 0xff, 0xa9, 0x10, 0x12, 0x7e, 0x25,
    0x84, 0x4f, 0x8, 0x93, 0xf1, 0x34, 0x22, 0x4f,
    0xc4, 0x10, 0x80,

    /* U+50CF "像" */
    0x0, 0x80, 0x11, 0x0, 0x27, 0xc0, 0x91, 0x1,
    0x7f, 0xc6, 0x48, 0x94, 0x91, 0x69, 0xfe, 0x10,
    0x88, 0x2f, 0xa0, 0x45, 0xc0, 0xb5, 0x41, 0x12,
    0x42, 0xc4, 0x44, 0x30, 0x0,

    /* U+5173 "关" */
    0x20, 0x0, 0xc1, 0x0, 0x88, 0x0, 0x20, 0x7f,
    0xf8, 0x8, 0x0, 0x20, 0x3f, 0xfe, 0x3, 0x0,
    0x14, 0x0, 0xc8, 0x6, 0x18, 0x60, 0x3b, 0x0,
    0x20,

    /* U+5206 "分" */
    0x0, 0x40, 0x4, 0x40, 0x4, 0x20, 0x8, 0x30,
    0x18, 0x10, 0x10, 0x8, 0x6f, 0xf6, 0x42, 0x12,
    0x2, 0x10, 0x2, 0x10, 0x4, 0x10, 0x4, 0x10,
    0x8, 0x10, 0x30, 0xe0,

    /* U+5207 "切" */
    0x10, 0x0, 0x40, 0x1, 0x1f, 0xc4, 0x11, 0xfe,
    0x44, 0x41, 0x11, 0x4, 0x44, 0x11, 0x10, 0x44,
    0x4a, 0x11, 0xc8, 0x46, 0x41, 0x3, 0x4, 0x18,
    0x70, 0x80, 0x0,

    /* U+5236 "制" */
    0x8, 0x1, 0x40, 0x52, 0x2, 0xfe, 0x58, 0x82,
    0x84, 0x17, 0xfe, 0xa1, 0x5, 0x8, 0x2b, 0xf9,
    0x52, 0x4a, 0x92, 0x54, 0x90, 0xa5, 0x85, 0x20,
    0x20, 0x2,

    /* U+52A1 "务" */
    0x4, 0x0, 0x10, 0x0, 0x3f, 0x80, 0x83, 0x2,
    0x4c, 0x8, 0x70, 0x1, 0xe0, 0xe, 0x38, 0xf2,
    0x1d, 0x4, 0x0, 0xff, 0x80, 0x11, 0x0, 0x42,
    0x1, 0x84, 0xe, 0x18, 0x30, 0x40,

    /* U+52A8 "动" */
    0x0, 0x43, 0xf2, 0x0, 0x10, 0x3, 0xf0, 0x4,
    0xff, 0x24, 0x41, 0x24, 0x9, 0x28, 0x4a, 0x24,
    0x51, 0x23, 0xf7, 0x10, 0x10, 0x81, 0x18,

    /* U+5355 "单" */
    0x8, 0x20, 0x10, 0x80, 0x4, 0x7, 0xfe, 0x11,
    0x8, 0x44, 0x21, 0xff, 0x84, 0x42, 0x11, 0x8,
    0x7f, 0xe0, 0x10, 0x3f, 0xff, 0x1, 0x0, 0x4,
    0x0, 0x10, 0x0,

    /* U+53CD "反" */
    0x0, 0x18, 0x3f, 0xf8, 0x40, 0x0, 0x80, 0x1,
    0x0, 0x3, 0xff, 0x5, 0x4, 0x9, 0x8, 0x13,
    0x20, 0x23, 0xc0, 0x83, 0x1, 0xf, 0x6, 0x71,
    0xcb, 0x80, 0xc0,

    /* U+53F7 "号" */
    0x1f, 0xe0, 0x40, 0x81, 0x2, 0x4, 0x8, 0x1f,
    0xe0, 0x0, 0xf, 0xff, 0xc2, 0x0, 0x8, 0x0,
    0x3f, 0xc0, 0x1, 0x0, 0x4, 0x0, 0x20, 0xf,
    0x0,

    /* U+548C "和" */
    0x0, 0x1, 0xf8, 0x7, 0x80, 0x2, 0x3f, 0x8,
    0x87, 0xfe, 0x10, 0x88, 0x47, 0x21, 0x1e, 0x84,
    0xaa, 0x14, 0x88, 0x72, 0x21, 0x8, 0xfc, 0x22,
    0x10, 0x80, 0x0,

    /* U+5668 "器" */
    0x7c, 0xf8, 0x89, 0x11, 0x12, 0x23, 0xe7, 0xc0,
    0x10, 0x0, 0x44, 0x3f, 0xff, 0x3, 0x60, 0xf0,
    0x3c, 0xf9, 0xf1, 0x12, 0x22, 0x24, 0x47, 0xcf,
    0x88, 0x91, 0x0,

    /* U+56FE "图" */
    0xff, 0xf8, 0x81, 0x88, 0x19, 0xf9, 0x91, 0x1a,
    0xe1, 0x8f, 0x1b, 0xd, 0x86, 0x18, 0x81, 0x86,
    0x18, 0x11, 0xff, 0xf8, 0x1,

    /* U+5730 "地" */
    0x20, 0x40, 0x89, 0x2, 0x24, 0x8, 0x90, 0xfa,
    0x78, 0x9f, 0x22, 0xa4, 0x88, 0x92, 0x22, 0x48,
    0xe9, 0x6e, 0x24, 0x20, 0x81, 0x2, 0x4, 0x7,
    0xe0,

    /* U+5740 "址" */
    0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x89, 0x7,
    0xd2, 0x2, 0x27, 0x84, 0x48, 0x8, 0x90, 0x11,
    0x20, 0x22, 0x40, 0x74, 0x83, 0x89, 0x0, 0x12,
    0x1, 0xff, 0xc0,

    /* U+591C "夜" */
    0x0, 0x0, 0x8, 0x0, 0x10, 0x3f, 0xff, 0x9,
    0x80, 0x44, 0x1, 0x3f, 0x88, 0x84, 0x24, 0x91,
    0xb9, 0x8a, 0xa6, 0x8, 0x50, 0x20, 0x80, 0x8d,
    0x82, 0xe1, 0xc8, 0x0,

    /* U+5927 "大" */
    0x2, 0x0, 0x8, 0x0, 0x20, 0x0, 0x80, 0x2,
    0x3, 0xff, 0xe0, 0x20, 0x0, 0xc0, 0x5, 0x0,
    0x12, 0x0, 0x88, 0x2, 0x10, 0x10, 0x31, 0x80,
    0x6c, 0x0, 0xc0,

    /* U+5929 "天" */
    0x1f, 0xf8, 0x2, 0x0, 0x4, 0x0, 0x8, 0x0,
    0x10, 0xf, 0xff, 0x80, 0x60, 0x0, 0xc0, 0x2,
    0x40, 0x4, 0x80, 0x10, 0x80, 0x40, 0x83, 0x0,
    0xc8, 0x0, 0x80,

    /* U+5934 "头" */
    0x0, 0x80, 0x62, 0x0, 0x68, 0x0, 0x20, 0x30,
    0x80, 0x62, 0x0, 0x8, 0x0, 0x20, 0xff, 0xfc,
    0x4, 0x0, 0x24, 0x1, 0x88, 0xc, 0x1b, 0xc0,
    0x30, 0x0, 0x0,

    /* U+5B58 "存" */
    0x2, 0x0, 0x18, 0x7, 0xff, 0xc1, 0x0, 0xb,
    0xf8, 0x20, 0x61, 0x3, 0xc, 0x8, 0xd7, 0xfc,
    0x40, 0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x43,
    0x0,

    /* U+5BC6 "密" */
    0x3, 0x0, 0x3, 0x1, 0xff, 0xf2, 0x10, 0x24,
    0x16, 0x47, 0x19, 0xa, 0x65, 0x27, 0x18, 0x1f,
    0xe0, 0xc2, 0x0, 0x84, 0x21, 0x8, 0x42, 0x10,
    0x87, 0xff, 0x0,

    /* U+5BF9 "对" */
    0x0, 0x10, 0x0, 0x4f, 0xc1, 0x1, 0x4, 0x47,
    0xfd, 0x20, 0x42, 0x81, 0xe, 0x44, 0x18, 0x90,
    0x62, 0x43, 0xc1, 0x9, 0x4, 0x42, 0x12, 0x0,
    0x40, 0x7, 0x0,

    /* U+5C0F "小" */
    0x1, 0x0, 0x4, 0x0, 0x10, 0x0, 0x40, 0x11,
    0x30, 0xc4, 0x42, 0x10, 0x88, 0x42, 0x21, 0xd,
    0x4, 0x1c, 0x10, 0x40, 0x40, 0x1, 0x0, 0x1c,
    0x0,

    /* U+5C4F "屏" */
    0x3f, 0xf8, 0x80, 0x22, 0x0, 0x8f, 0xfe, 0x24,
    0x10, 0x88, 0x82, 0xff, 0xc8, 0x88, 0x22, 0x20,
    0xff, 0xf6, 0x22, 0x11, 0x8, 0xc4, 0x20, 0x60,
    0x80,

    /* U+5E55 "幕" */
    0x4, 0x40, 0xff, 0xfc, 0x11, 0x0, 0xff, 0x81,
    0x1, 0x3, 0xfe, 0x4, 0x4, 0xf, 0xf8, 0x4,
    0x0, 0xf7, 0xf8, 0xff, 0xfe, 0x88, 0x81, 0x11,
    0x2, 0x22, 0x4, 0x4c, 0x0,

    /* U+5E73 "平" */
    0x7f, 0xf8, 0x2, 0x0, 0x4, 0x1, 0x88, 0x81,
    0x13, 0x1, 0x24, 0x2, 0x50, 0x0, 0x80, 0xff,
    0xfe, 0x2, 0x0, 0x4, 0x0, 0x8, 0x0, 0x10,
    0x0, 0x20, 0x0,

    /* U+5EA6 "度" */
    0x1, 0x0, 0x1, 0x0, 0xff, 0xf1, 0x11, 0x2,
    0x22, 0x7, 0xff, 0x88, 0x88, 0x11, 0xf0, 0x20,
    0x0, 0x5f, 0xe0, 0x88, 0x81, 0xa, 0x4, 0x8,
    0x8, 0x6c, 0x27, 0x7, 0x8, 0x0,

    /* U+5F00 "开" */
    0x7f, 0xf8, 0x21, 0x0, 0x84, 0x2, 0x10, 0x8,
    0x43, 0xff, 0xf0, 0x84, 0x2, 0x10, 0x8, 0x40,
    0x41, 0x1, 0x4, 0x8, 0x10, 0xc0, 0x40,

    /* U+5F55 "录" */
    0x1f, 0xf0, 0x0, 0x20, 0x3f, 0xc0, 0x1, 0x0,
    0x2, 0x1f, 0xff, 0x80, 0x40, 0x18, 0x8c, 0x19,
    0xb0, 0xe, 0x80, 0x25, 0x81, 0x88, 0x84, 0x10,
    0xc0, 0xe0, 0x0,

    /* U+6253 "打" */
    0x10, 0x0, 0x24, 0x4, 0x47, 0xf7, 0xe0, 0x81,
    0x1, 0x2, 0x2, 0x5, 0x4, 0xc, 0x8, 0xf0,
    0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x81, 0x1,
    0x6, 0xe, 0x0,

    /* U+6362 "换" */
    0x21, 0x0, 0x84, 0x2, 0x3e, 0x8, 0x88, 0xf4,
    0x40, 0x9f, 0xe2, 0x48, 0x8d, 0x22, 0xe4, 0x88,
    0xbf, 0xf2, 0x1c, 0x8, 0x50, 0x22, 0x20, 0x98,
    0x47, 0x80, 0xc0,

    /* U+6444 "摄" */
    0x10, 0x0, 0x23, 0xf8, 0x42, 0x20, 0x87, 0xc7,
    0xc8, 0x82, 0x1f, 0x4, 0x22, 0xc, 0xff, 0x18,
    0x9, 0xe7, 0xf8, 0x41, 0x90, 0x8c, 0xc1, 0xd,
    0x82, 0x2b, 0x8d, 0x99, 0x80,

    /* U+6548 "效" */
    0x0, 0x20, 0x30, 0xc0, 0x31, 0x3, 0xfa, 0x0,
    0xf, 0xe0, 0x11, 0xd, 0xa2, 0x11, 0xa4, 0x41,
    0x48, 0x68, 0xa0, 0x70, 0xc0, 0x61, 0x81, 0x63,
    0x86, 0x49, 0x98, 0x60, 0x80, 0x80,

    /* U+654F "敏" */
    0x20, 0x40, 0x81, 0x7, 0xec, 0x20, 0x3f, 0xfd,
    0x11, 0x1c, 0x45, 0x49, 0x3f, 0xe4, 0x44, 0x51,
    0x51, 0x84, 0x42, 0x1f, 0x9c, 0x4, 0x98, 0x6c,
    0x30, 0x20, 0x0,

    /* U+6570 "数" */
    0x8, 0x20, 0x92, 0x40, 0xa9, 0x0, 0x42, 0x7,
    0xf7, 0xe3, 0x91, 0xa, 0xa2, 0x64, 0x24, 0x18,
    0x49, 0xfc, 0x60, 0x88, 0xc1, 0x31, 0x81, 0xc6,
    0x83, 0x59, 0x98, 0x40, 0x80,

    /* U+6587 "文" */
    0x6, 0x0, 0xc, 0x0, 0x10, 0x3f, 0xff, 0x10,
    0x60, 0x61, 0x0, 0x84, 0x3, 0x20, 0x4, 0x80,
    0xc, 0x0, 0x30, 0x1, 0x30, 0x18, 0x33, 0x80,
    0x30, 0x0, 0x0,

    /* U+65E0 "无" */
    0x3f, 0xf8, 0x8, 0x0, 0x20, 0x0, 0x80, 0xff,
    0xfc, 0x1c, 0x0, 0x50, 0x1, 0x40, 0x9, 0x0,
    0x24, 0x1, 0x10, 0x48, 0x43, 0xc0, 0xf8,

    /* U+65E5 "日" */
    0xff, 0xe0, 0x18, 0x6, 0x1, 0x80, 0x7f, 0xf8,
    0x6, 0x1, 0x80, 0x60, 0x1f, 0xfe, 0x1, 0x80,
    0x0,

    /* U+65F6 "时" */
    0x0, 0x0, 0x1, 0x3e, 0x9, 0x10, 0x48, 0x82,
    0x47, 0xfe, 0x20, 0x9f, 0x44, 0x8b, 0x24, 0x49,
    0x22, 0x49, 0x10, 0x4f, 0x82, 0x44, 0x10, 0x3,
    0x80, 0x0,

    /* U+665A "晚" */
    0x1, 0x0, 0x4, 0xf, 0x3f, 0x25, 0x88, 0x94,
    0x62, 0x5f, 0xef, 0x48, 0xa5, 0x22, 0x97, 0xfa,
    0x43, 0xf, 0x1c, 0x24, 0x70, 0x82, 0xc4, 0x13,
    0x11, 0x87, 0x80,

    /* U+6700 "最" */
    0x1f, 0xf0, 0x40, 0x41, 0xff, 0x4, 0x4, 0xf,
    0xe3, 0xff, 0xf2, 0x20, 0xf, 0xfe, 0x22, 0x88,
    0xf9, 0x42, 0x26, 0xf, 0xd8, 0x42, 0xd8, 0x8,
    0x10,

    /* U+6708 "月" */
    0x1f, 0xf1, 0x1, 0x10, 0x11, 0x1, 0x1f, 0xf1,
    0x1, 0x10, 0x11, 0x1, 0x1f, 0xf1, 0x1, 0x30,
    0x12, 0x1, 0x60, 0x1c, 0x6,

    /* U+670D "服" */
    0x3e, 0xfc, 0x22, 0x84, 0x22, 0x84, 0x22, 0x84,
    0x3e, 0x98, 0x22, 0x80, 0x22, 0xfc, 0x22, 0xc4,
    0x3e, 0xa4, 0x22, 0xa8, 0x22, 0x98, 0x62, 0x98,
    0x42, 0xa7, 0x4c, 0xc0,

    /* U+679C "果" */
    0x3f, 0xf0, 0x42, 0x20, 0x84, 0x41, 0xff, 0x82,
    0x11, 0x4, 0x22, 0xf, 0xfc, 0x0, 0x80, 0xff,
    0xfc, 0x7, 0x0, 0x35, 0x0, 0x89, 0x8e, 0x10,
    0xe0, 0x20, 0x0,

    /* U+68C0 "检" */
    0x10, 0x20, 0x20, 0xc0, 0x41, 0x80, 0x84, 0x87,
    0xc9, 0x82, 0x21, 0x8c, 0x81, 0x9d, 0xfc, 0x3c,
    0x0, 0xa0, 0x8b, 0x45, 0x20, 0x89, 0x41, 0x1,
    0x2, 0x2, 0x4, 0xff, 0x80,

    /* U+6B21 "次" */
    0x1, 0x0, 0x4, 0x4, 0x20, 0x8, 0xff, 0x12,
    0x8, 0x13, 0x20, 0x48, 0x0, 0x20, 0x18, 0x80,
    0xc3, 0x6, 0x16, 0x30, 0xc8, 0x6, 0x10, 0x30,
    0x31, 0x0, 0x0,

    /* U+6B8A "殊" */
    0x0, 0x41, 0xfa, 0x80, 0x85, 0x1, 0xf, 0xc3,
    0xa4, 0x5, 0x8, 0x12, 0xff, 0x64, 0x20, 0xb8,
    0xe0, 0x32, 0xa0, 0x45, 0x61, 0x12, 0x66, 0xc4,
    0x58, 0x8, 0x0, 0x10, 0x0,

    /* U+6BD4 "比" */
    0x1, 0x1, 0x4, 0x4, 0x10, 0x10, 0x44, 0x41,
    0x31, 0xf7, 0x4, 0x10, 0x10, 0x40, 0x41, 0x1,
    0x4, 0x4, 0x50, 0x93, 0x43, 0x71, 0x9, 0x7,
    0xc0,

    /* U+6C34 "水" */
    0x1, 0x0, 0x2, 0x0, 0x4, 0x0, 0x8, 0x67,
    0xd3, 0x0, 0xbc, 0x2, 0x60, 0x4, 0xa0, 0x9,
    0x40, 0x22, 0x40, 0x84, 0x43, 0x8, 0xcc, 0x10,
    0x40, 0x20, 0x1, 0xc0, 0x0,

    /* U+6D4B "测" */
    0x40, 0x9, 0x7c, 0x42, 0x2a, 0x11, 0x58, 0xaa,
    0xe5, 0x54, 0xaa, 0xa1, 0x55, 0x2a, 0xa9, 0x55,
    0x51, 0x4a, 0x89, 0x19, 0x84, 0xc8, 0x1c,

    /* U+7070 "灰" */
    0x8, 0x0, 0x10, 0x0, 0x20, 0x7, 0xff, 0xe0,
    0x80, 0x1, 0x10, 0x2, 0x20, 0x6, 0x48, 0x14,
    0x90, 0x29, 0x40, 0x43, 0x1, 0xa, 0x6, 0x32,
    0x18, 0xc3, 0x2e, 0x3, 0x0, 0x0,

    /* U+7075 "灵" */
    0x7f, 0xf0, 0x0, 0x43, 0xff, 0x0, 0x4, 0x7f,
    0xf0, 0xc, 0x1, 0x21, 0x8, 0x88, 0x27, 0x60,
    0x96, 0x0, 0x8c, 0xc, 0x1c, 0xe0, 0x1c,

    /* U+70B9 "点" */
    0x2, 0x0, 0x8, 0x0, 0x3f, 0x80, 0x80, 0x2,
    0x0, 0xff, 0x82, 0x2, 0x8, 0x8, 0x3f, 0xe0,
    0x0, 0x2, 0x13, 0x11, 0x26, 0xc4, 0x8a, 0x10,
    0x10,

    /* U+70ED "热" */
    0x10, 0x80, 0x21, 0x0, 0x42, 0x7, 0xff, 0x81,
    0x9, 0x2, 0x92, 0xe, 0x44, 0x68, 0xc8, 0x11,
    0x16, 0x24, 0x18, 0xd0, 0x0, 0x4, 0x82, 0x49,
    0x88, 0x91, 0x21, 0x0, 0x0,

    /* U+7184 "熄" */
    0x10, 0x40, 0x42, 0x1, 0x3f, 0x85, 0x82, 0x56,
    0x9, 0x6f, 0xe5, 0x20, 0xa4, 0xfe, 0x12, 0x8,
    0x4f, 0xe1, 0x80, 0xb, 0x5a, 0x25, 0x5, 0x24,
    0x5c, 0x1e, 0x0,

    /* U+7279 "特" */
    0x10, 0x40, 0x41, 0x5, 0x3f, 0x94, 0x10, 0xb8,
    0x42, 0x5f, 0xf9, 0x1, 0x6, 0x4, 0x1b, 0xff,
    0xc0, 0x41, 0x11, 0x4, 0x24, 0x10, 0x10, 0x41,
    0xc0,

    /* U+7387 "率" */
    0x4, 0x0, 0x8, 0xf, 0xff, 0x80, 0x84, 0xc5,
    0x91, 0xbc, 0x80, 0x20, 0x9, 0x28, 0x4f, 0xd3,
    0x1, 0x20, 0x20, 0x3f, 0xff, 0x2, 0x0, 0x8,
    0x0, 0x20, 0x0,

    /* U+7801 "码" */
    0x1, 0xfc, 0xfc, 0x10, 0x22, 0x20, 0x84, 0x41,
    0x8, 0x83, 0xd1, 0x8, 0xa2, 0x31, 0x7f, 0x62,
    0x2, 0x44, 0x4, 0x8f, 0xe8, 0xf0, 0x12, 0x20,
    0x46, 0x3, 0x80, 0x0, 0x0,

    /* U+7BB1 "箱" */
    0x20, 0x40, 0xff, 0xf4, 0x9b, 0x20, 0x40, 0x11,
    0xf8, 0x44, 0x2f, 0xd0, 0x84, 0x7e, 0x39, 0x9,
    0x57, 0xe5, 0x10, 0xa4, 0x42, 0x11, 0xf8, 0x44,
    0x20,

    /* U+7EA2 "红" */
    0x30, 0x0, 0x8f, 0xe4, 0xc4, 0x12, 0x10, 0x88,
    0x43, 0xc1, 0x1, 0x4, 0x8, 0x10, 0x44, 0x43,
    0xe1, 0x0, 0x4, 0x1, 0x10, 0xf8, 0x42, 0x1f,
    0xf0,

    /* U+7EDC "络" */
    0x10, 0x80, 0x41, 0x0, 0x87, 0xe2, 0x48, 0x84,
    0xa9, 0x1f, 0xc, 0x4, 0x18, 0x10, 0xcc, 0x27,
    0x4, 0xb3, 0xf3, 0x84, 0x20, 0x8, 0x41, 0x90,
    0x9c, 0x3f, 0x0, 0x42, 0x0,

    /* U+7EFF "绿" */
    0x13, 0xf0, 0x80, 0x42, 0x1, 0x13, 0xfc, 0x88,
    0x13, 0xdf, 0xf2, 0x4, 0x8, 0x96, 0xf9, 0x60,
    0x1, 0x80, 0x9d, 0x3d, 0x93, 0x0, 0x44, 0x7,
    0x0,

    /* U+7F51 "网" */
    0xff, 0xf8, 0x1, 0x80, 0x1a, 0xa5, 0xa9, 0x59,
    0x99, 0x90, 0x99, 0x89, 0x99, 0x5a, 0x55, 0xe2,
    0x58, 0x1, 0x80, 0x18, 0x6,

    /* U+7FFB "翻" */
    0x6, 0x0, 0xf1, 0xdc, 0xa8, 0x88, 0xe1, 0x1f,
    0xea, 0xa3, 0x95, 0x4a, 0x88, 0xb4, 0x93, 0x7e,
    0x6a, 0x55, 0x74, 0xf8, 0x89, 0x51, 0x12, 0xa2,
    0x27, 0xdd, 0xc0,

    /* U+8272 "色" */
    0x4, 0x0, 0x10, 0x0, 0xfe, 0x4, 0x10, 0x60,
    0x42, 0xff, 0xc2, 0x11, 0x8, 0x44, 0x21, 0x10,
    0xff, 0xc2, 0x0, 0x8, 0x0, 0x20, 0x4, 0x80,
    0x13, 0xff, 0x80,

    /* U+84DD "蓝" */
    0x0, 0x40, 0x8, 0x83, 0xff, 0xf8, 0x22, 0x0,
    0x8, 0x6, 0x50, 0x8, 0xbe, 0x11, 0x90, 0x22,
    0x30, 0x4, 0x0, 0xff, 0xe1, 0x14, 0x42, 0x28,
    0x84, 0x51, 0x3f, 0xff, 0x80,

    /* U+85CF "藏" */
    0x4, 0x0, 0x8, 0x81, 0xff, 0xf0, 0x22, 0x0,
    0x2, 0x8b, 0xff, 0x14, 0x8, 0x3b, 0xf4, 0x15,
    0x28, 0x2f, 0xd1, 0xd1, 0x42, 0xbe, 0x85, 0x51,
    0x12, 0xf5, 0x48, 0x31, 0x0,

    /* U+8D26 "账" */
    0x0, 0x80, 0xf9, 0x11, 0x12, 0x22, 0xa4, 0x85,
    0x4b, 0xa, 0x94, 0x15, 0x20, 0x2a, 0xff, 0x54,
    0xa0, 0xa9, 0x21, 0x52, 0x41, 0x44, 0x42, 0x4a,
    0xc8, 0xd8, 0x60, 0x20, 0x0,

    /* U+8F6C "转" */
    0x10, 0x60, 0x41, 0x2, 0x4, 0x3f, 0x7e, 0x20,
    0x41, 0x42, 0x5, 0x3f, 0xd4, 0x20, 0xfc, 0x80,
    0x47, 0xe1, 0x21, 0x7, 0x4, 0xf0, 0xe0, 0x40,
    0x81, 0x1, 0x0,

    /* U+8FA8 "辨" */
    0x0, 0x0, 0x84, 0x80, 0x10, 0x3f, 0x5f, 0x9,
    0x49, 0x4d, 0x25, 0x51, 0x3f, 0x5f, 0x21, 0x10,
    0x84, 0x4f, 0x97, 0xc8, 0x84, 0x22, 0x11, 0x10,
    0x4c, 0x81, 0x0,

    /* U+8FD0 "运" */
    0x40, 0x1, 0x9f, 0xe2, 0x0, 0x4, 0x0, 0x0,
    0x0, 0x3f, 0xfe, 0x18, 0x8, 0x40, 0x22, 0x20,
    0x88, 0x42, 0x47, 0x8b, 0xe2, 0xf8, 0x2, 0x1f,
    0xf0,

    /* U+90AE "邮" */
    0x10, 0x0, 0x87, 0xc4, 0x25, 0xfd, 0x29, 0x2a,
    0x49, 0x52, 0x4a, 0x9f, 0xd2, 0x92, 0x8c, 0x94,
    0x64, 0xa3, 0x25, 0x1f, 0xeb, 0x41, 0x40, 0x2,
    0x0,

    /* U+91CF "量" */
    0x3f, 0xf0, 0x80, 0x43, 0xff, 0x8, 0x4, 0x1f,
    0xe3, 0xff, 0xf0, 0x0, 0xf, 0xfc, 0x3f, 0xf0,
    0x84, 0x41, 0xfe, 0x1f, 0xfe, 0x1, 0x3, 0xff,
    0xf0,

    /* U+955C "镜" */
    0x10, 0x40, 0x20, 0x40, 0x8f, 0xf1, 0xe4, 0x44,
    0xd, 0x18, 0x7f, 0xde, 0x0, 0x28, 0xfe, 0x11,
    0x4, 0xfb, 0xf8, 0x47, 0xf0, 0x84, 0x81, 0x49,
    0x23, 0x12, 0x44, 0xc7, 0x80, 0x0,

    /* U+95ED "闭" */
    0x40, 0x2, 0xff, 0x20, 0x18, 0x11, 0x81, 0x1b,
    0xfd, 0x87, 0x18, 0x51, 0x8d, 0x19, 0x91, 0xb1,
    0x1a, 0x11, 0x86, 0x18, 0x7,

    /* U+95F4 "间" */
    0xc0, 0x2, 0x7f, 0x20, 0x18, 0x1, 0x9f, 0x99,
    0x9, 0x90, 0x99, 0xf9, 0x90, 0x99, 0x9, 0x9f,
    0x98, 0x1, 0x80, 0x18, 0x2,

    /* U+9650 "限" */
    0xfb, 0xf2, 0x28, 0x49, 0x21, 0x28, 0xfc, 0xa2,
    0x12, 0x4f, 0xc8, 0xa8, 0xa2, 0x96, 0x9a, 0x62,
    0x88, 0x88, 0x2a, 0x20, 0xc6, 0x82, 0x8,

    /* U+9971 "饱" */
    0x21, 0x80, 0x84, 0x4, 0x1f, 0x9e, 0x82, 0x9f,
    0xe8, 0x84, 0xa2, 0x12, 0x88, 0x4a, 0x21, 0xe8,
    0x84, 0x62, 0x10, 0xa, 0x41, 0x31, 0x4, 0x87,
    0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 135, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 11, .adv_w = 135, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 20, .adv_w = 135, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 31, .adv_w = 135, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 42, .adv_w = 135, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 53, .adv_w = 135, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 64, .adv_w = 122, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 73, .adv_w = 222, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 90, .adv_w = 141, .box_w = 7, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 101, .adv_w = 132, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 112, .adv_w = 133, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 124, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 153, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 180, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 209, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 238, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 265, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 294, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 319, .adv_w = 256, .box_w = 16, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 347, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 374, .adv_w = 256, .box_w = 13, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 400, .adv_w = 256, .box_w = 15, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 430, .adv_w = 256, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 453, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 480, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 507, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 532, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 559, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 586, .adv_w = 256, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 607, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 632, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 659, .adv_w = 256, .box_w = 14, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 687, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 714, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 741, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 768, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 793, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 820, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 847, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 872, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 897, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 926, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 953, .adv_w = 256, .box_w = 15, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 983, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1006, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1033, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1060, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1087, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1116, .adv_w = 256, .box_w = 15, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1146, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1173, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1202, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1229, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1252, .adv_w = 256, .box_w = 10, .box_h = 13, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 1269, .adv_w = 256, .box_w = 13, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1295, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1322, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1347, .adv_w = 256, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1368, .adv_w = 256, .box_w = 16, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1396, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1423, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1452, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1479, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1508, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1533, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1562, .adv_w = 256, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1585, .adv_w = 256, .box_w = 15, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1615, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1638, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1663, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1692, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1719, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1744, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1771, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1800, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1825, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1850, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1879, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1904, .adv_w = 256, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1925, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1952, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1979, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2008, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2037, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2066, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2093, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2120, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2145, .adv_w = 256, .box_w = 13, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2170, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2195, .adv_w = 256, .box_w = 15, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 2225, .adv_w = 256, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 2246, .adv_w = 256, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 2267, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2290, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x1, 0x2, 0x3, 0x5, 0x7, 0x16, 0x1d,
    0x20, 0x23, 0x24, 0x4dfa, 0x4e7e, 0x4ec6, 0x4fad, 0x5078,
    0x509f, 0x5143, 0x51d6, 0x51d7, 0x5206, 0x5271, 0x5278, 0x5325,
    0x539d, 0x53c7, 0x545c, 0x5638, 0x56ce, 0x5700, 0x5710, 0x58ec,
    0x58f7, 0x58f9, 0x5904, 0x5b28, 0x5b96, 0x5bc9, 0x5bdf, 0x5c1f,
    0x5e25, 0x5e43, 0x5e76, 0x5ed0, 0x5f25, 0x6223, 0x6332, 0x6414,
    0x6518, 0x651f, 0x6540, 0x6557, 0x65b0, 0x65b5, 0x65c6, 0x662a,
    0x66d0, 0x66d8, 0x66dd, 0x676c, 0x6890, 0x6af1, 0x6b5a, 0x6ba4,
    0x6c04, 0x6d1b, 0x7040, 0x7045, 0x7089, 0x70bd, 0x7154, 0x7249,
    0x7357, 0x77d1, 0x7b81, 0x7e72, 0x7eac, 0x7ecf, 0x7f21, 0x7fcb,
    0x8242, 0x84ad, 0x859f, 0x8cf6, 0x8f3c, 0x8f78, 0x8fa0, 0x907e,
    0x919f, 0x952c, 0x95bd, 0x95c4, 0x9620, 0x9941
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 39234, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 94, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Font4 = {
#else
lv_font_t ui_font_Font4 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT4*/

