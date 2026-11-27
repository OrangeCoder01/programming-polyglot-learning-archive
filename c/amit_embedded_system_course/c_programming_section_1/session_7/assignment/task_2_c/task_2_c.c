#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

int find_the_nth_element_in_arithmetic_series(int n, int iteration)
{
    int i = 1, value = 1;
    if(n == 1) { return 1; }

    while(i < n)
    {
        value += iteration;
        i += 1;
    }
    return value;
}

int main(void)
{
    int iter_val = 0, order = 0, term_val;
    printf("This program prints the (n)th term of a arithmetic series: \n");
    printf("\nRules:\n(1) The (n)th term's value is from (1, 60,000).\n(2) The number of iteration is from (1, 100). \n\n");

    printf("Please, enter the number iteration for each new term: "); iter_val = number_validator(1, 100);/* It is 2 in this task assignment */
    printf("Please, enter the order (n)th term for the arithmetic series: "); order = number_validator(1, 60000);/* It is 100th term in this task assignment */

    term_val = find_the_nth_element_in_arithmetic_series(order, iter_val);

    printf("The terms with {%d} sequential iterations in order of {%d} equals {%d}", iter_val, order, term_val);

    return 0;
}