#include <stdio.h>
#include "../utility_functions_c.h"
int find_the_nth_element_in_geometric_series(int order, int common_ratio)
{
    int value = 1, i = 1;
    if(order == 1) { return 1; }
    for(i; i < order; i++)
    {
        value *= common_ratio;
    }
    return value;
}

int main(void)
{
    int common_ratio = 0, order = 0, term_val;

    printf("This program prints the (n)th term of a geometric series: \n");
    printf("\nRules:\n(1) The (n)th term's value is from (1, 10).\n(2) The common ratio is from (1, 10). \n\n");

    printf("Please, enter the common ratio: "); common_ratio = number_validator(1, 10);/* It is 3 in this task assignment */
    printf("Please, enter the order (n)th term for the geometric series: "); order = number_validator(1, 10);/*It is 10th in this task assignment */

    term_val = find_the_nth_element_in_geometric_series(order, common_ratio);

    printf("The terms with common ratio of {%d} in order of {%d} equals {%d}", common_ratio, order, term_val);
    return 0;
}