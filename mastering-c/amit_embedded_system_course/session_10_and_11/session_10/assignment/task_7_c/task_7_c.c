#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

char string(char*);

int main(void)
{
    char txt_arr[410];
    printf("Please, enter text with limit of 400 characters: ");scanf(" %s", txt_arr);
    if(sizeof(txt_arr)/sizeof(*(txt_arr)) > 400) { printf("\nYou entered more than 400 characters!\n"); }
    else {  }
    return 0;
}

char string(char arr[])
{
    
}