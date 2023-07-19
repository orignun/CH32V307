/**
 * @file lv_port_fs_templ.c
 *
 */

/*Copy this file as "lv_port_fs.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_fs_template.h"
#include "../../lvgl.h"
#include "usart.h"
#include "debug.h"
#include "tim.h"
#include "file.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void fs_init(void);

static void * fs_open(lv_fs_drv_t * drv, const char * path, lv_fs_mode_t mode);
static lv_fs_res_t fs_close(lv_fs_drv_t * drv, void * file_p);
static lv_fs_res_t fs_read(lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br);
static lv_fs_res_t fs_write(lv_fs_drv_t * drv, void * file_p, const void * buf, uint32_t btw, uint32_t * bw);
static lv_fs_res_t fs_seek(lv_fs_drv_t * drv, void * file_p, uint32_t pos, lv_fs_whence_t whence);
static lv_fs_res_t fs_size(lv_fs_drv_t * drv, void * file_p, uint32_t * size_p);
static lv_fs_res_t fs_tell(lv_fs_drv_t * drv, void * file_p, uint32_t * pos_p);

static void * fs_dir_open(lv_fs_drv_t * drv, const char * path);
static lv_fs_res_t fs_dir_read(lv_fs_drv_t * drv, void * rddir_p, char * fn);
static lv_fs_res_t fs_dir_close(lv_fs_drv_t * drv, void * rddir_p);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_fs_init(void)
{
    /*----------------------------------------------------
     * Initialize your storage device and File System
     * -------------------------------------------------*/
    fs_init();

    /*---------------------------------------------------
     * Register the file system interface in LVGL
     *--------------------------------------------------*/

    /*Add a simple drive to open images*/
    static lv_fs_drv_t fs_drv;
    lv_fs_drv_init(&fs_drv);

    /*Set up fields...*/
    fs_drv.cache_size = 9600;
    fs_drv.letter = 'D';
    fs_drv.open_cb = fs_open;
    fs_drv.close_cb = fs_close;
    fs_drv.read_cb = fs_read;
    fs_drv.write_cb = fs_write;
    fs_drv.seek_cb = fs_seek;
    fs_drv.tell_cb = fs_tell;

    fs_drv.dir_close_cb = fs_dir_close;
    fs_drv.dir_open_cb = fs_dir_open;
    fs_drv.dir_read_cb = fs_dir_read;

    lv_fs_drv_register(&fs_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your Storage device and File system.*/
static void fs_init(void)
{
    /*E.g. for FatFS initialize the SD card and FatFS itself*/

    /*You code here*/
}

/**
 * Open a file
 * @param drv       pointer to a driver where this function belongs
 * @param path      path to the file beginning with the driver letter (e.g. S:/folder/file.txt)
 * @param mode      read: FS_MODE_RD, write: FS_MODE_WR, both: FS_MODE_RD | FS_MODE_WR
 * @return          a file descriptor or NULL on error
 */
static void * fs_open(lv_fs_drv_t * drv, const char * path, lv_fs_mode_t mode)
{
    lv_fs_res_t res = LV_FS_RES_OK;

//    if(mode == LV_FS_MODE_WR) {
        /*Open a file for write*/
//        f = ...         /*Add your code here*/
//    }
//    else if(mode == LV_FS_MODE_RD) {
        /*Open a file for read*/
//        f = ...         /*Add your code here*/
//    }
//    else if(mode == (LV_FS_MODE_WR | LV_FS_MODE_RD)) {
        /*Open a file for read and write*/
//        f = ...         /*Add your code here*/
//    }
//    printf("open\n");

    _file_obj * f ;
    if(strstr(path,"bin"))
    {


        if(strstr(path,"11.bin")) f = &img11_bin;
        else if(strstr(path,"12.bin")) f = &img12_bin;
        else if(strstr(path,"13.bin")) f = &img13_bin;
        else if(strstr(path,"14.bin")) f = &img14_bin;
        else if(strstr(path,"15.bin")) f = &img15_bin;
        else if(strstr(path,"16.bin")) f = &img16_bin;

        else if(strstr(path,"bj.bin")) f = &imgbj_bin;

        else if(strstr(path,"31.bin")) f = &img31_bin;
        else if(strstr(path,"32.bin")) f = &img32_bin;

        else if(strstr(path,"2.bin")) f = &img2_bin;
        else if(strstr(path,"3.bin")) f = &img3_bin;
        else if(strstr(path,"4.bin")) f = &img4_bin;
        else if(strstr(path,"5.bin")) f = &img5_bin;
        else if(strstr(path,"6.bin")) f = &img6_bin;





    }

    f->pointer = 0;
    return f;
}

/**
 * Close an opened file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable. (opened with fs_open)
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_close(lv_fs_drv_t * drv, void * file_p)
{
    lv_fs_res_t res = LV_FS_RES_OK;
    /*Add your code here*/

    return res;
}

/**
 * Read data from an opened file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable.
 * @param buf       pointer to a memory block where to store the read data
 * @param btr       number of Bytes To Read
 * @param br        the real number of read bytes (Byte Read)
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
extern const uint8_t img22_bin[];
extern const uint8_t img23_bin[];
extern const uint8_t img24_bin[];
extern const uint8_t img25_bin[];
extern const uint8_t img26_bin[];
extern const uint8_t imgs31_bin[];
extern const uint8_t imgs32_bin[];

extern const uint8_t img11s_bin[];
extern const uint8_t img12s_bin[];
extern const uint8_t img13s_bin[];


static lv_fs_res_t fs_read(lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br)
{
    lv_fs_res_t res = LV_FS_RES_OK;

    _file_obj * f = (_file_obj *)file_p;

    int now = SysTickCnt;
    char cache[128];
    if(btr+f->pointer>f->pointer_max)
        btr=f->pointer_max-f->pointer;

    if(f == &img2_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(img22_bin+f->pointer)[i];
    else if(f == &img3_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(img23_bin+f->pointer)[i];
    else if(f == &img4_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(img24_bin+f->pointer)[i];
    else if(f == &img5_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(img25_bin+f->pointer)[i];
    else if(f == &img6_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(img26_bin+f->pointer)[i];
    else if(f == &img31_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(imgs31_bin+f->pointer)[i];
    else if(f == &img32_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(imgs32_bin+f->pointer)[i];
    else if(f == &img11_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(img11s_bin+f->pointer)[i];
    else if(f == &img12_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(img12s_bin+f->pointer)[i];
    else if(f == &img13_bin)
        for(int i=0;i<btr;i++)
            ((uint8_t *)buf)[i]=(img13s_bin+f->pointer)[i];
    else {
        if(f->pointer == 0)
        {
            if(f == &imgbj_bin)
                {((uint16_t *)buf)[0] = 0xc004;((uint16_t *)buf)[1] = 0x10e3;}
            else
                {((uint16_t *)buf)[0] = 0xc805;((uint16_t *)buf)[1] = 0x0600;}
        }

        else {
            sprintf(cache,"img?%s,%d,%d",f->name,f->pointer,btr);
            DMA_Rx_Init(DMA1_Channel2, (u32)&SPI1->DATAR, buf, btr);
            DMA_Cmd( DMA1_Channel2, ENABLE );
            send(cache);
            while(!DMA_GetFlagStatus(DMA1_FLAG_TC2)){}DMA_ClearFlag(DMA1_FLAG_TC2);
        }

    }
//    printf("time:%d,%d,%d\n",SysTickCnt-now,f->pointer,btr);
    f->pointer+=btr;
    *br=btr;

//    while(usart_receive_complete!=1);
//    Delay_Ms(5);
//    usart_receive_complete=0;


//    printf("time:%d,len:%d\n",SysTickCnt-now,btr);

//    uint16_t *buff = buf;
//    printf("pointer:%d\n",pointer);
//    printf("buf:%d,%d\n",((uint16_t *)buf)[0],((uint16_t *)buf)[1]);
//    printf("%d,%d,%d,%d\n",file_pointer[0],file_pointer[1],file_pointer[2],file_pointer[3]);
    return res;
}

/**
 * Write into a file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable
 * @param buf       pointer to a buffer with the bytes to write
 * @param btw       Bytes To Write
 * @param bw        the number of real written bytes (Bytes Written). NULL if unused.
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_write(lv_fs_drv_t * drv, void * file_p, const void * buf, uint32_t btw, uint32_t * bw)
{
    lv_fs_res_t res = LV_FS_RES_OK;


    printf("write\n");
    /*Add your code here*/

    return res;
}

/**
 * Set the read write pointer. Also expand the file size if necessary.
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable. (opened with fs_open )
 * @param pos       the new position of read write pointer
 * @param whence    tells from where to interpret the `pos`. See @lv_fs_whence_t
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_seek(lv_fs_drv_t * drv, void * file_p, uint32_t pos, lv_fs_whence_t whence)
{
    lv_fs_res_t res = LV_FS_RES_OK;
    _file_obj * f = (_file_obj *)file_p;
    switch(whence)
    {
    case LV_FS_SEEK_SET:f->pointer=0;break;
    case LV_FS_SEEK_CUR:break;
    case LV_FS_SEEK_END:f->pointer=f->pointer_max;break;
    }
    f->pointer += pos;
//    printf("seek\n");
    /*Add your code here*/

    return res;
}
/**
 * Give the position of the read write pointer
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable.
 * @param pos_p     pointer to to store the result
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_tell(lv_fs_drv_t * drv, void * file_p, uint32_t * pos_p)
{
    _file_obj * f = (_file_obj *)file_p;
    lv_fs_res_t res = LV_FS_RES_OK;
    *pos_p = f->pointer;
    /*Add your code here*/

    return res;
}

extern char esp32_value[64];
/**
 * Initialize a 'lv_fs_dir_t' variable for directory reading
 * @param drv       pointer to a driver where this function belongs
 * @param path      path to a directory
 * @return          pointer to the directory read descriptor or NULL on error
 */
static void * fs_dir_open(lv_fs_drv_t * drv, const char * path)
{
//   void * dir = NULL;
    /*Add your code here*/
//    dir = ...           /*Add your code here*/
//          return dir;
    char buf[64];
    sprintf(buf,"opendir?%s",path);
    usart_receive_complete = 0;
    send(buf);
    while(usart_receive_complete == 0);

    if(atoi(esp32_value))return LV_FS_RES_UNKNOWN;
    else return LV_FS_RES_UNKNOWN;

}

/**
 * Read the next filename form a directory.
 * The name of the directories will begin with '/'
 * @param drv       pointer to a driver where this function belongs
 * @param rddir_p   pointer to an initialized 'lv_fs_dir_t' variable
 * @param fn        pointer to a buffer to store the filename
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_dir_read(lv_fs_drv_t * drv, void * rddir_p, char * fn)
{
    lv_fs_res_t res = LV_FS_RES_OK;

    char buf[64];
    sprintf(buf,"readdir?1");
    usart_receive_complete = 0;
    send(buf);
    while(usart_receive_complete == 0);

    strcpy(fn,esp32_value);

    if(strstr(esp32_value,"error"))return LV_FS_RES_UNKNOWN;
    else return res;
    /*Add your code here*/


}

/**
 * Close the directory reading
 * @param drv       pointer to a driver where this function belongs
 * @param rddir_p   pointer to an initialized 'lv_fs_dir_t' variable
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_dir_close(lv_fs_drv_t * drv, void * rddir_p)
{
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;

    /*Add your code here*/
    send("closedir?1");

    return res;
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
