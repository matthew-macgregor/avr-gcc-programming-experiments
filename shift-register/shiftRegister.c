/* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>     /* Defines pins, ports, etc */
#include <util/delay.h> /* Functions to waste time */
#include <stdbool.h>
#include <inttypes.h>

// data pin
#define HC595_DS_PIN     PB2
// clock pin
#define HC595_SH_CP_PIN  PB4
// latch pin
#define HC595_ST_CP_PIN  PB3
// blinker pin
// #define BLINK_PIN        PB4
#define MSB_HIGH         0b10000000

void set_pin(uint8_t pin, uint8_t bit)
{
  if (bit)
  {
    PORTB |= (1 << pin);
  }
  else
  {
    PORTB &= (~(1 << pin));
  }
}

void shift_clock()
{
  // Pulse the shift clock
  set_pin(HC595_SH_CP_PIN, 1);
  set_pin(HC595_SH_CP_PIN, 0);
}

void shift_latch()
{
  // Pulse the store clock
  set_pin(HC595_ST_CP_PIN, 1);
  _delay_ms(1);
  set_pin(HC595_ST_CP_PIN, 0);
  _delay_ms(1);
}

void shift_data(uint8_t data)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    bool state = (data & MSB_HIGH) ? 1 : 0;
    set_pin(HC595_DS_PIN, state);
    shift_clock();
    data = data << 1;
  }
  shift_latch();
}

int main(void)
{
  /*
  RESET/PB5 - |    | - VCC
  PB3       - |    | - PB2 / SCK
  PB4       - |    | - PB1 / MISO
  GND       - |    | - PB0 / MOSI
  */

  // -------- Inits --------- //
  // Enable output on data direction register B
  DDRB |= ((1 << HC595_DS_PIN) | (1 << HC595_SH_CP_PIN) | (1 << HC595_ST_CP_PIN));
  // DDRB |= (1 << BLINK_PIN);

  // uint8_t led[2] = {
  //   0b10000001,
  //   0b11000011
  // };

  // ------ Event loop ------ //
  while (1)
  {
    for(uint8_t i = 0; i < 8; i++)
    {
      // set_pin(BLINK_PIN, 1);
      shift_data(1 << i);
      _delay_ms(50);
      // set_pin(BLINK_PIN, 0);
      // _delay_ms(100);
    }
  }
  return 0;
}
