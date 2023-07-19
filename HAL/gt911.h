#ifndef __GT911_H_
#define __GT911_H_

//#include "i2c.h"
#include "debug.h"

/*I2C���*/

#define HOST_MODE     1
#define SLAVE_MODE    0

#define I2C_MODE   HOST_MODE

#define Address_8bit     1
#define Address_16bit    0

#define Address_Lenth   Address_16bit

#define     GT911_I2C           hi2c1

#define     GT911_DIV_ID    0XBA    //�豸��ַ //0X28 //0XBA

#define     GT911_DIV_W     (GT911_DIV_ID | 0)  //д��ַ
#define     GT911_DIV_R     (GT911_DIV_ID | 1)  //����ַ



//GT911 ���ּĴ�������
#define GT_CTRL_REG     0X8040      //GT911���ƼĴ���
#define GT_CFGS_REG     0X8047      //GT911������ʼ��ַ�Ĵ���
#define GT_CHECK_REG    0X80FF      //GT911У��ͼĴ���
#define GT_PID_REG      0X8140      //GT911��ƷID�Ĵ���

#define GT_GSTID_REG    0X814E      //GT911��ǰ��⵽�Ĵ������,��7λ�Ǵ�����־λ����4λ�Ǵ�����������

#define GT_TPD_Sta      0X8150      //��������ʼ���ݵ�ַ
#define GT_TP1_REG      0X8150      //��һ�����������ݵ�ַ
#define GT_TP2_REG      0X8158      //�ڶ������������ݵ�ַ
#define GT_TP3_REG      0X8160      //���������������ݵ�ַ
#define GT_TP4_REG      0X8168      //���ĸ����������ݵ�ַ
#define GT_TP5_REG      0X8170      //��������������ݵ�ַ


#define GT_TOUCH_MAX            5           //����gt911�����ͬʱ��ȡ5�������������

typedef enum
{
    X_L = 0,
    X_H = 1,
    Y_L = 2,
    Y_H = 3,
    S_L = 4,
    S_H = 5
}Data_XYS_P;    //����X��Y��������С����ƫ����

typedef enum
{
    TOUCH__NO       = 0x00, //û�д���
    TOUCH_ING       = 0x80  //������
}TOUCH_STATE_enum;  //����״̬

typedef struct
{
    uint16_t    X_Point;    //X����
    uint16_t    Y_Point;    //Y����
    uint16_t    S_Point;    //�������С
}XY_Coordinate; //����������


/*�����ṹ��*/
typedef struct
{
    uint8_t Touch_State             ;   //����״̬
    uint8_t Touch_Number            ;   //��������
    XY_Coordinate Touch_XY[GT_TOUCH_MAX]    ;   //������x���꣬����gt911���5���������
}Touch_Struct;  //������Ϣ�ṹ��


/*�ⲿ������*/
extern Touch_Struct User_Touch;



/*�ⲿ������*/
void GT911_WriteReg(uint16_t _usRegAddr, uint8_t *_pRegBuf, uint8_t _ucLen);
void GT911_ReadReg(uint16_t _usRegAddr, uint8_t *_pRegBuf, uint8_t _ucLen);

void GT911_Send_Config(uint8_t mode);       //���ó�ʼ��ft911
void Software_Reset(uint8_t gt_SR_type);//��λ���߲���λgt911
void gt911_Scanf(void);                                 //ɨ�败��ģ��







#endif /*__GT911_H_*/

