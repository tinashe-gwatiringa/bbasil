################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/_write.c \
../src/acd_stm32f0.c \
../src/bbasil.c \
../src/gpio_stm32f0.c \
../src/lcd_stm32f0.c \
../src/led_stm32f0.c \
../src/main.c \
../src/tim_stm32f0.c 

OBJS += \
./src/_write.o \
./src/acd_stm32f0.o \
./src/bbasil.o \
./src/gpio_stm32f0.o \
./src/lcd_stm32f0.o \
./src/led_stm32f0.o \
./src/main.o \
./src/tim_stm32f0.o 

C_DEPS += \
./src/_write.d \
./src/acd_stm32f0.d \
./src/bbasil.d \
./src/gpio_stm32f0.d \
./src/lcd_stm32f0.d \
./src/led_stm32f0.d \
./src/main.d \
./src/tim_stm32f0.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F051 -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f0-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


