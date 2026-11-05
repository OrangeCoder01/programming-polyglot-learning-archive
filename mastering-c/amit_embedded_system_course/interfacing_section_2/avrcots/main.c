#if __has_include(<avr/io.h>)
#include <avr/io.h>
#else
#include <stdint.h>

#ifndef DDRC
#define DDRC (*(volatile uint8_t *)0x14)
#endif
#ifndef PORTC
#define PORTC (*(volatile uint8_t *)0x15)
#endif
#ifndef DDRD
#define DDRD (*(volatile uint8_t *)0x11)
#endif
#ifndef PORTD
#define PORTD (*(volatile uint8_t *)0x12)
#endif
#endif

#include "LIB/bit_math_c.h"

int main(void)
{

    SetBit(DDRC, 7);
    SetBit(PORTC, 7);
    
    SetBit(DDRD, 6);
    SetBit(PORTD, 6);
    
    // SetBit(DDRC, 6);
    // SetBit(PORTC, 6);
    
    // SetBit(DDRD, 6);
    // SetBit(PORTD, 6);

    while (1) 
    {

    }
}

