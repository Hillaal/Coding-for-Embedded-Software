################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/PollerTimer.c \
../Drivers/src/client.c \
../Drivers/src/device.c \
../Drivers/src/poller.c 

OBJS += \
./Drivers/src/PollerTimer.o \
./Drivers/src/client.o \
./Drivers/src/device.o \
./Drivers/src/poller.o 

C_DEPS += \
./Drivers/src/PollerTimer.d \
./Drivers/src/client.d \
./Drivers/src/device.d \
./Drivers/src/poller.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/lab 4/43_polling_to_observer_garbage/inc" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/lab 4/43_polling_to_observer_garbage/CMSIS/device" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/lab 4/43_polling_to_observer_garbage/CMSIS/core" -I"E:/SBME/2022/Semester 2/Coding for Embedded/Sections/lab 4/43_polling_to_observer_garbage/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

