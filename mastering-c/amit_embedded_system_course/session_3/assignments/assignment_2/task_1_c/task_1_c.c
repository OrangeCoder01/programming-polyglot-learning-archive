#include <stdio.h>
int main(void)
{
    int user_number = 0, i = 2, is_prime = 0x01;

    printf("The programs validate an input from user by only passing positive integer and check if it is a prime number\n");
    printf("Please, enter the number: "); scanf("%d", &user_number);

    while(!(user_number > 0))
    {
        printf("Input: {%d} is not a positive number\n", user_number);
        printf("Enter the number again: "); scanf("%d", &user_number);
    }

    for(i; i < user_number / 2; i++) /*i < user_number/2 takes less time than i < user_number condition*/
    {
        if (user_number % i == 0 ) 
        {
            is_prime = is_prime && (0); 
            break;
        }
    }

    if(is_prime){ printf("Input: {%d} is a prime number [Prime number]\n", user_number); }
    else { printf("Input: {%d} is not a prime number [Not a prime number]\n", user_number); }


    return 0;
}