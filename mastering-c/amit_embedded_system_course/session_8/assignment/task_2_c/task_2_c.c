#include <stdio.h>
#include "../utility_function_c.h"

int last_occurence_with_index(int arr[], int size, int target)
{
    int index = -1, i = 0;
    for(i; i < size; i++) { if( arr[i] == target ) { index = i; } }
    return index;
}

int main(void)
{
    int target = 0, size = 0, index = 0;
    printf("This program outpus the index of the last occurence of an element's value in an array: \n");
    printf("\nRules:\n(1) Size must be from 1 to 100.\n(2) Element's value and the target must be from -60,000 to 60,000.\n");

    printf("\nPlease, enter the size of the array: "); size = number_validator(1, 100);
    int arr[size];

    printf("Please, enter the target number: "); target = number_validator(-60000, 60000);

    fill_arr(arr, size, -60000, 60000);
    index = last_occurence_with_index(arr, size, target);
    if(index != -1) { printf("The last occurence of the element {%d} in array: ", target); print_array(arr, size); printf("is in index: {%d}", index); }
    else{printf("Not found!");}



    return 0;
}