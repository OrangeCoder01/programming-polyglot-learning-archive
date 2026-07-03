#include <iostream>
using std::cin;
using std::cout;

int input_user_interface()
{
    int user_inp_int_num = 0;

    while (true)
    {
        std::printf("Enter an integer number: ");
        if (!(cin >> user_inp_int_num))
        {
            std::printf("Illegal input, only integer!\n");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            break;
        }
    }

    return user_inp_int_num;
}

void counting_the_num_of_digits_of_user_input_integer()
{
    int inp_user_int = input_user_interface();
    int num_of_digits = 0;

    for(long long int i = 1; i < (10e24); i = i*10)
    {
        if(inp_user_int == 0)//Special case
        {
            num_of_digits = 1;
        }

        if(inp_user_int/(i) != 0 && inp_user_int != 0)
        {
            num_of_digits ++;
        }
        else
        {
            break;
        }
    }

    printf("The input integer number: {%d}\n the number of digits: {%d}"
        ,inp_user_int,num_of_digits);

}

int main()
{
    counting_the_num_of_digits_of_user_input_integer();
    return 0;
}