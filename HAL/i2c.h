/*
 * i2c.h
 *
 *  Created on: 2023Äê7ÔÂ1ÈÕ
 *      Author: zhengshengbing
 */

#ifndef HAL_I2C_H_
#define HAL_I2C_H_

#include "gt911.h"

void IIC_Init(u32 bound, u16 address);
void AT24CXX_ReadOneByte(u16 ReadAddr, u8 *pBuffer, u16 NumToRead);
void AT24CXX_WriteOneByte(u16 WriteAddr, u8 *pBuffer, u16 NumToWrite);

#endif /* HAL_I2C_H_ */
