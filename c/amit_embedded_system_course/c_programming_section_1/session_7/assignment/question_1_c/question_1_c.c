#include <stdio.h>
int main(void)
{
    char name[100];

    printf("Please, enter your name: "); scanf(" %s", name);
    printf("Your input name: %s", name);
    return 0;
}