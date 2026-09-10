#include <stdio.h>
#include "calculator.h"

int main(void)
{
    int num_1 = 0, num_2 = 0, is_valid = 1, result = 0;
    char oper_char = 'a';

    printf("Please, enter 1st integer: "); scanf(" %d", &num_1);
    printf("Please, enter the operator ('+', '-', '*', '/', '%%'): "); scanf(" %c", &oper_char);
    printf("Please, enter 2nd integer: "); scanf(" %d", &num_2);

    switch (oper_char)
    {
        case ('+'): { result = add(num_1, num_2); break; }
        case ('-'): { result = sub(num_1, num_2); break; }
        case ('*'): { result = mult(num_1, num_2); break; }
        case ('/'): 
        {
            if(num_2 == 0) 
            {
                 printf("Can not divide by zero \n");
                 is_valid = 0;
            }
            else { result = div(num_1,  num_2); }
            break;
        }
        case ('%'): { result = mod(num_1, num_2); break; }
        default: 
        {
            printf("Invalid operator!\n");
            is_valid = 0;
        }
    }

    if (is_valid) { printf(" %d %c %d = %d ", num_1, oper_char, num_2, result); }
    is_valid = 1;

    return 0;
}