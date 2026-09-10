#include <stdio.h>

int main(void)
{

    int user_num = 0;
    int user_bit = 0;

    printf("Please, enter an integer number: "); scanf("%d", &user_num);
    printf("Please, enter a bit order: "); scanf("%d", &user_bit);
    if(user_bit < 0)
    {
        printf("Bit order can not be negative! ");
        return 0;
    }
    if(user_bit > 32)
    {
        printf("Bit order can not be over 32 bits! ");
        return 0;
    }

    int result = (user_num >> user_bit) & 1;
    printf("The number {%d} has a bit in the order {%d}: {%d}", user_num, user_bit, result);
    return 0;
}