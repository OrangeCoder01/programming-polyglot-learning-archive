#include <stdio.h>
int main(void)
{
    int user_number = 0, i = 0;

    printf("This program receives an input integer and checks if it is a perfect square: \n");
    printf("Please, enter the integer: "); scanf("%d", &user_number);

    while(i * i < user_number){i += 1;}

    if(i * i == user_number){printf("Integer {%d} is a perfect square of {%d} [Perfect Square]\n", user_number, i);}
    else{printf("Integer {%d} is not a perfect square [Not a perfect square]", user_number);}
    return 0;
}