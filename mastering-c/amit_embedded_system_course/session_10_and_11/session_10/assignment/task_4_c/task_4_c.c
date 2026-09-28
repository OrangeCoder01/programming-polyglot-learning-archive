#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

int find_small_element_in_array(int*, int);

int main(void)
{
    printf("Please, enter the size of the array: "); int size = number_validator(1, 100);

    int arr[size];
    fill_arr(arr, size, -60000, 60000);

    printf("The smallest element in array: ");print_array(arr, size);printf(" is %d ", find_small_element_in_array(arr, size));

    return 0;
}

int find_small_element_in_array(int arr[], int size)
{
    int i = 1, min = *(arr);
    for(i; i < size; i ++)
    {
        int value = *(arr + i);
        if(min > value) { min = value;}
    }
    return min;
}