################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/simpleWMouse/simpleWMouse.cpp 

OBJS += \
./src/simpleWMouse/simpleWMouse.o 

CPP_DEPS += \
./src/simpleWMouse/simpleWMouse.d 


# Each subdirectory must supply rules for building sources it contributes
src/simpleWMouse/%.o: ../src/simpleWMouse/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\Jeane\workspace\simpleWMouse\simpleWMouse\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


