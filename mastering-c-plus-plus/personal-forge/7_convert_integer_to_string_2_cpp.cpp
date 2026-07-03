#include <iostream>
#include <string>
using std::cin;
using std::string;


void user_input_integer_validation(int &user_ip_int)
{
    printf("Please, enter an integer number: ");

    while (true)
    {
        if (!(cin >> user_ip_int))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            printf("Invalid integer number, insert again: ");
        }
        else
        {
            break;
        }
    }
}

void number_to_string(int &user_ip_int)
{
  user_input_integer_validation(user_ip_int);
  string converted_to_string = std::to_string(user_ip_int);

  printf("\nThe integer is: {%i}\nIts string: {%s}\n", user_ip_int, converted_to_string.c_str());

}



int main()
{
    int user_ip_int = 0;
    number_to_string(user_ip_int);
    
}