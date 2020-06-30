MCU=atmega16
F_CPU=8000000
CC=avr-gcc

CFLAGS= -std=c99 -Wall -g -Os -mmcu=$(MCU) -D F_CPU=$(F_CPU)

SRC=Test_Blink.c
TARGET=Test_Blink


.PHONY : all		
.PHONY : clean
.PHONY : superclean

all: COMPILE HEX

COMPILE:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
	@echo "FILE COMPILED SECCESFULLY...."

# For more details (memory regions etc.) uncomment these two lines
# @echo "DETAILS:"
# @avr-size -C $(TARGET)

HEX:
	avr-objcopy -O ihex $(TARGET) $(TARGET).hex
	@echo "HEX FILE WAS GENERATED SECCESFULLY...."

clean:
	@echo "cleaning......."
	@rm -rf $(TARGET) $(TARGET).hex


