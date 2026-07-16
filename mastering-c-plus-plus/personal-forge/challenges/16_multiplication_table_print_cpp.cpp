#include <iostream>

void multiplication_table()
{

    for(int first_dig = 1; first_dig <= 9; first_dig++)
    {
        bool new_digit_flag = true;
        for(int second_dig = 1; second_dig <= 9; second_dig++)
        {
            if(new_digit_flag)
            {
                new_digit_flag = false;
                printf("Table of {%i}:\n", first_dig);

            }
            printf("%i x %i = %i\n", first_dig, second_dig, first_dig*second_dig);
        }
        printf("--------------------------------------------------\n");
    }
}

int main()
{
    multiplication_table();
}