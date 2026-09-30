#include <stdio.h>
typedef unsigned char u_i_8; /* 'u' for unsigned (positive integer representation), 'i' for integer, and '8' for the number of bits (1 bytes) */
/* Note: chars are integers but require 1 byte, 8 bits.*/
typedef unsigned int u_i_32; /* containing 32 bits*/
typedef float s_f_32;
typedef double s_f_64; 
/* same as */
/*
typedef signed double s_f_64; 
*/
/* But that will yield to compilation; the default datatype declaration is signed */

int main(void)
{
    u_i_32 x = 3;
    s_f_32 y = 5.0;
    s_f_64 z = 0;

    z = (s_f_64)x + (s_f_64)y;
    printf("z = %.2f", z);
    return 0;
}