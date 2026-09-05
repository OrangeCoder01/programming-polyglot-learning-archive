#include <stdio.h>


int main(void)
{
    int number = 0;
    int digit = 0;
    
    printf("Please, enter 3-digit number: "); scanf("%d", &number);
    printf("Number: %d\n", number);
    int temp = number;

    digit = (temp / 100) % 10;
    printf("%d", digit);
    temp = number;

    digit = (temp / 10) % 10;
    printf(" %d", digit);
    temp = number;

    digit = temp % 10;
    printf(" %d", digit);    
}