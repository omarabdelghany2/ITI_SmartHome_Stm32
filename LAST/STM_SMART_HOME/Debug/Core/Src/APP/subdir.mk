################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/APP/Login_System.c \
../Core/Src/APP/SMART_HOME.c 

OBJS += \
./Core/Src/APP/Login_System.o \
./Core/Src/APP/SMART_HOME.o 

C_DEPS += \
./Core/Src/APP/Login_System.d \
./Core/Src/APP/SMART_HOME.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/APP/%.o Core/Src/APP/%.su Core/Src/APP/%.cyclo: ../Core/Src/APP/%.c Core/Src/APP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-APP

clean-Core-2f-Src-2f-APP:
	-$(RM) ./Core/Src/APP/Login_System.cyclo ./Core/Src/APP/Login_System.d ./Core/Src/APP/Login_System.o ./Core/Src/APP/Login_System.su ./Core/Src/APP/SMART_HOME.cyclo ./Core/Src/APP/SMART_HOME.d ./Core/Src/APP/SMART_HOME.o ./Core/Src/APP/SMART_HOME.su

.PHONY: clean-Core-2f-Src-2f-APP

