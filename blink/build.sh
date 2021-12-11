#/bin/bash

# Example: You don't really need a makefile for simple projects, and the
# advantages of using Make are sometimes outweighed by its quirks.

BAUD=9600UL
F_CPU=8000000UL
MCU=attiny45
MAIN=blink

case $1 in
    build)
	echo "Building..."
	## COMPILE ##
	avr-gcc -Os -g -std=gnu99 -Wall \
  		-funsigned-char -funsigned-bitfields \
		-fpack-struct -fshort-enums -ffunction-sections \
		-fdata-sections -DF_CPU=$F_CPU -DBAUD=$BAUD -I. \
		-mmcu=attiny45 -c -o $MAIN.o $MAIN.c
	
	## LINK ##
	echo "Linking..."
	avr-gcc -Wl,-Map,$MAIN.map -Wl,--gc-sections -mmcu=$MCU $MAIN.o -o $MAIN.elf
	
	## HEX ##
	echo "Generating HEX..."
	avr-objcopy -j .text -j .data -O ihex $MAIN.elf $MAIN.hex
	;;

    clean)
	## CLEAN ##
	rm *.elf *.hex *.map *.o
	;;
    flash)
	## FLASH ##
	avrdude -c usbasp -p $MCU -U flash:w:$MAIN.hex
	;;
    *)
	echo "Unrecognized: $1"
	;;
esac

echo "Done."
