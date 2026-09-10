#include <stdio.h>
float cube(float input_number)
{
    int i = 0;
    float result = input_number;

    for(i;  i < 2; i++){ result *= input_number; }
    return result;
}

int main(void)
{
    float user_number = 0;
    printf("Please, enter a number and the program prints the cube of the number: "); scanf("%f", &user_number);
    printf("The cube of the number: {%.2f} is: {%.2f}", user_number, cube(user_number));
    return 0;
}