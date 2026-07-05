#include <iostream>
#include <string>
using ::std::cin;
using ::std::cout;
using ::std::endl;

void user_input_validation(int &user_input_num)
{

 while(true)
    {
    printf("Please, enter a number to analyze: ");
    if(!(cin >> user_input_num))
        {
        cout << "Please enter a valid integer.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        }
    else
     {
        break;
     }
    }
}

void user_recursive_looping(void (*first_callback_func)(int),void (*second_callback_func)(int))
{
    int user_input_num;
    char user_choice = 'y';
    do
    {
        user_input_validation(user_input_num);
        first_callback_func(user_input_num);
        second_callback_func(user_input_num);
        std::printf("Do you want to continue? {Y} or {y} for (continue) and any other key for (no):");
        cin >> user_choice;
    }
    while(user_choice == 'y'|| user_choice == 'Y');
}

void number_odd_even_identifier( int user_input_num)
{
    std::string result = "";
    if(user_input_num % 2 == 0)
    {
        result = "even";
    }
    else  
    {
        result = "odd";
    }

    std::printf("The user input number:( %d ) is %s\n", user_input_num, result.c_str());
}


void number_sign_analyzer( int user_input_num)
{

    if(user_input_num > 0)
    {
        cout<<"The user input number is positive"<<endl;
    }
    else if(user_input_num < 0)
    {
        cout<<"The user input number is negative"<<endl;
    }
    else if (user_input_num == 0)
    {
        cout<<"The user input number is zero"<<endl;
    }
    else
    {
        cout<<"The user input number is nan"<<endl;
    }
}

int main()
{
   user_recursive_looping(number_sign_analyzer,number_odd_even_identifier);
    return 0;
}
