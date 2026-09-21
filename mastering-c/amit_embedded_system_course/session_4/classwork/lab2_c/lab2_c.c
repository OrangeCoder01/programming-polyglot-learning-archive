#include <stdio.h>

int main(void)
{
    int user_num = 0;
    printf("Please, enter the input from the user: "); scanf("%d", &user_num);
    if(user_num % 2 == 0)
    {
        printf("The number: {%d} is even", user_num);
    }
    else
    {
        printf("The number: {%d} is odd", user_num);
    }

    return 0;
}