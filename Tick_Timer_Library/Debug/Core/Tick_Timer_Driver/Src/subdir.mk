################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Tick_Timer_Driver/Src/tick_timer_driver.c 

OBJS += \
./Core/Tick_Timer_Driver/Src/tick_timer_driver.o 

C_DEPS += \
./Core/Tick_Timer_Driver/Src/tick_timer_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Tick_Timer_Driver/Src/%.o Core/Tick_Timer_Driver/Src/%.su Core/Tick_Timer_Driver/Src/%.cyclo: ../Core/Tick_Timer_Driver/Src/%.c Core/Tick_Timer_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/90543/Desktop/stm32_software-based timer architecture task scheduler/Tick_Timer_Library/Core/Tick_Timer_Driver/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Tick_Timer_Driver-2f-Src

clean-Core-2f-Tick_Timer_Driver-2f-Src:
	-$(RM) ./Core/Tick_Timer_Driver/Src/tick_timer_driver.cyclo ./Core/Tick_Timer_Driver/Src/tick_timer_driver.d ./Core/Tick_Timer_Driver/Src/tick_timer_driver.o ./Core/Tick_Timer_Driver/Src/tick_timer_driver.su

.PHONY: clean-Core-2f-Tick_Timer_Driver-2f-Src

