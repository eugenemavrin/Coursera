################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PalindromFilter.cpp 

OBJS += \
./src/PalindromFilter.o 

CPP_DEPS += \
./src/PalindromFilter.d 


# Each subdirectory must supply rules for building sources it contributes
src/PalindromFilter.o: ../src/PalindromFilter.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/PalindromFilter.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


