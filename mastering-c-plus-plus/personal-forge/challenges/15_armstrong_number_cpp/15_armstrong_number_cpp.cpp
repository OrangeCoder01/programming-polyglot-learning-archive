#include <iostream>
using std:: cin;

int user_int_validation()
{
    int user_inp_int = 0;
    printf("Please, enter the number integer: ");
    while(true)
    {
        if(!(cin >> user_inp_int))
        {
            printf("Invalid, input, try again!");
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else{break;}
    }
    return user_inp_int;
}


long int armstrong_mathematics(int user_inp_int)
{
    bool can_continue = true;
    if(user_inp_int < 0){user_inp_int *= -1;}
    if(user_inp_int == 0){return 0;}
    int temp = user_inp_int;
    long int value = 0;
    int num_of_dig = 0;

    while(can_continue)
    {
        if(temp != 0)
        {
            temp /= 10;
            num_of_dig ++;
        }
        else{can_continue = false;}
    }
    can_continue = true;
    temp = user_inp_int;

    while(can_continue)
    {
        if(temp == 0){can_continue = false;break;}
        long int base_digit = temp % 10;
        temp /= 10;

        long int temp_power = base_digit;


        for(int j = 1; j < num_of_dig; j++)
        {
            long int current_power = 0;
            for(int k = 0; k < base_digit; k++)
            {
                current_power += temp_power;
            }
            temp_power = current_power;
        }
        value += temp_power;
    }

    return value;
}

void armstrong_number_validator(int user_inp_int)
{
    long int armst_value = armstrong_mathematics(user_inp_int);
    armst_value == user_inp_int? printf("an Armstrong number"): printf("Not an Armstrong number");
}

int main()
{
    printf("Welcome, This is the Armstrong number challenge:\n");
    int user_inp_input = user_int_validation();
    printf("the Armstrong number for: {%i} is: {%li}, and it is: ", user_inp_input, armstrong_mathematics(user_inp_input));
    armstrong_number_validator(user_inp_input);
}
