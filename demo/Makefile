MCU=atmega16
F_CPU=8000000
CC=avr-gcc

INCLUDES_PATH = ../inc/
BUILDS_PATH   = ../src/*.c

CFLAGS= -std=c99 -Wall -g -Os -mmcu=$(MCU) -D F_CPU=$(F_CPU) -I $(INCLUDES_PATH)


SRC=Test_Blink.c
TARGET=Test_Blink


.PHONY : all		
.PHONY : clean
.PHONY : superclean

all: COMPILE HEX

COMPILE:
	$(CC) $(CFLAGS) $(SRC) $(BUILDS_PATH) -o $(TARGET).elf
	@echo "FILE COMPILED SECCESFULLY...."
	

HEX:
	avr-objcopy -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex
	@echo "HEX FILE WAS GENERATED SECCESFULLY...."

	#For more details (memory regions etc.) uncomment these two lines
	echo "DETAILS:"
	@avr-size --format=avr --mcu=$(MCU) $(TARGET).elf

FLASH:
	avrdude -p $(MCU) -c usbasp -U flash:w:$(TARGET).hex:i -F -P usb


clean:
	@echo "cleaning......."
	@rm  $(TARGET).elf $(TARGET).hex


