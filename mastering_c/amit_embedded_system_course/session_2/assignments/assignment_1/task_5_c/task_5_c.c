#include <stdio.h>


int main(void)
{
    int user_num_1 = 0;
    int user_num_2 = 0;

    printf("Please, enter the value for the 1st number: "); scanf("%d", &user_num_1);
    printf("Please, enter the value for the 2nd number: "); scanf("%d", &user_num_2);

    int summing = user_num_1 + user_num_2;
    int subtraction = user_num_1 - user_num_2;
    int anding = user_num_1 & user_num_2;
    int oring = user_num_1 | user_num_2;
    int xoring = user_num_1 ^ user_num_2;

    printf("\n\nNumbers: (%d, %d):\n1) Summation: %d\n2) subtraction: %d\n3) anding: %d\n4) oring: %d\n5) xoring: %d\n\n", user_num_1, user_num_2, summing, subtraction, anding, oring, xoring);


}