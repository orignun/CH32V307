/*
 * Kalman.h
 *
 *  Created on: 2023年7月6日
 *      Author: zhengshengbing
 */

#ifndef APP_UTILS_KALMAN_H_
#define APP_UTILS_KALMAN_H_

typedef struct
{
    float Last_P;//上次估算协方差 不可以为0 ! ! ! ! !
    float Now_P;//当前估算协方差
    float out;//卡尔曼滤波器输出
    float Kg;//卡尔曼增益
    float Q;//过程噪声协方差
    float R;//观测噪声协方差
}Kalman;

void Kalman_Init(void);
float KalmanFilter(Kalman *kfp,float input);

extern Kalman kfp;

#endif /* APP_UTILS_KALMAN_H_ */
