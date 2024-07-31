################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AFIO_program.c \
../Src/BKMOTORS_program.c \
../Src/CAN_program.c \
../Src/DIO_program.c \
../Src/EXTI_program.c \
../Src/GENRERALTIMERS_program.c \
../Src/MDMA_program.c \
../Src/MNVIC_program.c \
../Src/MSYSTICK_program.c \
../Src/RCC_program.c \
../Src/SERVO_program.c \
../Src/SPI_program.c \
../Src/STK_program.c \
../Src/UART_program.c \
../Src/ULTRASONIC_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/AFIO_program.o \
./Src/BKMOTORS_program.o \
./Src/CAN_program.o \
./Src/DIO_program.o \
./Src/EXTI_program.o \
./Src/GENRERALTIMERS_program.o \
./Src/MDMA_program.o \
./Src/MNVIC_program.o \
./Src/MSYSTICK_program.o \
./Src/RCC_program.o \
./Src/SERVO_program.o \
./Src/SPI_program.o \
./Src/STK_program.o \
./Src/UART_program.o \
./Src/ULTRASONIC_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/AFIO_program.d \
./Src/BKMOTORS_program.d \
./Src/CAN_program.d \
./Src/DIO_program.d \
./Src/EXTI_program.d \
./Src/GENRERALTIMERS_program.d \
./Src/MDMA_program.d \
./Src/MNVIC_program.d \
./Src/MSYSTICK_program.d \
./Src/RCC_program.d \
./Src/SERVO_program.d \
./Src/SPI_program.d \
./Src/STK_program.d \
./Src/UART_program.d \
./Src/ULTRASONIC_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/AFIO_program.d ./Src/AFIO_program.o ./Src/AFIO_program.su ./Src/BKMOTORS_program.d ./Src/BKMOTORS_program.o ./Src/BKMOTORS_program.su ./Src/CAN_program.d ./Src/CAN_program.o ./Src/CAN_program.su ./Src/DIO_program.d ./Src/DIO_program.o ./Src/DIO_program.su ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/GENRERALTIMERS_program.d ./Src/GENRERALTIMERS_program.o ./Src/GENRERALTIMERS_program.su ./Src/MDMA_program.d ./Src/MDMA_program.o ./Src/MDMA_program.su ./Src/MNVIC_program.d ./Src/MNVIC_program.o ./Src/MNVIC_program.su ./Src/MSYSTICK_program.d ./Src/MSYSTICK_program.o ./Src/MSYSTICK_program.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SERVO_program.d ./Src/SERVO_program.o ./Src/SERVO_program.su ./Src/SPI_program.d ./Src/SPI_program.o ./Src/SPI_program.su ./Src/STK_program.d ./Src/STK_program.o ./Src/STK_program.su ./Src/UART_program.d ./Src/UART_program.o ./Src/UART_program.su ./Src/ULTRASONIC_program.d ./Src/ULTRASONIC_program.o ./Src/ULTRASONIC_program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

