#include <stdio.h>

int main(void)
{
    int user_number = 0, i = 0;
    printf("Please, enter a number: "); scanf("%d", &user_number);

    while(i < (user_number - 1)) /*Printing from user specified number */
    {
        printf("%d, \n", user_number - i); 
        i += 1;
    }

    return 0;
}