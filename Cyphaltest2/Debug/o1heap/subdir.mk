################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../o1heap/o1heap.c 

OBJS += \
./o1heap/o1heap.o 

C_DEPS += \
./o1heap/o1heap.d 


# Each subdirectory must supply rules for building sources it contributes
o1heap/%.o o1heap/%.su o1heap/%.cyclo: ../o1heap/%.c o1heap/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/joe/Desktop/Github/Cyphal_STM32/Cyphaltest2/o1heap" -I"C:/Users/joe/Desktop/Github/Cyphal_STM32/Cyphaltest2/uavcan/node" -I"C:/Users/joe/Desktop/Github/Cyphal_STM32/Cyphaltest2/libcanard" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-o1heap

clean-o1heap:
	-$(RM) ./o1heap/o1heap.cyclo ./o1heap/o1heap.d ./o1heap/o1heap.o ./o1heap/o1heap.su

.PHONY: clean-o1heap

