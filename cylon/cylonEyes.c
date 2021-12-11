/* Cylon Eyes */

// ------- Preamble -------- //
#include <avr/io.h>      /* Defines pins, ports, etc */
#include <util/delay.h>  /* Functions to waste time */
#include <stdbool.h>

#define DELAYTIME 85     /* milliseconds */
#define LED_PORT                PORTB
#define LED_PIN                 PINB
#define LED_DDR                 DDRB

int main(void) {
  // -------- Inits --------- //
  uint8_t i=0;
  LED_DDR = 0xff;   /* Data Direction Register B: */
  // all set up for output

  // ------ Event loop ------ //
  while (true) {
    while (i < 7) {
      LED_PORT = (1 << i);  /* illuminate only i'th pin */
      _delay_ms(DELAYTIME); /* wait */
      i = i + 1;            /* move to the next LED */
    }

    while (i > 0) {
      LED_PORT = (1 << i);   /* illuminate only i'th pin */
      _delay_ms(DELAYTIME);  /* wait */
      i = i - 1;             /* move to the previous LED */
    }

  }
  return 0;
}
