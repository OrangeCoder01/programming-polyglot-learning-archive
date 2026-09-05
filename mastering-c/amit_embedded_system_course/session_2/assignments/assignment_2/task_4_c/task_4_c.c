#include <stdio.h>


int main(void)
{
    int number = 0;
    printf("Please, enter an integer number:"); scanf("%d", &number);

    int bits = 0;
    printf("Please, enter the bit order: "); scanf("%d", &bits);

    int result = number & ~(1 << bits);
    printf("The input number: {%d} is equal to (when bit order %d is cleared): %d", number, bits, result);
}