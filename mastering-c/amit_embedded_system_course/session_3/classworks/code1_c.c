#include <stdio.h>
int main(void)
{
    int i = 0;
    for(i = 0; i < 5; i++)
    {
        printf("Hello, World!\n");
    }

    /*
        for(int i = 0; i < 5; i ++)
        is not portable code type, it is available from C99 and above
    */
   return 0;
}