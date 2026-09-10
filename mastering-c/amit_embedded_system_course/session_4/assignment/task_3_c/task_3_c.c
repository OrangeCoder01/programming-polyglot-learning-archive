#include <stdio.h>

int prime_check(int input_number)
{
    /* return 1 if true prime else 0 */
    if(input_number < 2 || input_number == 4){ return 0;}
    else if(input_number == 2 || input_number == 3 ){ return 1;}

    int i = 2;
    while( i * i <= input_number )
    {
        if(input_number % i == 0){ return 0;}
        i += 1;
    }

    return 1;
}



int main(void)
{
    int user_bound_1 = 0, user_bound_2 = 0, i = 0;

    printf("This program receives two boundary integer numbesr and it outputs the primes within the range\n");
    printf("Please, enter the first integer: "); scanf(" %d", &user_bound_1);
    printf("Please, enter the second integer: "); scanf(" %d", &user_bound_2);

    printf("Prime numbers between: {%d} and {%d} is: ", user_bound_1, user_bound_2);

    i = user_bound_1;

    for(i; i <= user_bound_2; i++)
    {
        if(prime_check(i)) { printf("%d ", i); }
    }


    return 0;
}