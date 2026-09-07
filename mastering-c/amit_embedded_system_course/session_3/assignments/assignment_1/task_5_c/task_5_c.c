#include <stdio.h>
int main(void)
{
    float num1 = 0, num2 = 0;
    int sum_integer = 0;
    printf("The program receives two float inputs and output the sum as integer\n");

    printf("Enter the first number: "); scanf("%f", &num1);
    printf("Enter the second number: "); scanf("%f", &num2);

    sum_integer = (int)(num1 + num2);
    printf("The integer sum of (%.2f) and (%.2f) is (%i) ", num1, num2, sum_integer);

    return 0;
}