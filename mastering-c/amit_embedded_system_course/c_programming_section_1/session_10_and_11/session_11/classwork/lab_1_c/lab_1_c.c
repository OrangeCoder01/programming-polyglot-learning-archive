#include <stdio.h>

#define print_cv printf("Yassin\n");\
                 printf("Embedded Engineer\n");\
                 printf("Living in Cairo\n");

int main(void)
{
    printf("Hello! My CV:\n");
    print_cv;
    return 0;
}