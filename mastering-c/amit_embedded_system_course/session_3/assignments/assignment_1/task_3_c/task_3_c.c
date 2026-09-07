#include <stdio.h>

int main(void)
{
    int num1 = 0, num2 = 0;

    printf("The program receives two input numbers, checks if the first number is a muiple of the latter.\n");
    printf("Enter the first number: "); scanf("%d", &num1);
    printf("Enter the second number: "); scanf("%d", &num2);

    
    if(num2 % num1 == 0)
    {
        printf("They first number {%d} is a multiple of the second number {%d} with a multiple of {%d} [Multiple]", num1, num2, num2 / num1);
    }
    else
    {
        printf("They first number {%d} is not a multiple of the second number {%d} [Not multiple]", num1, num2);   
    }
    return 0;
}