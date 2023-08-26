################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MCAL/MGPIO/MGPIO_prog.c 

OBJS += \
./Core/Src/MCAL/MGPIO/MGPIO_prog.o 

C_DEPS += \
./Core/Src/MCAL/MGPIO/MGPIO_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MCAL/MGPIO/%.o Core/Src/MCAL/MGPIO/%.su Core/Src/MCAL/MGPIO/%.cyclo: ../Core/Src/MCAL/MGPIO/%.c Core/Src/MCAL/MGPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MCAL-2f-MGPIO

clean-Core-2f-Src-2f-MCAL-2f-MGPIO:
	-$(RM) ./Core/Src/MCAL/MGPIO/MGPIO_prog.cyclo ./Core/Src/MCAL/MGPIO/MGPIO_prog.d ./Core/Src/MCAL/MGPIO/MGPIO_prog.o ./Core/Src/MCAL/MGPIO/MGPIO_prog.su

.PHONY: clean-Core-2f-Src-2f-MCAL-2f-MGPIO

