#include <stdio.h>

int digit_holes_counter(int digit)
{
    switch(digit)
    {
        case 0:
        {
            return 1;
            break;
        }
        case 1:
        {
            return 0;
            break;
        }
        case 2: 
        {
            return 0;
            break;
        }
        case 3:
        {
            return 0;
            break;
        }
        case 4: 
        {
            return 1;
            break;
        }
        case 5:
        {
            return 0;
            break;
        }
        case 6:
        {
            return 1;
            break;
        }
        case 7:        
        { 
            return 0;
            break;
        }
        case 8: 
        {
            return 2;
            break;
        }
        case 9: 
        {
            return 1;
            break;
        }
        default:
        {
            return 0;
        }
    }
}


int calculate_number_of_digits(int integer_input)
{
    int num_of_digits = 0;

    if(integer_input == 0) { return 1; }
    while(integer_input != 0)
    {
        integer_input /= 10;
        num_of_digits ++;
    }

    return num_of_digits;
}


int digit_extractor(int integer_input, int order)
{
    int i = 1;
    while(i <= order)
    {
        if(i == order) { return integer_input % 10; }
        integer_input /= 10;
        i ++;
    }
}

int main(void)
{
    int i = 1, num_of_digits = 0, user_integer_input = 0, sum_of_holes = 0;
    printf("The program receives an integer input, and prints the number of holes present in each digit: \n");
    printf("Please, enter the integer's value: "); scanf(" %d", &user_integer_input);

    num_of_digits = calculate_number_of_digits(user_integer_input);
    for(i; i <= num_of_digits; i++)
    {
        sum_of_holes += digit_holes_counter( digit_extractor( user_integer_input, i ) );
    }
    printf("There are a total of {%d} holes in the integer: {%d}", sum_of_holes, user_integer_input);
    return 0;
}