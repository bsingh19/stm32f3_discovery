################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppTest/Src/apptTest.c 

OBJS += \
./AppTest/Src/apptTest.o 

C_DEPS += \
./AppTest/Src/apptTest.d 


# Each subdirectory must supply rules for building sources it contributes
AppTest/Src/%.o AppTest/Src/%.su: ../AppTest/Src/%.c AppTest/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/RopeIoT/STM32CubeIDE/workspace_1.10.1/TestMotorServo/AppTest/Inc" -I"C:/Users/RopeIoT/STM32CubeIDE/workspace_1.10.1/TestMotorServo/Components/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppTest-2f-Src

clean-AppTest-2f-Src:
	-$(RM) ./AppTest/Src/apptTest.d ./AppTest/Src/apptTest.o ./AppTest/Src/apptTest.su

.PHONY: clean-AppTest-2f-Src

