################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MCAL/MSTK/MSTK_prog.c 

OBJS += \
./Core/Src/MCAL/MSTK/MSTK_prog.o 

C_DEPS += \
./Core/Src/MCAL/MSTK/MSTK_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MCAL/MSTK/%.o Core/Src/MCAL/MSTK/%.su Core/Src/MCAL/MSTK/%.cyclo: ../Core/Src/MCAL/MSTK/%.c Core/Src/MCAL/MSTK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MCAL-2f-MSTK

clean-Core-2f-Src-2f-MCAL-2f-MSTK:
	-$(RM) ./Core/Src/MCAL/MSTK/MSTK_prog.cyclo ./Core/Src/MCAL/MSTK/MSTK_prog.d ./Core/Src/MCAL/MSTK/MSTK_prog.o ./Core/Src/MCAL/MSTK/MSTK_prog.su

.PHONY: clean-Core-2f-Src-2f-MCAL-2f-MSTK

