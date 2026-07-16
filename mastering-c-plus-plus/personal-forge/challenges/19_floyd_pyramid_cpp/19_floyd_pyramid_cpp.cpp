#include <iostream>
using std::cin;

int user_validation_input()
{
    int user_input_num;
    while (true)
    {
        if (!(cin >> user_input_num))
        {
            printf("Your input is invalid, enter again: ");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            break;
        }
    }
    return user_input_num;
}

void print_floyd_triangle(int num_of_rows)
{
    int count = 1;
    do
    {
        if(num_of_rows >= 2 && num_of_rows <= 18)
        {break;}
        else
        {
            printf("That size of a triangle is unsuitable. enter a number of rows\nbetween 2 to 18\nEnter the number of rows again: ");
            num_of_rows = user_validation_input();
        }
    } while (true);

    for (int rows = num_of_rows; rows >= 0; rows--)
    {
        for (int cols = 0; cols < (num_of_rows - rows); cols++)
        {
            printf("%d\t", count);
            count ++;
        }
        printf("\n");
    }
}

int main()
{
    printf("Welcome to 'Floyd Pyramid'\nHere, you enter the number of rows\nand the program outputs a Floyd pyramid:\n\nPlease, enter the number of rows: ");
    int num_of_rows = user_validation_input();
    print_floyd_triangle(num_of_rows);
}
