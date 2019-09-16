################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/i2c.c \
../Src/main.c \
../Src/stm32f3xx_hal_msp.c \
../Src/stm32f3xx_it.c \
../Src/system_stm32f3xx.c \
../Src/tim.c 

CPP_SRCS += \
../Src/i2c_myclass.cpp \
../Src/wrapper.cpp 

OBJS += \
./Src/gpio.o \
./Src/i2c.o \
./Src/i2c_myclass.o \
./Src/main.o \
./Src/stm32f3xx_hal_msp.o \
./Src/stm32f3xx_it.o \
./Src/system_stm32f3xx.o \
./Src/tim.o \
./Src/wrapper.o 

C_DEPS += \
./Src/gpio.d \
./Src/i2c.d \
./Src/main.d \
./Src/stm32f3xx_hal_msp.d \
./Src/stm32f3xx_it.d \
./Src/system_stm32f3xx.d \
./Src/tim.d 

CPP_DEPS += \
./Src/i2c_myclass.d \
./Src/wrapper.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F303xC -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Inc" -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Drivers/STM32F3xx_HAL_Driver/Inc" -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F303xC -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Inc" -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Drivers/STM32F3xx_HAL_Driver/Inc" -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"C:/UserFile/club/2019/KOSEN-Robokon2019/program/gyro-test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


