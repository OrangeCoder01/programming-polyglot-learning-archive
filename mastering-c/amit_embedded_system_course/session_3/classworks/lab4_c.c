#include <stdio.h>
int main(void)
{
    int i = 0, value = 0;
    printf("The first 10 natural numbers are: \n");
    for(i; i < 10; i++)
    {
        value += 1;
        printf("%d ", value);
    }
    printf("\n");
    return 0;
}