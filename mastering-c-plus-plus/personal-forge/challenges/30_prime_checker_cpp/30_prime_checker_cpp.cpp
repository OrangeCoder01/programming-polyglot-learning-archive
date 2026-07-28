/*
Explanation:
    This program takes from the user an integer and check if this number is prime or not
*/

#include <iostream>
using std::cin;

void user_input_validation(int &user_input_integer)
{
    while(!(cin >> user_input_integer))
    {
        printf("Illegitimate Input, Try again: ");
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void user_choice_validation(char &user_input_char)
{
    cin >> user_input_char;
    while(user_input_char != 'y'&&user_input_char != 'Y'&&user_input_char != 'n'&&user_input_char != 'N')
    {
        printf("Illgitimate input, please, enter either {(Y/y) for continue or (N/n) for halting}: ");
        cin >> user_input_char;
    }
}


bool is_prime(int input_int)
{
    if(input_int < 0){return false;}

    if(input_int == 0 || input_int == 1){return false;}
    else if(input_int == 2){return true;}

    for(int i = 0; i < input_int / 2; i++)
    {
        if(input_int % (i + 2) == 0){return false;}
    }
    return true;
}

void looping()
{
    char choice = 'N'; 
    do
    {
        int integer_input = 0;
        printf("Please enter the number: ");
        user_input_validation(integer_input);
        is_prime(integer_input)?printf("This is a 'Prime Number'"):printf("This is a 'Composite Number'");
        printf("\n");
        printf("Would you like to continue playing: {y/Y} for continue, {N/n} for exiting: ");
        user_choice_validation(choice);

    } while(choice == 'Y' || choice == 'y');
}

int main()
{
    printf("Welcome to 'Prime Number Checker':\nYou enter an integer input, and the program will indicate if it is a prime or composite\n");
    looping();
}