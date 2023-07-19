################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/sw/lv_draw_sw.c \
../lvgl/src/draw/sw/lv_draw_sw_arc.c \
../lvgl/src/draw/sw/lv_draw_sw_blend.c \
../lvgl/src/draw/sw/lv_draw_sw_dither.c \
../lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../lvgl/src/draw/sw/lv_draw_sw_img.c \
../lvgl/src/draw/sw/lv_draw_sw_letter.c \
../lvgl/src/draw/sw/lv_draw_sw_line.c \
../lvgl/src/draw/sw/lv_draw_sw_polygon.c \
../lvgl/src/draw/sw/lv_draw_sw_rect.c 

OBJS += \
./lvgl/src/draw/sw/lv_draw_sw.o \
./lvgl/src/draw/sw/lv_draw_sw_arc.o \
./lvgl/src/draw/sw/lv_draw_sw_blend.o \
./lvgl/src/draw/sw/lv_draw_sw_dither.o \
./lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./lvgl/src/draw/sw/lv_draw_sw_img.o \
./lvgl/src/draw/sw/lv_draw_sw_letter.o \
./lvgl/src/draw/sw/lv_draw_sw_line.o \
./lvgl/src/draw/sw/lv_draw_sw_polygon.o \
./lvgl/src/draw/sw/lv_draw_sw_rect.o 

C_DEPS += \
./lvgl/src/draw/sw/lv_draw_sw.d \
./lvgl/src/draw/sw/lv_draw_sw_arc.d \
./lvgl/src/draw/sw/lv_draw_sw_blend.d \
./lvgl/src/draw/sw/lv_draw_sw_dither.d \
./lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./lvgl/src/draw/sw/lv_draw_sw_img.d \
./lvgl/src/draw/sw/lv_draw_sw_letter.d \
./lvgl/src/draw/sw/lv_draw_sw_line.d \
./lvgl/src/draw/sw/lv_draw_sw_polygon.d \
./lvgl/src/draw/sw/lv_draw_sw_rect.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sw/%.o: ../lvgl/src/draw/sw/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -DLV_LVGL_H_INCLUDE_SIMPLE -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Debug" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\resources" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\utils" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\lib" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos\benchmark" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples\porting" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\draw" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\extra" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\font" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\hal" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\misc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\widgets" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\User" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Peripheral\inc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\HAL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

