#include <stdio.h>

int counter(void);
int static_counter(void);
int main(void)
{
    int i = 0;
    printf("counter: \n");
    for(i; i < 10; i++) { printf("X = %d\n", counter()); }

    i = 0;
    
    printf("\n\nstatic_counter: \n");
    for(i; i < 10; i++) { printf("X = %d\n", static_counter()); }
    return 0;
}

int counter(void)
{
    int x = 0;
    x ++;
    return x;
}
int static_counter(void)
{
    static int x = 0;
    x ++;
    return x;
}