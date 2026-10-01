#include <stdio.h>
#include <stdlib.h>


#define true 1
#define false 0

typedef signed char boolean;


void bubbleSort(int *arr, int size) 
{
    int temp;
    boolean swapped;

    for (int i = 0; i < size - 1; i++) 
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) { break; } 
    }
}

int main() {
    int size;

    printf("Enter the number of elements: ");

    if (scanf("%d", &size) != 1 || size <= 0) 
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int *data = (int *)malloc(size * sizeof(int));

    if (data == NULL) 
    {
        printf("Memory allocation failed! Out of memory.\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++)  { scanf("%d", &data[i]); }


    printf("\nOriginal array: ");
    for (int i = 0; i < size; i++)  { printf("%d ", data[i]); }
    printf("\n");

    bubbleSort(data, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)  { printf("%d ", data[i]); }
    printf("\n");

    free(data);
    data = NULL; 

    return 0;
}
