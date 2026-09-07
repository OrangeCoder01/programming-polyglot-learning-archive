#include <stdio.h>
int main(void)
{
    int user_number = 0;
    printf("The programs validate an input from user by only passing positive integer and a prime number\n");
    printf("Please, enter the number: "); scanf("%d", &user_number);
    while(!(user_number > 0 && user_number % 2 == 0))
    {
        if(!(user_number > 0)){printf("Input: {%d} is not a positive number\n", user_number);}
        if(!(user_number % 2 == 0)){printf("Input: {%d} is not a prime number\n", user_number);}
        printf("Enter the number again: "); scanf("%d", &user_number);
    }
    printf("Number: %d is indeed a positive and a prime number", user_number);
    return 0;
}