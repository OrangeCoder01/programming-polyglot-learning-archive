#include <stdio.h>
#include "valuable_functions_c.h"

int sum_arr(int arr[], int size)
{
    int i = 0, sum = 0;
    for(i; i < size; i++) { sum += arr[i]; }
    return sum;
}

int main(void)
{
    int size = 0;

    printf("This program calculates and print the sum of the elements of the array: \n(1) Size is from 1 to 100.\n(2) Elements' value is from -60,000 to 60,000.\n\n");
    printf("Please, enter the size of the array: "); size = number_validator(1, 100);

    int arr[size];
    fill_arr(arr, size, -60000, 60000);
    printf("The sum is: {%d}", sum_arr(arr, size));

    return 0;
}