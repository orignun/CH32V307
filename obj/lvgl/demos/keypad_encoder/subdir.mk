################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.c 

OBJS += \
./lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.o 

C_DEPS += \
./lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/keypad_encoder/%.o: ../lvgl/demos/keypad_encoder/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -DLV_LVGL_H_INCLUDE_SIMPLE -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Debug" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\resources" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\utils" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\APP\lib" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\demos\benchmark" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\examples\porting" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\draw" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\extra" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\font" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\hal" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\misc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\lvgl\src\widgets" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Core" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\User" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\SRC\Peripheral\inc" -I"C:\Users\zhengshengbing\Desktop\opench-ch32v307-master\firmware\LCD_LVGL\HAL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

