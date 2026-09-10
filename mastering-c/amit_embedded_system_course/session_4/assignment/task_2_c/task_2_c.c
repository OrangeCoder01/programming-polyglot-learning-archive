#include <stdio.h>

char user_choice_validation(char user_choice, char option_1, char option_2)
{
    do
    {
        printf("Please, choose '%c' or '%c': ", option_1, option_2); scanf(" %c", &user_choice);

        if(user_choice == option_1 || user_choice == option_2) { break; }
        else { printf("\n\nInput '%c' is illegitimate: must be either: '%c' or '%c'\n", user_choice, option_1, option_2); }

    }while(1);

    return user_choice;
}

float addition(float num_1, float num_2) { return num_1 + num_2; }
float multiplication(float num_1, float num_2) { return num_1 * num_2; } 
float subtraction(float num_1, float num_2) { return num_1 - num_2; }
float division(float num_1, float num_2) { return num_1 / num_2; }


int main(void)
{
    char user_decision = 'a';
    float user_num_1 = 0, user_num_2 = 0, result = 0;
    int is_valid = 1;

    do
    {
        printf("Please, enter the first number: "); scanf(" %f", &user_num_1);
        
        printf("Please, enter the operator: `+`, '-', '*', '/': "); scanf(" %c", &user_decision);

        printf("Please, enter the second number: "); scanf(" %f", &user_num_2);



        switch(user_decision)
        {
            case '+':
            { 
                result = addition(user_num_1, user_num_2);
                break; 
            }
            case '-':
            { 
                result = subtraction(user_num_1, user_num_2); 
                break;
            }
            case '*':
            {  
                result = multiplication(user_num_1, user_num_2);
                break;
            }
            case '/':
            {
                if (user_num_2 == 0) 
                {
                    printf("Can not divide by zero \n");
                    is_valid = 0;
                }
                else { result = user_num_1 / user_num_2; }
                break;
            }
            default:
            {  
                printf("Invalid operator\n");
                is_valid = 0;
                break;
            }
        }
        
        
        if(is_valid) { printf("\n %.2f %c %.2f = %.2f", user_num_1, user_decision, user_num_2, result); }

        printf("\nType '%c' for to continue or type '%c' to halt:\n ", 'y', 'n');
        user_decision = user_choice_validation(user_decision, 'y', 'n');
        is_valid = 1;


    }while(user_decision == 'y');
    
    return 0;
}
