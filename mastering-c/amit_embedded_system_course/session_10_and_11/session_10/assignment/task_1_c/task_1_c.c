#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

void fill_array_pointer(int arr[], int size)
{
    int i = 0;
    for(i; i < size; i++)
    {
        printf("Please, enter the value for element {%d} (-60,000 ~ 60,000): ", (i + 1)); *(arr + i) = number_validator(-60000, 60000);
    }
}


int sum_array(int arr[], int size)
{
    int i = 0, sum = 0;
    for(i; i < size; i++) { sum += *(arr + i); }
    return sum;
}


int main(void)
{
    int size = 0;
    printf("Please, enter the size of the array (1, 100): "); size = number_validator(1, 100);

    int arr[size];
    fill_array_pointer(arr, size);
    int sum = sum_array(arr, size);

    printf("The sum is %d of array: ", sum);print_array(arr, size);

    return 0;
}