#include <stdio.h>


int main(void)
{
    float degree_celsius = 0;
    float degree_fahrenheit = 0;

    printf("Please, enter the temperature in Celcsius(C): ");
    scanf("%f", &degree_celsius);

    degree_fahrenheit = (degree_celsius * 9.0/5.0) + 32.0;
    printf("\nThe corresponding value of: {%f celsius} is {%f fahrenheit}\n", degree_celsius, degree_fahrenheit);
}