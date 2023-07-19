/*
 * gt911.c
 *
 *  Created on: 2023��6��30��
 *      Author: zhengshengbing
 */

#include "gt911.h"
#include "i2c.h"



//GT911��ԭGT9147�����ò�����
//��һ���ֽ�Ϊ�汾��(0X60),���뱣֤�µİ汾�Ŵ��ڵ���GT911�ڲ�
//flashԭ�а汾��,�Ż��������.
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

/*���������ṹ��*/
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
    ����gt911������gt911���ò���
    ����1��mode��0,���������浽flash1,�������浽flash��
*/
void GT911_Send_Config(uint8_t mode)
{
    uint8_t buf[2];

    buf[0] = 0;
    buf[1] = mode;  //�Ƿ�д�뵽GT9147 FLASH?  ���Ƿ���籣��
    for(uint8_t i=0; i<sizeof(GT9147_CFG_TBL); i++)
    {
        buf[0] += GT9147_CFG_TBL[i];//����У���
    }
  buf[0]=(~buf[0])+1;

    GT911_WriteReg(GT_CFGS_REG, (uint8_t *)GT9147_CFG_TBL, sizeof(GT9147_CFG_TBL));//���ͼĴ�������

    GT911_WriteReg(GT_CHECK_REG, buf, 2);//д��У���,�����ø��±��
}


/*
    ���ܣ�������λgt911
    ����1��gt_SR_type��Ϊ1ʱ��ʼ������λ,Ϊ0ʱ����������λ��
*/
void Software_Reset(uint8_t gt_SR_type)
{
    uint8_t _temp=0;    //�м����
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
    ���ܣ�gt911����ɨ�裬�жϵ�ǰ�Ƿ񱻴���
    ����1��
*/
void gt911_Scanf(void)
{
//    static uint8_t timer_=0;
//    timer_++;
//    if(timer_<10)       //��ֹ��ʱ���ν����ж�
//    {
//        return;
//    }
//    timer_=0;

    uint8_t _temp;  //�м����

    GT911_ReadReg(GT_GSTID_REG, &_temp, 1);//��0x814E�Ĵ���

    User_Touch.Touch_State = _temp;

    User_Touch.Touch_Number = (User_Touch.Touch_State & 0x0f);  //��ȡ��������
    User_Touch.Touch_State = (User_Touch.Touch_State & 0x80);   //����״̬

    switch(User_Touch.Touch_State)  //�ж��Ƿ��д�������
    {
        case TOUCH__NO:     //û������

        break;
        case TOUCH_ING:     //������~�������ݣ�����������

            for(uint8_t i=0; i<User_Touch.Touch_Number; i++)
            {
                GT911_ReadReg((GT_TPD_Sta + i*8 + X_L), &_temp, 1); //��������x����ĵ�8λ
                User_Touch.Touch_XY[i].X_Point  = _temp;
                GT911_ReadReg((GT_TPD_Sta + i*8 + X_H), &_temp, 1); //��������x����ĸ�8λ
                User_Touch.Touch_XY[i].X_Point |= (_temp<<8);

                GT911_ReadReg((GT_TPD_Sta + i*8 + Y_L), &_temp, 1); //��������y����ĵ�8λ
                User_Touch.Touch_XY[i].Y_Point  = _temp;
                GT911_ReadReg((GT_TPD_Sta + i*8 + Y_H), &_temp, 1); //��������y����ĸ�8λ
                User_Touch.Touch_XY[i].Y_Point |= (_temp<<8);

                GT911_ReadReg((GT_TPD_Sta + i*8 + S_L), &_temp, 1); //����������С���ݵĵ�8λ
                User_Touch.Touch_XY[i].S_Point  = _temp;
                GT911_ReadReg((GT_TPD_Sta + i*8 + S_H), &_temp, 1); //����������С���ݵĸ�8λ
                User_Touch.Touch_XY[i].S_Point |= (_temp<<8);
            }

            _temp=0;
            GT911_WriteReg(GT_GSTID_REG, &_temp, 1);    //������ݱ�־λ
        break;
    }
}

