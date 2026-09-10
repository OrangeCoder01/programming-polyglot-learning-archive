#include <stdio.h>
int summation(int num)
{
    if(num > 0) { return num + summation(num - 1); }
    else if (num < 0) { return num + summation(num + 1); }
    else { return 0; }
}
int main(void)
{
    int input_number = 0;

    printf("The program receives an integer and it prints the sum of numbers from user-integer number to 0\n");
    printf("Please, enter the integer: "); scanf(" %d", &input_number);
    printf("\nThe sum of numbers from {%d} and 0 is: {%d} ", input_number, summation(input_number));
    return 0;
}