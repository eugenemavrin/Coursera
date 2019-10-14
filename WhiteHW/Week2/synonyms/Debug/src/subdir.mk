################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/synonyms.cpp 

OBJS += \
./src/synonyms.o 

CPP_DEPS += \
./src/synonyms.d 


# Each subdirectory must supply rules for building sources it contributes
src/synonyms.o: ../src/synonyms.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/synonyms.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


