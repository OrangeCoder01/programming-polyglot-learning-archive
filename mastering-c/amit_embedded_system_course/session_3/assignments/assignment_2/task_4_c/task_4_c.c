#include <stdio.h>
int main(void)
{
    int user_number = 0, power = 0, result = 0, i = 1;
    printf("This program receives two input: an integer and the power, it outputs the result of the number powered by that root power: \n");
    printf("Please, enter the integer: "); scanf("%d", &user_number);
    printf("Please, enter the power: "); scanf("%d", &power);

    result = user_number;
    for (i; i < power; ++i)
    {
        result = result * user_number;
    }
    printf("\n Integer {%d} to the power of {%d} is: {%d}", user_number, power, result);
    return 0;
}