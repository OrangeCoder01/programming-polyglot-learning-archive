#include <stdio.h>


int main(void)/* conditional control flow is not learned, but used in this code, to avoid errors from unexpected user input */
{
    int number = 0;
    printf("Please, enter an integer number:"); scanf("%d", &number);

    int bits = 0;
    printf("Please, enter the bit order: "); scanf("%d", &bits);
    if(bits < 0)
    {
        printf("Bit order can not be negative! ");
        return 0;
    }
    if(bits > 32)
    {
        printf("Bit order can not be over 32 bits! ");
        return 0;
    }

    int result = number & ~(1 << bits);
    printf("The input number: {%d} is equal to (when bit order %d is cleared): %d", number, bits, result);
    return 0;
}