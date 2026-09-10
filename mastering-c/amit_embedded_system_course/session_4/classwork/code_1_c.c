#include <stdio.h>

int Add(int num_1, int num_2)
{
    return (num_1 + num_2);
}

int main(void)
{
    int num_1 = 2, num_2 = 10;

    int sum = Add(2, 10);
    printf("The sum is: %d", sum);
    
    return 0;
}