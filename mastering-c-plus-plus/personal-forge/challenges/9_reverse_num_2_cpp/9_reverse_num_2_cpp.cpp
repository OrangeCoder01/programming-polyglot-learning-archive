#include <iostream>
using std::cin;

int input_user_integer()
{
    int inp_user_int = 0;
    printf("Please, Enter your input integer: ");
    while (true)
    {
        if (!(cin >> inp_user_int))
        {
            printf("Illegal Input, retry again: ");
        }
        else
        {
            break;
        }
    }
    return inp_user_int;
}

bool Negative_sign_checker_for_integer(int inp_user_int)
{
    bool is_negative = false;
    (inp_user_int < 0) ? is_negative = true : is_negative = false;
    return is_negative;
}

int calculate_the_number_of_digits(int inp_user_int)
{
    int num_of_digits_with_sign = 0;
    bool is_negative = Negative_sign_checker_for_integer(inp_user_int);

    for (int i = 10; i < 10e8; i = i * 10)
    {
        num_of_digits_with_sign++;
        if (inp_user_int == 0 || inp_user_int / (i) == 0)
        {
            break;
        }
    }

    num_of_digits_with_sign = num_of_digits_with_sign + is_negative;
    return num_of_digits_with_sign;
}

int reversing_the_input_integer_order(int inp_user_int, int num_of_digits_with_sign)
{
    inp_user_int = input_user_integer();
    num_of_digits_with_sign = calculate_the_number_of_digits(inp_user_int);

    bool is_negative = Negative_sign_checker_for_integer(inp_user_int);
    int result = 0;
    
    if(is_negative){inp_user_int = -1 * (inp_user_int);}
    int temp = inp_user_int;

    for(int i = 0 ; i < num_of_digits_with_sign - is_negative; i ++)
    {
        result = (result*10) + (temp)%10;
        temp = temp/10;
    }

    if(is_negative){result *= -1;}
    
    return result;
}

int main()
{
    int inp_user_int = 0;
    int num_of_user_inp_int_dig = 0;
    printf("\nThe reversed integer order is: {%i}\n", reversing_the_input_integer_order(inp_user_int, num_of_user_inp_int_dig));
}