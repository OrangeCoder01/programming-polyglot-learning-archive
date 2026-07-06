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
        else{break;}
    }

    return user_inp_int_num;
}

int calc_num_of_inp_dig(int user_inp_int_num)
{
    int num_of_dig = 0;

    for(int i = 1; i < 10e12; i = i*10 )
    {
        if(user_inp_int_num == 0)
        {
            num_of_dig = 1;
            break;
        }

        if(user_inp_int_num / (i) != 0)
        {
            num_of_dig ++;
        }
        else{break;}
    }

    return num_of_dig;
}

int digit_sum(int user_inp_int_num)
{
    int num_of_dig = calc_num_of_inp_dig(user_inp_int_num);
    
    int filtered_right_to_left_int_sequence[num_of_dig + 1];

    int temp = user_inp_int_num;

    for(int i = 1; i < num_of_dig + 1; i++ )
    {
        filtered_right_to_left_int_sequence[i-1] = temp;
        temp = temp / (10);    
        //printf("sequence index {(%i)} equals: %i\n", (i-1) ,filtered_right_to_left_int_sequence[i-1]);
    }

    int filtered_left_to_right_sequence[num_of_dig + 1];
    int dummy_array[num_of_dig + 1]; //  it is for learning sizeof() C++ concept

    for(int i = 0; i < sizeof(dummy_array)/sizeof(dummy_array[0]) - 1; i++)
    {
        filtered_left_to_right_sequence[i] = filtered_right_to_left_int_sequence[i];
    }

    for(int i = num_of_dig - 1; i >= 0; i--)
    {
        filtered_left_to_right_sequence[i] = filtered_right_to_left_int_sequence[i] % (10);
        filtered_right_to_left_int_sequence[i + 1] = filtered_left_to_right_sequence[i];

       // printf("sequence index {(%i)} equals: %i\n", (i) ,filtered_left_to_right_sequence[i]);
    }

    int sum = 0;
    for(int i = 0; i < num_of_dig; i++)
    {
        sum = sum + filtered_left_to_right_sequence[i];
    }

    return sum;

}

int main()
{
    int summing_individualistic_digits = 0;
    int user_inp_int_num = input_user_interface();
    summing_individualistic_digits = digit_sum(user_inp_int_num);
    printf("The sum of every individualistic digits in the input number: (%i)\n", summing_individualistic_digits);
    return 0;
}