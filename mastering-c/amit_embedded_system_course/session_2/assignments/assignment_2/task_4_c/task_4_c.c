#include <stdio.h>


int main(void)
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
    if(user_bit > 32)
    {
        printf("Bit order can not be over 32 bits! ");
        return 0;
    }

    int result = number & ~(1 << bits);
    printf("The input number: {%d} is equal to (when bit order %d is cleared): %d", number, bits, result);
    return 0;
}