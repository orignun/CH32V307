/*
 * Kalman.h
 *
 *  Created on: 2023��7��6��
 *      Author: zhengshengbing
 */

#ifndef APP_UTILS_KALMAN_H_
#define APP_UTILS_KALMAN_H_

typedef struct
{
    float Last_P;//�ϴι���Э���� ������Ϊ0 ! ! ! ! !
    float Now_P;//��ǰ����Э����
    float out;//�������˲������
    float Kg;//����������
    float Q;//��������Э����
    float R;//�۲�����Э����
}Kalman;

void Kalman_Init(void);
float KalmanFilter(Kalman *kfp,float input);

extern Kalman kfp;

#endif /* APP_UTILS_KALMAN_H_ */
