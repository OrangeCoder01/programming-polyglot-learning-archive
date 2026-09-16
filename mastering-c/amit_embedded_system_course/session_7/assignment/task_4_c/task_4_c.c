#include <stdio.h>
#include "../utility_functions_c.h"

int looping_fibonacci(int order)
{
    int num_1 = 1, num_2 = 1, i = 2, result = 0;

    if(order <= 2) { return 1; }

    for(i; i < order; i++)
    {
        result = num_1;
        num_1 = num_2;
        num_2 += result;
    }
    return result;
}

int recursive_fibonacci(int order, int num_1, int num_2)
{
    int result  = num_1 + num_2;
    order -= 1;

    if(order <= 0){return ( num_1 );}
    
    num_1 = num_2;
    num_2 = result;
    
    return recursive_fibonacci(order, num_1, num_2);

}

int find_the_nth_element_in_fibonacci_series(int order, char user_choice)
{
    int result = 0;
    if(user_choice == 'L') { result = looping_fibonacci(order); }
    else { result =  recursive_fibonacci(order, 1, 1); }

    return result;
}

int main(void)
{
    int order = 0, result = 0;
    char user_choice = 'a';

    printf("This program prints the (n)th term of a Fibonacci series: \n");
    printf("\nRules:\n(1) The (n)th term's value is from (1, 50).\n(2) Choice between using (For/while) loops and (Recursion) methods must be either ['L' for loops,'R' for recursion]. \n\n");

    printf("Please, enter the order (n)th term for the Fibonacci series: "); order = number_validator(1, 50);
    printf("Your choice for Fibonacci method: "); user_choice = user_choice_validator('L', 'R');

    result = find_the_nth_element_in_fibonacci_series(order, user_choice);

    printf("The term order of {%d} is equal to {%d}", order, result);


    return 0;
}