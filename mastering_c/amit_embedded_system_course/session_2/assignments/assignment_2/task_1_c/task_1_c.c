#include <stdio.h>


int main(void)
{
    char character = 'a';
    printf("Please, enter a character: ");
    scanf("%c", &character);
    printf("The ascii form of the letter {%c} is {%d}", character, character);   
}