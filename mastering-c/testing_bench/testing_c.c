#include <stdio.h>
#include "helper_library_c.h"

void bubble_sort(int arr[], int size)
{
    int i = 0, j = 0, temp = 0;
    for(i; i < size; i++)
    {
        j = i + 1;
        for(j; j < size; j++)
        {
            if(arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
            print_array(arr, size);
        }
        printf("\n\n");
    }
}



int main(void)
{
    int arr[7] = {-1, -3, 3, -2, 1, 2, 0};
    bubble_sort(arr, 7);
    return 0;
}