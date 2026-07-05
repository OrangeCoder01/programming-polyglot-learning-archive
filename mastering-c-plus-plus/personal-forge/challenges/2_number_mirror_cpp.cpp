#include <iostream>
using std::cin;
using std::cout;

int user_input_integer_num()
{
    char choice;
    std::printf("Would you like to enter an integer number? (Y/N): ");
    cin >> choice;

    int user_inp_int_num = 0;
    bool break_loop = false;

    if (choice != 'Y' && choice != 'y')
    {
        std::printf("You chose not to enter an integer number. Exiting the program.\n");
        exit(0);
    }

    do
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
            std::printf("You entered: %d\n", user_inp_int_num);
            break_loop = true;
        }

    } while (!break_loop);

    return user_inp_int_num;
}

void converting_integer_to_character_array_with_reversing(char char_array[100])
{
    int length_char = 0;
    int user_inp_int_num = user_input_integer_num();
    std::sprintf(char_array, "%d", user_inp_int_num);

    char stored_char_array[100];

    for (int i = 0; char_array[i] != '\0'; ++i)
    {
        length_char++;
        stored_char_array[i] = char_array[i];
    }

    stored_char_array[length_char] = '\0';

    cout << "Length of the character array is: " << length_char << "\n";

    for (int i = 0; char_array[i] != '\0'; i++)
    {
        char_array[i] = stored_char_array[length_char - i - 1];
    }
    char_array[length_char] = '\0';

    std::printf("The original character array is: %s\n", stored_char_array);
    std::printf("The reversed character array is: %s\n", char_array);
}

int main()
{
    char buffer[100];
    converting_integer_to_character_array_with_reversing(buffer);
}