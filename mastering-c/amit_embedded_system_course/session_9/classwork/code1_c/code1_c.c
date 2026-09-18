#include <stdio.h>


int bubble_sort(int arr[], int size)
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
        }
    }
}



int main(void)
{
    return 0;
}