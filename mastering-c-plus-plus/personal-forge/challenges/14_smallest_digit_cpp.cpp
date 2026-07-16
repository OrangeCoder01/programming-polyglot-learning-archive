// Same as 13_largest_digit_cpp code but with a small addition


#include <iostream>
using std::cin;

int input_user_integer()
{
    int inp_user_int = 0;
    printf("Please, enter the number integer: ");
    while (true)
    {
        if (!(cin >> inp_user_int))
        {
            printf("Illegal Input, try again: ");
        }
        else{break;}
    }
    return inp_user_int;
}

int find_smallest_digit(int integer)
{
    if (integer == 0){return 0;}
    bool can_continue = true;
    bool is_negative = false;
    int temp = integer;
    int max = 0;

    integer >= 0? is_negative = false: is_negative = true;
    if(is_negative){temp = -1*temp;}

    while (can_continue)
    {
        int digit = temp % 10;
        if(digit > max)
        {
            max = digit;
        }
        temp /= 10;
        temp != 0 ? can_continue = true: can_continue = false;
    }
// This part is only added
    can_continue = true;
    int min = max;
    temp = integer;
    if(is_negative){temp = -1*temp;}
    while (can_continue)
    {
        int digit = temp % 10;
        if(min > digit)
        {
            min = digit;
        }
        temp /= 10;
        temp != 0 ? can_continue = true: can_continue = false;
    }

    return min;
}



int main()
{  
    printf("Welcome, this programs takes your integer number as input and print the minimum digit prevalent in the number:\n");
    int user_int = input_user_integer();
    printf("\nThe minimum digit in (%i) is: (%i)", user_int, find_smallest_digit(user_int));

}