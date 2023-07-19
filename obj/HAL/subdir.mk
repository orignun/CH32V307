################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/adc.c \
../HAL/gpio.c \
../HAL/gt911.c \
../HAL/i2c.c \
../HAL/it.c \
../HAL/lcd.c \
../HAL/pwm.c \
../HAL/rtc.c \
../HAL/spi.c \
../HAL/tim.c \
../HAL/usart.c 

OBJS += \
./HAL/adc.o \
./HAL/gpio.o \
./HAL/gt911.o \
./HAL/i2c.o \
./HAL/it.o \
./HAL/lcd.o \
./HAL/pwm.o \
./HAL/rtc.o \
./HAL/spi.o \
./HAL/tim.o \
./HAL/usart.o 

C_DEPS += \
./HAL/adc.d \
./HAL/gpio.d \
./HAL/gt911.d \
./HAL/i2c.d \
./HAL/it.d \
./HAL/lcd.d \
./HAL/pwm.d \
./HAL/rtc.d \
./HAL/spi.d \
./HAL/tim.d \
./HAL/usart.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -DLV_LVGL_H_INCLUDE_SIMPLE -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Debug" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\resources" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\utils" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\lib" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos\benchmark" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples\porting" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\draw" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\extra" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\font" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\hal" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\misc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\widgets" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\User" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Peripheral\inc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\HAL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

