################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../libsrc/color.cpp \
../libsrc/driver.cpp \
../libsrc/graphics.cpp \
../libsrc/keys.cpp \
../libsrc/utility.cpp 

OBJS += \
./libsrc/color.o \
./libsrc/driver.o \
./libsrc/graphics.o \
./libsrc/keys.o \
./libsrc/utility.o 

CPP_DEPS += \
./libsrc/color.d \
./libsrc/driver.d \
./libsrc/graphics.d \
./libsrc/keys.d \
./libsrc/utility.d 


# Each subdirectory must supply rules for building sources it contributes
libsrc/%.o: ../libsrc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/X11/include -I"/Users/cschatz/Developer/LPCGraphics/LPCGraphicsProject-Mac-Eclipse/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


