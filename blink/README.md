# Blink LED

Introductory programming example using the ATMega168 and USBASP programmer.

`make`

`make clean`

Note: the `makefile` is hardware-specific. There are settings that need to be tuned to
the chip you are using.

etc.

Avrdude command to check connection:

`avrdude -p m168 -c usbasp`
`avrdude -p attiny45 -c usbasp`

Note: I did get the Makefile working with the attiny, but I had to remove the reference
to the "library" -- Some of the code there seems to be for the larger mega168 chips and
doesn't work with the tiny. The build script definitely works with the tiny.