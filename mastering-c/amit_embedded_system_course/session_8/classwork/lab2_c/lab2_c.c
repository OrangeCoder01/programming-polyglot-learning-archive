#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

void element_shifter_in_array(int arr[], int size, int removed_index)
{
    int i = removed_index;

    if( removed_index == (size - 1) ) { arr[removed_index] = 0; }
    else
    {
        while( (size - 1) > i )
        {
            arr[i] = arr[i + 1];
            i += 1;
        }
        arr[size - 1] = 0;
    }
}

int main(void)
{
    int size = 0, removed_index = 0;

    printf("Enter the array's size (0 to 100): ");
    size = number_validator(1, 100);

    printf("Enter the array's elemets' value: \n");
    int arr[size];
    fill_arr(arr, size, -60000, 60000);

    printf("Enter the index you want to remove: "); removed_index = number_validator( 0, (size - 1) );
    printf("Original array: ");print_array(arr, size);
    element_shifter_in_array(arr, size, removed_index);
    printf("Removed index {%d} array:", removed_index);print_array(arr, size);

    return 0;
}