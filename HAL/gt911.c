/*
 * gt911.c
 *
 *  Created on: 2023年6月30日
 *      Author: zhengshengbing
 */

#include "gt911.h"
#include "i2c.h"



//GT911（原GT9147）配置参数表
//第一个字节为版本号(0X60),必须保证新的版本号大于等于GT911内部
//flash原有版本号,才会更新配置.
const uint8_t GT9147_CFG_TBL[]=
{
    0X60,0XE0,0X01,0X20,0X03,0X05,0X35,0X00,0X02,0X08,
    0X1E,0X08,0X50,0X3C,0X0F,0X05,0X00,0X00,0XFF,0X67,
    0X50,0X00,0X00,0X18,0X1A,0X1E,0X14,0X89,0X28,0X0A,
    0X30,0X2E,0XBB,0X0A,0X03,0X00,0X00,0X02,0X33,0X1D,
    0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X32,0X00,0X00,
    0X2A,0X1C,0X5A,0X94,0XC5,0X02,0X07,0X00,0X00,0X00,
    0XB5,0X1F,0X00,0X90,0X28,0X00,0X77,0X32,0X00,0X62,
    0X3F,0X00,0X52,0X50,0X00,0X52,0X00,0X00,0X00,0X00,
    0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
    0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,
    0X0F,0X03,0X06,0X10,0X42,0XF8,0X0F,0X14,0X00,0X00,
    0X00,0X00,0X1A,0X18,0X16,0X14,0X12,0X10,0X0E,0X0C,
    0X0A,0X08,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
    0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
    0X00,0X00,0X29,0X28,0X24,0X22,0X20,0X1F,0X1E,0X1D,
    0X0E,0X0C,0X0A,0X08,0X06,0X05,0X04,0X02,0X00,0XFF,
    0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
    0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
    0XFF,0XFF,0XFF,0XFF
};

/*创建触摸结构体*/
Touch_Struct    User_Touch;


void GT911_WriteReg(uint16_t _usRegAddr, uint8_t *_pRegBuf, uint8_t _ucLen)
{
    AT24CXX_WriteOneByte(_usRegAddr, _pRegBuf, _ucLen);
//    HAL_I2C_Mem_Write(&GT911_I2C, GT911_DIV_W, _usRegAddr, I2C_MEMADD_SIZE_16BIT, _pRegBuf, _ucLen, 0xff);
}
void GT911_ReadReg(uint16_t _usRegAddr, uint8_t *_pRegBuf, uint8_t _ucLen)
{
    AT24CXX_ReadOneByte(_usRegAddr, _pRegBuf, _ucLen);
//    HAL_I2C_Mem_Read(&GT911_I2C, GT911_DIV_R, _usRegAddr, I2C_MEMADD_SIZE_16BIT, _pRegBuf, _ucLen, 0xff);
}


/*
    配置gt911，发送gt911配置参数
    参数1：mode（0,参数不保存到flash1,参数保存到flash）
*/
void GT911_Send_Config(uint8_t mode)
{
    uint8_t buf[2];

    buf[0] = 0;
    buf[1] = mode;  //是否写入到GT9147 FLASH?  即是否掉电保存
    for(uint8_t i=0; i<sizeof(GT9147_CFG_TBL); i++)
    {
        buf[0] += GT9147_CFG_TBL[i];//计算校验和
    }
  buf[0]=(~buf[0])+1;

    GT911_WriteReg(GT_CFGS_REG, (uint8_t *)GT9147_CFG_TBL, sizeof(GT9147_CFG_TBL));//发送寄存器配置

    GT911_WriteReg(GT_CHECK_REG, buf, 2);//写入校验和,和配置更新标记
}


/*
    功能：软件复位gt911
    参数1：gt_SR_type（为1时开始软件复位,为0时结束软件复位）
*/
void Software_Reset(uint8_t gt_SR_type)
{
    uint8_t _temp=0;    //中间变量
    if(gt_SR_type)
    {
        _temp=2;
        GT911_WriteReg(GT_CTRL_REG, &_temp, 1);
    }
    else
    {
        _temp=0;
        GT911_WriteReg(GT_CTRL_REG, &_temp, 1);
    }
}

/*
    功能：gt911触摸扫描，判断当前是否被触摸
    参数1：
*/
void gt911_Scanf(void)
{
//    static uint8_t timer_=0;
//    timer_++;
//    if(timer_<10)       //防止短时间多次进入判断
//    {
//        return;
//    }
//    timer_=0;

    uint8_t _temp;  //中间变量

    GT911_ReadReg(GT_GSTID_REG, &_temp, 1);//读0x814E寄存器

    User_Touch.Touch_State = _temp;

    User_Touch.Touch_Number = (User_Touch.Touch_State & 0x0f);  //获取触摸点数
    User_Touch.Touch_State = (User_Touch.Touch_State & 0x80);   //触摸状态

    switch(User_Touch.Touch_State)  //判断是否有触摸数据
    {
        case TOUCH__NO:     //没有数据

        break;
        case TOUCH_ING:     //触摸中~后，有数据，并读出数据

            for(uint8_t i=0; i<User_Touch.Touch_Number; i++)
            {
                GT911_ReadReg((GT_TPD_Sta + i*8 + X_L), &_temp, 1); //读出触摸x坐标的低8位
                User_Touch.Touch_XY[i].X_Point  = _temp;
                GT911_ReadReg((GT_TPD_Sta + i*8 + X_H), &_temp, 1); //读出触摸x坐标的高8位
                User_Touch.Touch_XY[i].X_Point |= (_temp<<8);

                GT911_ReadReg((GT_TPD_Sta + i*8 + Y_L), &_temp, 1); //读出触摸y坐标的低8位
                User_Touch.Touch_XY[i].Y_Point  = _temp;
                GT911_ReadReg((GT_TPD_Sta + i*8 + Y_H), &_temp, 1); //读出触摸y坐标的高8位
                User_Touch.Touch_XY[i].Y_Point |= (_temp<<8);

                GT911_ReadReg((GT_TPD_Sta + i*8 + S_L), &_temp, 1); //读出触摸大小数据的低8位
                User_Touch.Touch_XY[i].S_Point  = _temp;
                GT911_ReadReg((GT_TPD_Sta + i*8 + S_H), &_temp, 1); //读出触摸大小数据的高8位
                User_Touch.Touch_XY[i].S_Point |= (_temp<<8);
            }

            _temp=0;
            GT911_WriteReg(GT_GSTID_REG, &_temp, 1);    //清除数据标志位
        break;
    }
}


