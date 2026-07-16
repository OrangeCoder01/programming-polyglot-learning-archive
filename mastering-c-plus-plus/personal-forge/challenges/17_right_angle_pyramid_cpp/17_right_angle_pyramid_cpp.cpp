#include <iostream>
using std::cin;

int user_input_validation()
{
    int user_inp_int = 0;
    while(true)
    {
        if(!(cin>>user_inp_int))
        {
            printf("Wrong input, re-enter again: ");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else{break;}
    }
    return user_inp_int;
}
void right_angle_pyramid(int num_of_rows, int num_of_columns)
{
    for(int rows = num_of_rows; rows >= 0; rows--)
    {
        for(int columns = 0; columns <= num_of_columns - rows; columns++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    printf("Welcome, this is the right angle asterick pyramid generation program:\n");
    printf("To generate a pyramid, you need to enter both number of rows and columns.");
    printf("\nEnter number of rows: ");
    int num_of_rows = user_input_validation();
    printf("Enter number of columns: ");
    int num_of_columns = user_input_validation();
    right_angle_pyramid(num_of_rows, num_of_columns);
}