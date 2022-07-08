################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/PollDataClient.c \
../Drivers/src/PollerTimer.c \
../Drivers/src/device.c \
../Drivers/src/ds1307.c \
../Drivers/src/i2c.c \
../Drivers/src/poller.c 

OBJS += \
./Drivers/src/PollDataClient.o \
./Drivers/src/PollerTimer.o \
./Drivers/src/device.o \
./Drivers/src/ds1307.o \
./Drivers/src/i2c.o \
./Drivers/src/poller.o 

C_DEPS += \
./Drivers/src/PollDataClient.d \
./Drivers/src/PollerTimer.d \
./Drivers/src/device.d \
./Drivers/src/ds1307.d \
./Drivers/src/i2c.d \
./Drivers/src/poller.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/Lab 5/45_FSM/45_FSM/inc" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/Lab 5/45_FSM/45_FSM/CMSIS/device" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/Lab 5/45_FSM/45_FSM/CMSIS/core" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/Lab 5/45_FSM/45_FSM/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

