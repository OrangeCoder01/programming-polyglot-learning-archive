#include <stdio.h>
int main(void)
{
    int heating_time = 0, temperature = 0;
    printf("The program receives the temperature input in celsius and output the corresponding heating time: \n");
    printf("Temperature: "); scanf("%d", &temperature);
    if(temperature >= 0 && temperature <= 100)
    {
        if(temperature >= 0 && temperature <= 30) {heating_time = 7;}
        else if(temperature > 30 && temperature <= 60) {heating_time = 5;}
        else if(temperature > 60 && temperature <= 90) {heating_time = 3;}
        else {heating_time = 1;}
        printf("Heating time = %d minute/minutes", heating_time);
    }
    else
    {
        printf("\nCan not procceed with a temperature input value out of boundary of 0 to 100.\n");
    }

    return 0;

}