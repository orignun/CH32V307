################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c \
../lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c \
../lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.c \
../lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.c \
../lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.c 

OBJS += \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.o \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.o \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.o 

C_DEPS += \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d \
./lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.d \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.d \
./lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/benchmark/assets/%.o: ../lvgl/demos/benchmark/assets/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -DLV_LVGL_H_INCLUDE_SIMPLE -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Debug" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\resources" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\utils" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\lib" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos\benchmark" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples\porting" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\draw" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\extra" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\font" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\hal" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\misc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\widgets" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\User" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Peripheral\inc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\HAL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

