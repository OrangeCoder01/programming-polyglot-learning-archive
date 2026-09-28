#include <stdio.h>

int get_str_length(char arr[])
{
    int i = 0;
    while(*(arr + i) != '\0') { i += 1; }
    return i;
}

int main(void)
{
    char name[100] = {'\0'};
    printf("Please, enter your name: "); scanf(" %99s", name);
    printf("\nYour name: %s has a length of {%d} characters\n", name, get_str_length(name));
    return 0;
}