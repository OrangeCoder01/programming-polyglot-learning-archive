#include <stdio.h>
int main(void)
{
    int number_of_rows = 0, i = 0, j = 0;
    printf("This program receives the number of rows and outputs a pyramid with sepecifc set of rows [left-sided right angled triangle]: \n");
    printf("Please, enter the number of rows: "); scanf("%d", &number_of_rows);

    for(i; i <= number_of_rows; i++)
    {
        for(j; j < i; j++)
        {
            printf("*");
        }

        j = 0;
        printf("\n");
    }
    return 0;
}