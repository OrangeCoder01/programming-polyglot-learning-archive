#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

void array_copy(int*, int*, int);

int main(void)
{
    printf("Please, enter the size of the array: "); int size = number_validator(1, 100);

    int arr_1[size], arr_2[size];
    fill_arr(arr_1, size, -60000, 60000);
    printf("Original array: ");print_array(arr_1, size);
    array_copy(arr_1, arr_2, size);
    printf("Copying array: ");print_array(arr_2, size);
    return 0;
}

void array_copy(int arr_1[], int arr_2[], int size)
{
    int i = 0;
    for(i; i < size; i ++) { *(arr_2 + i) = *(arr_1 + i); }
}