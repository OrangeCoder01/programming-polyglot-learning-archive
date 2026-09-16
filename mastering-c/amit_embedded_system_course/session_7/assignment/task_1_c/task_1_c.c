#include <stdio.h>
#include "../utility_functions_c.h"


int main(void)
{
    int user_number = 0, size = 0, index = 0, is_found = 0;
    printf("This program returns the index of the first occurence of an integer value in an integer array:\n");
    printf("The program takes:\n(1) The size of the Array.\n(2) The elements' value.\n(3) User's searched number.\n");
    printf("\n\nUser's outputs:\n(1) The {index of the first occurence}, if there is no occurence: {'number is not found!'} is printed instead.\n\n");
    printf("Rules: \n");
    printf("(1) Size must be from 1 to 100.\n(2) Element's value must be from -60,000 to 60,000.\n\n");

    printf("Please, enter the size of the array: "); size = number_validator(1, 100);
    
    int array[size];
    fill_arr(array, size, -60000, 60000);
    
    printf("\nPlease, enter the element you are looking for: "); user_number = number_validator(-60000, 60000);
    
    for(index; index < size; index ++)
    {
        if(array[index] == user_number)
        {
            is_found = 1;
            break;
        }
    }

    if(is_found) { printf("Element with value: {%d} is found in index {%d} of the array: ", user_number, index);print_array(array, size); }
    else { printf("Number is not found in array: ");print_array(array, size); }

    return 0;
}