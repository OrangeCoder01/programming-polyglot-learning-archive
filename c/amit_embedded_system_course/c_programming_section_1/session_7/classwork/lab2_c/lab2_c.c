#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

int main(void)
{
    int size = 0, i = 0, sum = 0;
    printf("This program prints the sum and average of the input array: \n"); 
    printf("\nRules:\n(1) Size must be from (0) to (100).\n(2) The elements' value must be from (-60,000) to (60,000).\n");
    printf("\nPlease, enter the size: "); size = number_validator(1, 100);

    int arr[size];
    fill_arr(arr, size, -60000, 60000);
    for(i; i < size; i++) { sum += arr[i]; }
    printf("Array: "); print_array(arr, size);printf(": sum = {%d} and average = {%d}", sum, sum/size );

    return 0;
}