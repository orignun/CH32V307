################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/core/lv_disp.c \
../lvgl/src/core/lv_event.c \
../lvgl/src/core/lv_group.c \
../lvgl/src/core/lv_indev.c \
../lvgl/src/core/lv_indev_scroll.c \
../lvgl/src/core/lv_obj.c \
../lvgl/src/core/lv_obj_class.c \
../lvgl/src/core/lv_obj_draw.c \
../lvgl/src/core/lv_obj_pos.c \
../lvgl/src/core/lv_obj_scroll.c \
../lvgl/src/core/lv_obj_style.c \
../lvgl/src/core/lv_obj_style_gen.c \
../lvgl/src/core/lv_obj_tree.c \
../lvgl/src/core/lv_refr.c \
../lvgl/src/core/lv_theme.c 

OBJS += \
./lvgl/src/core/lv_disp.o \
./lvgl/src/core/lv_event.o \
./lvgl/src/core/lv_group.o \
./lvgl/src/core/lv_indev.o \
./lvgl/src/core/lv_indev_scroll.o \
./lvgl/src/core/lv_obj.o \
./lvgl/src/core/lv_obj_class.o \
./lvgl/src/core/lv_obj_draw.o \
./lvgl/src/core/lv_obj_pos.o \
./lvgl/src/core/lv_obj_scroll.o \
./lvgl/src/core/lv_obj_style.o \
./lvgl/src/core/lv_obj_style_gen.o \
./lvgl/src/core/lv_obj_tree.o \
./lvgl/src/core/lv_refr.o \
./lvgl/src/core/lv_theme.o 

C_DEPS += \
./lvgl/src/core/lv_disp.d \
./lvgl/src/core/lv_event.d \
./lvgl/src/core/lv_group.d \
./lvgl/src/core/lv_indev.d \
./lvgl/src/core/lv_indev_scroll.d \
./lvgl/src/core/lv_obj.d \
./lvgl/src/core/lv_obj_class.d \
./lvgl/src/core/lv_obj_draw.d \
./lvgl/src/core/lv_obj_pos.d \
./lvgl/src/core/lv_obj_scroll.d \
./lvgl/src/core/lv_obj_style.d \
./lvgl/src/core/lv_obj_style_gen.d \
./lvgl/src/core/lv_obj_tree.d \
./lvgl/src/core/lv_refr.d \
./lvgl/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/core/%.o: ../lvgl/src/core/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -DLV_LVGL_H_INCLUDE_SIMPLE -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Debug" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\resources" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\utils" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\lib" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos\benchmark" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples\porting" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\draw" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\extra" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\font" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\hal" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\misc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\widgets" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\User" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Peripheral\inc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\HAL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

