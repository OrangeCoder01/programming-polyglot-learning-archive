/*The ASCII distance between lowercase and uppercase alphabets is 32*/
#include <stdio.h>
int main(void)
{
    char user_character = 'a';

    printf("This program takes a lowercase alphabet and convert it into an uppercase\n\n");
    printf("Please, enter the character: "); scanf("%c", &user_character);

    printf("The uppercase of '%c' is '%c'", user_character, user_character - 32);

    return 0;
}