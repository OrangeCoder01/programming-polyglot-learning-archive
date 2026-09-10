#include <stdio.h>
#include "calculator_c.h"

int main(void)
{
    int num_1 = 10, num_2 = 35;

    int sum = add(num_1,  num_2);
    int diff = subtract(num_1, num_2); 
    printf("Number: [%d, %d] has sum {%d} and difference {%d} ", num_1, num_2, sum, diff);  
    return 0;
}