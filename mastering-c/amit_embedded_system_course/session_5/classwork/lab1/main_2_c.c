#include <stdio.h>
int fact(int num)
{
    if( (num == 1) || (num == 0) ) { return 1; }
    return num * fact(num - 1);
}

int main(void)
{
    printf("factorial (5) = %d ", fact(5));
    return 0;
}
