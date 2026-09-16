#include <stdio.h>
#include "../utility_function_c.h"

int total(int array[], int size)
{
    int i = 0, sum = 0;
    for(i; i < size; i++) { sum += array[i]; }
    return sum;
}

int main(void)
{
    int sum = 0, size = 0;
    printf("This program returns the sum of elements of input array: \n");

    printf("\nRules:\n(1) Size must be from 1 to 100.\n(2) Element's value must be from -60,000 to 60,000.\n");

    printf("\nPlease, enter the size of the array: "); size = number_validator(1, 100);
    int arr[size];

    fill_arr(arr, size, -60000, 60000);
    sum = total(arr, size);

    printf("Array: ");print_array(arr, size);printf("Sum = {%d}", sum);
    



    return 0;
}