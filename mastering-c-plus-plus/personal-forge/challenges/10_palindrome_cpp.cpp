#include <iostream>
using std::cin;

int input_user_integer() // Same old technique as always
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

bool palindrome_detector(int inp_user_int, int num_of_digits_with_sign)
{
//    num_of_digits_with_sign = calculate_the_number_of_digits(inp_user_int);
    bool is_palindrome = false;

    bool is_negative = Negative_sign_checker_for_integer(inp_user_int);
    int result = 0;
    
    if(is_negative){inp_user_int = -1 * (inp_user_int);}
    int temp = inp_user_int;

    for(int i = 0 ; i < num_of_digits_with_sign - is_negative; i ++)
    {
        result = (result*10) + (temp)%10;
        temp = temp/10;
    }

    if(is_negative){result *= -1; inp_user_int *= -1;}
    
    (result == inp_user_int)? is_palindrome = true: is_palindrome = false;
    printf("\nReverse Order: [%i]\nOriginal Order: [%i]\n", result, inp_user_int);

    return is_palindrome;
}

int main()
{
    int inp_user_int = input_user_integer();
    bool is_palindrome = palindrome_detector(inp_user_int, calculate_the_number_of_digits(inp_user_int));
    is_palindrome? printf("It is a palindrome!\n\n"): printf("It is NOT a palindrome\n\n");
}
