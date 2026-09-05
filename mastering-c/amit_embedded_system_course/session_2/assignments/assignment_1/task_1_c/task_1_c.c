#include <stdio.h>


int main(void)
{
    int user_num_1 = 0;
    int user_num_2 = 0;

    printf("Please, enter the value for the 1st number: "); scanf("%d", &user_num_1);
    printf("Please, enter the value for the 2nd number: "); scanf("%d", &user_num_2);

    int result = ((user_num_1 + user_num_2) * 3) - 10;
    printf("The result is: %d", result);

}