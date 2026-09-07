#include <stdio.h>
int main(void)
{
    int i = 0;
    printf("This program prints uppercase alphabetical letters A ~ Z: \n");
    for(i = 65; i <= 90; ++i)
    {
        printf("%c\n", i);
    }
    return 0;
}