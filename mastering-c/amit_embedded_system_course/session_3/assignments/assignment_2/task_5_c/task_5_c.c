#include <stdio.h>
int main(void)
{
    int user_number = 0, temp = 0, rev_user_number = 0, digit = 0, multiplier = 1, number_of_digits = 0, i = 0;
    printf("This program receive an input integer and output the reversed integer. \n");
    printf("Please, enter the user number value: "); scanf("%d", &user_number);

    temp = user_number;
    while (temp > 0) /*To extract the number of digit in the input integer*/
    {
        temp /= 10;
        number_of_digits += 1;
    }
    
    
    for(i; i < number_of_digits - 1; i++){multiplier *= 10;}
    
    temp = user_number;
    i = 0;

    while (i < number_of_digits)
    {
        digit = temp % 10;
        rev_user_number += digit * multiplier;

    /*  printf("temp = %d, rev_user_number = %d, digit = %d, multiplier = %d\n", temp, rev_user_number, digit, multiplier);*/   /*for debugging*/
        temp /= 10;
        multiplier /= 10;
        i += 1;
    }
    printf("Input integer: {%d} and reversed input integer: {%d}", user_number, rev_user_number);


    return 0;
}