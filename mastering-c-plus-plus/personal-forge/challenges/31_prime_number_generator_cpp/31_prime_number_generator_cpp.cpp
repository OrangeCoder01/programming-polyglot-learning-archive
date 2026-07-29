#include <iostream>
#include "../utility_functions/yassin_math.h" // Implemeting the library for first time
using std::cin;
/*
Code Explanation:
    The 'Prime Number Generator' is about genetrating the number of primes founfd until reaching user's limit
*/

void user_input_validation(int &user_input_integer)
{
    while(!(cin >> user_input_integer) || (user_input_integer < 2))
    {
        if(user_input_integer < 2){printf("Invalid; must enter an integer with a value above 2, insert the value again:  ");}
        else{printf("Illegitimate Input, Try again: ");}
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void user_choice_validation(char &user_input_char)
{
    cin >> user_input_char;
    while(user_input_char != 'y' && user_input_char != 'Y' && user_input_char != 'n' && user_input_char != 'N')
    {
        printf("Illgitimate input, please, enter either {(Y/y) for continue or (N/n) for halting}: ");
        cin >> user_input_char;
    }
}


bool is_prime(int input_int) 
{
    if (input_int < 2 || input_int % 2 == 0) return false;
    if (input_int == 2) return true;
    
    for (int i = 3; pow(i, 2)<= input_int; i += 2) // using the pow(float element, int power) function
    {
        if (input_int % i == 0) return false;
    }
    return true;
}

void looping() 
{
    char choice = 'N';
    do {
        int limit = 0;
        printf("\nPlease enter the number: ");
        user_input_validation(limit);

        printf("Primes found till (%i): [", limit);
        
        bool first_prime = true;
        for (int i = 2; i <= limit; i++) 
        {
            if (is_prime(i)) 
            {
                if (!first_prime) printf(", ");

                printf("%i", i); 
                first_prime = false;
            }
        }
        printf("]\n");

        printf("Would you like to continue playing: {y/Y} for continue, {N/n} for exiting: ");
        user_choice_validation(choice);
    } while (choice == 'Y' || choice == 'y');
}

int main()
{
    printf("Welcome to 'Prime Number Generator':\nYou enter an input integer that must be above 2, and the program will print an array of primes found till that number\n");
    looping();
}