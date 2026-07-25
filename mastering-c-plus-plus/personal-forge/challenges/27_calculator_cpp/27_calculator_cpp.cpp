#include <iostream>
using std::cin;

double user_input_number_validation()
{
    double user_double_numer_input = 0;
    while (!(cin >> user_double_numer_input))
    {
        printf("Illegitimate integer input, enter the value again: ");
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return user_double_numer_input;
}

double addition(double a, double b) { return (a + b); }
double subtraction(double a, double b) { return (a - b); }
double multiplication(double a, double b) { return (a * b); }
double division(double a, double b) { return (a / b); }

char user_choice_validator(char choice)
{
    cin >> choice;
    while (choice != 'Y' && choice != 'N')
    {
        printf("Illegitimate char input, Enter 'Y' for continuation or 'N' for exiting: ");
        cin >> choice;
    }
    return choice;
}

void calculator()
{
    double a = 0;
    double b = 0;
    char operator_char = 'a';

    printf("Number {1}: ");
    a = user_input_number_validation();

    printf("\nEnter the operation:\n1) Addition (+)\n2) Subtraction (-)\n3) Multiplication (x)\n4) Division (/)\n");
    printf("Enter the operator: ");
    cin >> operator_char;
    while (operator_char != '+' && operator_char != '-' && operator_char != 'x' && operator_char != '/')
    {
        printf("Your operator does not belong to the list given above: \nRe-enter the operator: ");
        cin >> operator_char;
    }

    printf("\nNumber {2}: ");
    b = user_input_number_validation();

    double value = 0;
    bool unique_flag = false;
    
    switch (operator_char)
    {
        case '+':
        {
            value = addition(a, b);
            break;
        }
        
        case '-':
        {
            value = subtraction(a, b);
            break;
        }
        
        case 'x':
        {
            value = multiplication(a, b);
            break;
        }
        
        case '/':
        {
            if (b == 0)
            {
                unique_flag = true;
            }
            else
            {
                value = division(a, b);
            }
            break;
        }
        
        default:
        break;
    }
    
    if (unique_flag)
    {
        printf("Invalid, Division by zero");
        unique_flag = false;
    }
    else
    {
        printf("\n%f   %c   %f  =  %f", a, operator_char, b, value);
    }
    printf("\n\n");
}

void looping()
{
    char choice = 'N';
    do
    {
        calculator();
        printf("Would you like to continue, type 'Y' for to continue, otherwise 'N': ");
        choice = user_choice_validator(choice);

    } while (choice != 'N');
}

int main()
{
    printf("Welcome to 'Simple Calculator', your are meant to enter two numbers and the operator\nThe output is the result of the operation. \n\n");
    looping();
}