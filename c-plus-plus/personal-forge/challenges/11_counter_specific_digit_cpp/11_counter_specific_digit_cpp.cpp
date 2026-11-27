#include <iostream>
using std::cin;

int input_user_integer(char type)
{
    int inp_user_int = 0;

    if(type == 'i'){printf("Please, Enter your input integer: ");}
    else{printf("Please, Enter your specific digit: ");}

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


int count_digit_frequency_in_integer(int integer, int specific_dig)
{
    int freq = 0;
    long int temp = integer;
    int num_of_digits = 0;

    while(true)
    {
        temp /= 10;
        if(temp != 0)
        {
            num_of_digits ++;
        }
        else
        {
            num_of_digits++;
            break;
        }
    }

    temp = integer;
    for(int i = 0; i < num_of_digits; i++)
    {
        int digit = temp %10;
        if(specific_dig == digit)
        {
            freq += 1;
        }
        temp /= 10;
    }
    return freq;
}

int main()
{   printf("Welcome, to specific digit counter\nHere You will enter both your integer number and a digit,\nand the result is frequency of that digit in that number\n");
    int user_int = input_user_integer('i');
    int user_specific_dig = input_user_integer('_');
    printf("That digit {%i} appeared in that integer {%i} number: [%i] times",user_specific_dig ,user_int ,count_digit_frequency_in_integer(user_int, user_specific_dig));
}
