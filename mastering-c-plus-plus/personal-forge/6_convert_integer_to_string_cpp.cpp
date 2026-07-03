#include <iostream>
using std::cin;

void user_input_integer_validation(int &user_ip_int)
{
    printf("Please, enter an integer number: ");

    while (true)
    {
        if (!(cin >> user_ip_int))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            printf("Invalid integer number, insert again: ");
        }
        else
        {
            printf("The number you entered is: {%i}", user_ip_int);
            break;
        }
    }
}

int returning_user_input_integer_number_of_digits(int &user_ip_int)
{
    user_input_integer_validation(user_ip_int);

    int num_of_dig = 0;

    for (int i = 1; i < 1e7; i = i * 10)
    {
        if (user_ip_int == 0)
        {
            num_of_dig++;
            break;
        }
        if (user_ip_int / i != 0)
        {
            num_of_dig++;
        }
        else
        {
            break;
        }
    }

    return num_of_dig;
}


void convert_user_input_integer_to_string(int &user_ip_int)
{
    int number_of_digits = returning_user_input_integer_number_of_digits(user_ip_int);
    int temp = user_ip_int;
    bool is_negative = false;

    if(temp < 0)
    {
        temp = -temp;
        is_negative = true;
    }

    int string_length = number_of_digits + (is_negative ? 1 : 0);

    char buffer[string_length];

    for (int i = 0; i < number_of_digits; i++)
    {
        buffer[i] = (temp % 10) + '0';
        temp /= 10;
    }

    if(is_negative)
    {
        buffer[number_of_digits] = '-';
    }

    char correct_order_buffer[string_length + 1];

    for(int i = 0; i < string_length; i++)
    {
        correct_order_buffer[i] = buffer[string_length - i - 1];
    }

    correct_order_buffer[string_length] = '\0';

    printf("\nThe expression in integer: {%i}", user_ip_int);
    printf("\nThe expression in char: {%s}\n", correct_order_buffer);
}

int main()
{
    std::cout << std::endl;
    int user_ip_int_num = 0;
    convert_user_input_integer_to_string(user_ip_int_num);
    std::cout << std::endl;
}
