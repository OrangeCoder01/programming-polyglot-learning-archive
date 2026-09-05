#include <stdio.h>

int main(void)
{
    // Learning post- and pre- increment
          int x = 10; 
          printf("x = %d\n", x);
          int y = x ++;
          printf("y = %d\n", y);
          printf("x = %d\n", x);
          int z = ++x;
          printf("x =  %d\n", x);
          printf("z =  %d\n", z);
}