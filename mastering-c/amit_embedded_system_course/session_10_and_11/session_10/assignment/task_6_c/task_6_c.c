#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

void array_swap(int*, int*, int);

int main(void)
{
    printf("Please, enter the size of the array: "); int size = number_validator(1, 100);

    int arr_1[size], arr_2[size];
    printf("\nPlease, Enter array {1}: \n");
    fill_arr(arr_1, size, -60000, 60000);
    
    printf("Please, enter array {2}: \n");
    fill_arr(arr_2, size, -60000, 60000);
    
    printf("Original arrays: Array {1}: ");print_array(arr_1, size);printf(" & Array {2}: ");print_array(arr_2, size);
    array_swap(arr_1, arr_2, size);
    printf("Swapped arrays: Array {1}: ");print_array(arr_1, size);printf(" & Array {2}: ");print_array(arr_2, size);
    return 0;
}

void array_swap(int arr_1[], int arr_2[], int size)
{
    int i = 0, temp = 0;
    for(i; i < size; i ++) 
    {
        temp = *(arr_2 + i);
        *(arr_2 + i) = *(arr_1 + i); 
        *(arr_1 + i) = temp;
    }
}