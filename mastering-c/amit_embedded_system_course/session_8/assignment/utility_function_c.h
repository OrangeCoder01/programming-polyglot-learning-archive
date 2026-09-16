#include <stdio.h>

int number_validator(int limit_1, int limit_2)
{
    int user_num = 0, is_number_legit = 1;

    scanf(" %d", &user_num);
    is_number_legit = is_number_legit && (user_num >= limit_1 && user_num <= limit_2);
    
    while(!is_number_legit)
    {
        if(!is_number_legit) 
        { 
            printf("Input {%d} is out of boundary [%d ~ %d], enter again: ", user_num, limit_1, limit_2); scanf(" %d", &user_num);
            is_number_legit = 1; 
        }
        is_number_legit = is_number_legit && (user_num >= limit_1 && user_num <= limit_2);
    }
    return user_num;
}

void fill_arr(int arr[], int size, int limit_1, int limit_2)
{
    int i = 0;
    for(i; i < size; i++)
    {
        printf("Please, enter the value for element {%d}: ", i + 1); arr[i] = number_validator(limit_1, limit_2);
        printf("\n");
    }
}

void print_array(int arr[], int size)
{
    int i = 0;
    printf("[ ");
    for(i; i < size; i++)
    {
        if(i < (size - 1)) { printf("%d, ", arr[i]); }
        else { printf("%d ]\n", arr[i]); }
    }
}