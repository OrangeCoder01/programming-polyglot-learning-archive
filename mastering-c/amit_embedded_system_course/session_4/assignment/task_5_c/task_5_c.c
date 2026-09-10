#include <stdio.h>

int power_check(int integer_input, int base, int supposed_result)
{
    /* Default return result is -1 */
    if(integer_input <= 0 || base <= 1){return -1;}
    while(integer_input != 1)
    {
        if(integer_input % base != 0){return -1;}
        integer_input /= base;
    }
    return supposed_result;
}


int main(void)
{
    int integer_input = 0, base_num = 2, result = -1;

    printf("This program recieves an integer number, a base number, and a supposed value that will be printed\n");
    printf("if the integer number is a result of the powering the base number, for example: 8 = 2^4, supposed result = 1.\n\n");

    printf("Please, enter the integer number: "); scanf(" %d", &integer_input);

    result = power_check(integer_input, 2, 1);

    if(result == -1)
    {
        result = power_check(integer_input, 3,  0);
    }

    printf("The result for user's integer {%d} is: {%d}\n", integer_input, result);

    return 0;
}