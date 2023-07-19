################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/resources/11_bin.c \
../APP/resources/12_bin.c \
../APP/resources/13_bin.c \
../APP/resources/2_bin.c \
../APP/resources/31_bin.c \
../APP/resources/32_bin.c \
../APP/resources/3_bin.c \
../APP/resources/4_bin.c \
../APP/resources/5_bin.c \
../APP/resources/6_bin.c \
../APP/resources/ui_font_Font4.c 

OBJS += \
./APP/resources/11_bin.o \
./APP/resources/12_bin.o \
./APP/resources/13_bin.o \
./APP/resources/2_bin.o \
./APP/resources/31_bin.o \
./APP/resources/32_bin.o \
./APP/resources/3_bin.o \
./APP/resources/4_bin.o \
./APP/resources/5_bin.o \
./APP/resources/6_bin.o \
./APP/resources/ui_font_Font4.o 

C_DEPS += \
./APP/resources/11_bin.d \
./APP/resources/12_bin.d \
./APP/resources/13_bin.d \
./APP/resources/2_bin.d \
./APP/resources/31_bin.d \
./APP/resources/32_bin.d \
./APP/resources/3_bin.d \
./APP/resources/4_bin.d \
./APP/resources/5_bin.d \
./APP/resources/6_bin.d \
./APP/resources/ui_font_Font4.d 


# Each subdirectory must supply rules for building sources it contributes
APP/resources/%.o: ../APP/resources/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -DLV_LVGL_H_INCLUDE_SIMPLE -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Debug" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\resources" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\utils" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\lib" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos\benchmark" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples\porting" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\draw" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\extra" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\font" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\hal" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\misc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\widgets" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\User" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Peripheral\inc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\HAL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

