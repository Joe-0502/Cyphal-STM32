################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/joe/Desktop/libcanard-master/libcanard/canard.c 

OBJS += \
./libcanard/canard.o 

C_DEPS += \
./libcanard/canard.d 


# Each subdirectory must supply rules for building sources it contributes
libcanard/canard.o: C:/Users/joe/Desktop/libcanard-master/libcanard/canard.c libcanard/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/joe/Desktop/libcanard-master/libcanard" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libcanard

clean-libcanard:
	-$(RM) ./libcanard/canard.cyclo ./libcanard/canard.d ./libcanard/canard.o ./libcanard/canard.su

.PHONY: clean-libcanard

