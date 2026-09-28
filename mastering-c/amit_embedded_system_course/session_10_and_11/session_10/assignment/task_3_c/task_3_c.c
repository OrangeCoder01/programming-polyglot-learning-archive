#include <stdio.h>
#include "../helper_library/utility_functions_c.h"


void reverse_array_pt(int*, int);

int main(void)
{
    printf("Please, enter the size of the array: "); int size = number_validator(1, 100);

    int arr[size];
    fill_arr(arr, size, -60000, 60000);

    printf("Original array:" );print_array(arr, size);
    
    reverse_array_pt(arr, size);
    printf("Reversed array: ");print_array(arr, size);
    return 0;
}

void reverse_array_pt(int arr[], int size)
{
    int i = 0, temp = 0;
    for(i; i < size/2; i++)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + (size - 1) - i);
        *(arr + (size - 1 ) - i) = temp;
    }
}