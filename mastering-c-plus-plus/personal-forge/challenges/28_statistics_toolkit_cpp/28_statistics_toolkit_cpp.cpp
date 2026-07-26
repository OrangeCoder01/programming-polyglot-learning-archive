#include <iostream>
using std::cin;

// "Validation and inputing functions" section:
float user_input_validation(float num, int integer, char choice)
{   
    if(choice == '1')
    {
        while(!(cin >> num) || !(-1048575.0 <= num <= 1048575.0))
        {
            if(!cin){printf("Illegitimate float Input, enter again: ");}
            else{printf("Your number: {%i} is out of range {-1048575 to 1048575}, enter again: ", num);}
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return num;
    }
    else
    {
        while(!(cin >> integer) || (integer <= 0))
        {
            if(!cin){printf("Illegitimate integer Input, enter again: ");}
            else{printf("The number must be more than zero, enter again: ");}
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return (float)(integer);
    }
}

void input_size(unsigned int &size)
{size = (unsigned int)(user_input_validation(0, size, '2'));}


void input_array(float array[], unsigned const int size)
{
    for(int i = 0; i < size; i ++)
    {   
        printf("Enter value for element {%i}: ", (i + 1));
        array[i] = user_input_validation(array[i], 0, '1');
    }
}

void print_array(float array[], unsigned const int size)
{
    printf("[");
    for(unsigned int i = 0; i < size; i++)
    {  
         printf("%f", array[i]);
        if(i < (size - 1))
        {
            printf(", ");
        }
    }
    printf("]");
}


//Annoncing the idea of the challenge:
void declaration()
{
    printf("\nWelcome to 'Statistic Tool-kit Program',\nHere, you choose to enter a set of numbers to an array,\nAnd the output is full statistic table from:\n1)Minimum element:\n2)Maximum element:\n3)Mean:\n4)Mode:\n5)Median:\n6)Range:\n7)Standard deviation:\n8)Variance:");
    printf("\n\nRules:\n1)Elements can not exceed 1048575 or lower than -1048575.\n2)You must restart the program to initialize a new statisitc analysis.\n\n");
}

//Important math operations:
float float_pow(float element, int power)
{
    float value = element;
    for(int i = 1; i < power; i++)
    {value *= element;}
    return value;
}

float flooring(float element, int decimal_point)
{
    int value = element * float_pow(10, decimal_point);
    float new_f_value = (float)(value) / float_pow(10, decimal_point);
    return new_f_value;
}




int main()
{
    declaration();
    printf("Please, enter number of elements in array: ");
    unsigned int size = 0;
    input_size(size);

    unsigned const int constant_size = size;

    printf("\n\n");
    printf("Fill the elements in array: \n");
    float array[constant_size];
    input_array(array, constant_size);

    printf("\n\nStatistic Displaying: ");

    return 0;
}