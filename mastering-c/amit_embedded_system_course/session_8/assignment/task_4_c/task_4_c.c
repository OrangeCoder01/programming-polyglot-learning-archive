#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

void reverse_array(int arr[], int size)
{
    int i = 0, temp = 0;

    for(i; i < (size / 2); i ++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main(void)
{
    int size = 0;
    printf("\nRules:\n(1) Size must be from 1 to 100.\n(2) Element's value must be from -60,000 to 60,000.\n");

    printf("\nPlease, enter the size of the array: "); size = number_validator(1, 100);
    int arr[size];

    fill_arr(arr, size, -60000, 60000);

    printf("Original array: "); print_array(arr, size);
    reverse_array(arr, size);
    printf("The reversed array: ");print_array(arr, size);
    
    return 0;
}