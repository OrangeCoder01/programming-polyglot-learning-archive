#include <stdio.h>
#include "../utility_function_c.h"

void array_swap(int array_1[], int array_2[], int size)
{
    int i = 0, temp = 0;
    for(i; i < size; i ++)
    {
        temp = array_1[i];
        array_1[i] = array_2[i];
        array_2[i] = temp;
    }
}

int main(void)
{
    int size = 0;
    printf("This program swaps two arrays' elements\n");
    printf("\nRules:\n(1) size must be from 1 to 100.\n(2) Element's value must be from -60,000 to 60,000.\n");

    printf("\nPlease, enter the size of both arrays: "); size = number_validator(1, 100);
    int arr_1[size], arr_2[size];

    printf("\nFill first array:\n");
    fill_arr(arr_1, size, -60000, 60000);
    
    printf("\nFill second array:\n");
    fill_arr(arr_2, size, -60000, 60000);

    printf("\nOriginal:\n");
    printf("First array: ");print_array(arr_1, size);
    printf("Second array: ");print_array(arr_2, size);
    
    array_swap(arr_1, arr_2, size);
    
    printf("\nSwapped:\n");
    printf("First array: ");print_array(arr_1, size);
    printf("Second array: ");print_array(arr_2, size);
    

    return 0;
}