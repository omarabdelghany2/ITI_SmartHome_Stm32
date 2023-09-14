################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/HAL/HKPD/HKPD_programm.c 

OBJS += \
./Core/Src/HAL/HKPD/HKPD_programm.o 

C_DEPS += \
./Core/Src/HAL/HKPD/HKPD_programm.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/HAL/HKPD/%.o Core/Src/HAL/HKPD/%.su Core/Src/HAL/HKPD/%.cyclo: ../Core/Src/HAL/HKPD/%.c Core/Src/HAL/HKPD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-HAL-2f-HKPD

clean-Core-2f-Src-2f-HAL-2f-HKPD:
	-$(RM) ./Core/Src/HAL/HKPD/HKPD_programm.cyclo ./Core/Src/HAL/HKPD/HKPD_programm.d ./Core/Src/HAL/HKPD/HKPD_programm.o ./Core/Src/HAL/HKPD/HKPD_programm.su

.PHONY: clean-Core-2f-Src-2f-HAL-2f-HKPD

