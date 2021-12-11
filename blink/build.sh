#/bin/bash

BAUD=9600UL
F_CPU=8000000UL
MCU=attiny45

function build () {
    avr-gcc -Os -g -std=gnu99 -Wall \
        -funsigned-char -funsigned-bitfields \
        -fpack-struct -fshort-enums -ffunction-sections \
        -fdata-sections -DF_CPU=$F_CPU -DBAUD=$BAUD -I. \
        -mmcu=attiny45 -c -o blinkLED.o blinkLED.c
    avr-gcc -Wl,-Map,blinkLED.map -Wl,--gc-sections -mmcu=$MCU blinkLED.o -o blinkLED.elf
    avr-objcopy -j .text -j .data -O ihex blinkLED.elf blinkLED.hex
    avrdude -c usbasp -p $MCU -U flash:w:blinkLED.hex
}

function clean () {
    rm *.elf *.hex *.map *.o
}

case $1 in
    build)
        build;;
    clean)
        clean;;
    *)
        echo "Unrecognized command $1"
esac