#include <avr/io.h>
#include "bit_math_c.h"
int main(void) 
{
    DDRC &= 0;
    PORTC &= 0;

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

