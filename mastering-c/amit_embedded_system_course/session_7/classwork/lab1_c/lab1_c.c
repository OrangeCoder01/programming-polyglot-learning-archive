#include <stdio.h>
#include "../utility_functions_c.h"

int main(void)
{
    int size = 0, i = 0, temp = 0;
    printf("This program prints the reversed form of the input array: \n"); 
    printf("\nRules:\n(1) Size must be from (0) to (100).\n(2) The elements' value must be from (-60,000) to (60,000).\n");
    printf("\nPlease, enter the size: "); size = number_validator(1, 100);

    int arr[size];
    fill_arr(arr, size, -60000, 60000);
    printf("Original array: "); print_array(arr, size);

    for(i; i < (size / 2); i ++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("The reversed array: ");print_array(arr, size);

    return 0;
}