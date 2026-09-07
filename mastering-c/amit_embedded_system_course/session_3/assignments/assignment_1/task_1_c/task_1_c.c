/*a = 97, z = 122, A = 65, and Z = 90*/
#include <stdio.h>
int main(void)
{
    char user_character = 'a';
    printf("The program will output an input character whether it is an alphabet or not, enter character: "); scanf("%c", &user_character);

    if((user_character >= 97 && user_character <= 122) || (user_character <= 90 && user_character >= 65))
    {
        printf("Input '%c' is indeed an alphabet", user_character);
    }
    else
    {
        printf("Input '%c is not an alphabet'", user_character);
    }
    return 0;
}