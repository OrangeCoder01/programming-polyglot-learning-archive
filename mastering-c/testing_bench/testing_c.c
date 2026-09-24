#include <stdio.h>
#define MakeVar(name, number) name##_##number
int main(void)
{
    int MakeVar(number, 1) = 5;
    printf("number_1 = %d\n", number_1);
    return 0;
}