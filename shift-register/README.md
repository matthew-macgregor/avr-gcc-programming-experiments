# Shift Register

TODO: record shift register model, and setup
TODO: replace the makefile with something simpler

Pins:

- `DS` (Pin 14): Data Pin
- `ST_CP` (Pin 12): Latch Pin
- `SH_CP` (Pin 11): Clock Pin

Introductory programming example using the ATTiny and USBASP programmer and a shift register.

- `make`
- `make clean`

Note: the `makefile` is hardware-specific. There are settings that need to be tuned to
the chip you are using.

etc.

Avrdude command to check connection:

`avrdude -p m168 -c usbasp`
`avrdude -p attiny45 -c usbasp`

Note: I did get the Makefile working with the attiny, but I had to remove the reference
to the "library" -- Some of the code there seems to be for the larger mega168 chips and
doesn't work with the tiny. The build script definitely works with the tiny.
