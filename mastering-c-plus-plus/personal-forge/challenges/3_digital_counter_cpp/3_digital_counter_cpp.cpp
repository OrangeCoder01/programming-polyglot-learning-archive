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

void counting_users_num_of_digits_of_integer()
{
    char char_array[100];
    int num_of_dig = 0;
    int user_inp_int_num = input_user_interface();

    int user_int_array_holder[100];

    sprintf(char_array, "%d", user_inp_int_num);

    bool is_above_zero_contained = false;
    bool is_below_nine_contained = false;
    bool is_contained = false;

    for(int i = 0; char_array[i] != '\0'; i++ )
    {
        user_int_array_holder[i] = char_array[i] - '0';
    }

    for(int i = 0; char_array[i] != '\0'; ++i)
    {
        user_int_array_holder[i] >= 0 ? is_above_zero_contained = true: is_above_zero_contained = false;
        user_int_array_holder[i] <= 9 ? is_below_nine_contained = true: is_below_nine_contained = false;
        is_contained = is_above_zero_contained && is_below_nine_contained;

        if(is_contained)
        {
            num_of_dig ++;
        }
    }

    printf("Your input number: {%d}\n",user_inp_int_num);
    printf("and the corresponding number of digits: {%d}\n",num_of_dig);

}

int main()
{
    counting_users_num_of_digits_of_integer();
}