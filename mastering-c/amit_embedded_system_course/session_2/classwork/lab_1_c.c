#include <stdio.h>

int main(void)
{

    // Setting (Set bit)
    int user_num = 0;
    printf("Please enter a number: ");scanf("%d", &user_num);
    int bit = 0;
    printf("Please enter the bit: ");scanf("%d", &bit);

    int end_val = (user_num | (1 << bit)) ;

    printf("user input number = %d || user input bit = %d || result = %d", user_num, bit, end_val);
    return 0;
}