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

int find_large_digit_func(int integer)
{
    bool can_continue = true;
    bool is_negative = false;
    int temp = integer;
    int max = 0;

    integer > 0? is_negative = false: is_negative = true;
    if(is_negative){temp = -1*temp;}

    while (can_continue)
    {
        temp != 0 ? can_continue = true: can_continue = false;
        int digit = temp % 10;
        if(digit > max)
        {
            max = digit;
        }
        temp /= 10;
    }
    return max;
}

int main()
{  
    printf("Welcome, this programs takes your integer number as input and print the max digit prevalent in the number:\n");
    int user_int = input_user_integer();
    printf("\n The max digit in (%i) is: (%i)", user_int, find_large_digit_func(user_int));

}