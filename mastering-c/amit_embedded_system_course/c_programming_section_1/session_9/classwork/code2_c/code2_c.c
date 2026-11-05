#include <stdio.h>
int main(void)
{
    register int x = 0, y = 1;
    register int z =  x + y;
    /*In terminal push: gcc -S code2_c.c -o code2_c.s*/
    /*Then push: gcc code2_c.s*/
    return 0;
}