################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MCAL/MNVIC/MNVIC_prog.c 

OBJS += \
./Core/Src/MCAL/MNVIC/MNVIC_prog.o 

C_DEPS += \
./Core/Src/MCAL/MNVIC/MNVIC_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MCAL/MNVIC/%.o Core/Src/MCAL/MNVIC/%.su Core/Src/MCAL/MNVIC/%.cyclo: ../Core/Src/MCAL/MNVIC/%.c Core/Src/MCAL/MNVIC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MCAL-2f-MNVIC

clean-Core-2f-Src-2f-MCAL-2f-MNVIC:
	-$(RM) ./Core/Src/MCAL/MNVIC/MNVIC_prog.cyclo ./Core/Src/MCAL/MNVIC/MNVIC_prog.d ./Core/Src/MCAL/MNVIC/MNVIC_prog.o ./Core/Src/MCAL/MNVIC/MNVIC_prog.su

.PHONY: clean-Core-2f-Src-2f-MCAL-2f-MNVIC

