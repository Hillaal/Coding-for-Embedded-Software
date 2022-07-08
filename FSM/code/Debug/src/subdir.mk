################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/main.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/Lab 5/45_FSM/45_FSM/inc" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/Lab 5/45_FSM/45_FSM/CMSIS/device" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/Lab 5/45_FSM/45_FSM/CMSIS/core" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/Lab 5/45_FSM/45_FSM/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

