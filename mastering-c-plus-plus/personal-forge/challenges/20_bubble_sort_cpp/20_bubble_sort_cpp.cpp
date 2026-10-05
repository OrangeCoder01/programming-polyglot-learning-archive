#include <iostream>
using std::cin;

void fill_array(int arr[], int size)
{
    int i = 0;
    for(i; i < size; i++)
    {
        printf("Please, enter the element {%d}: ", (i + 1)); cin >> *(arr + i);
    }
}

void print_array(int arr[], int size)
{
    int i = 0;
    printf("[");
    for(i; i < size; i++)
    {
        if(i < (size - 1)) { printf("%d, ", *(arr + i)); }
        else { printf("%d]", *(arr + i)); }
    }
}

void bubble_sort(int arr[], int size)
{
    int i = 0, j = 0;
    for(i; i < size; i++)
    {
        for(j; j < (size - i - 1); j++)
        {
            int temp = 0;
            if(*(arr + j)  > * (arr + j + 1)) 
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    } 
}

int main(void)
{
    int size = 0;
    int array[500]; 
    printf("enter size: ");cin >> size;
    if(size < 0 || size > 500) 
    {
        printf("Illegal input"); 
        return 0;
    }
    else { fill_array(array, size); }
    printf("\nOriginal array: ");print_array(array, size);
    bubble_sort(array, size);
    printf("\nSorted array: ");print_array(array, size);

    return 0;
} 