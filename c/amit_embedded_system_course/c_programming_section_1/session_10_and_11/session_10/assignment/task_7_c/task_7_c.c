#include <stdio.h>
#include "../helper_library/utility_functions_c.h"

int main(void)
{
    char word_arr[410], two_letter_arr[4];
    
    printf("Please, enter a word with max limit of 400 characters: ");
    scanf("%400s", word_arr);

    int actual_length = 0;
    while (*(word_arr + actual_length) != '\0')  { actual_length++; }


    if (actual_length > 400) { printf("\nYou entered more than 400 characters!\n"); }
    else 
    {
        *(two_letter_arr + 0) = *(word_arr + actual_length - 1);  
        *(two_letter_arr + 1) = ' ';                              
        *(two_letter_arr + 2) = *(word_arr + 0);                 
        *(two_letter_arr + 3) = '\0';                            
    }

    printf("letters from word: {%s} is {%s}\n", word_arr, two_letter_arr);
    return 0;
}
