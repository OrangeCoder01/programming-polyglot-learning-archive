#include <iostream>
using std::cin;
#include "../../utility_functions/yassin_math.h"//new stuff

/*
Code Explanation:

The project is about bringing a program serving the user by giving list of applications that the user
use for analyzing numbers, generating numbers or performing tasks:

If the user wanted to use calculator, the program fetches calculator function and run its program until the user decided to stop.

And then again exiting to the program page, introducing the compendium of applications as:
"lcm", "gcd", "generating prime", "printing floyd triangle", and more.

This aim from the project is to combine all what is previously learned into one integerated program.

The compendium is:
1) Two number simple calculator
2) Check Palindrome
3) Largest Digit
4) Smallest Digit
5) Count a Digit
6) Check Armstrong 
7) Reverse number
8) Triangles: 
    8.1) Right-angled triangle to right
    8.2) Right-angled triangle to left
    8.3) Equalaterial Triangle:
9) Generate Prime numbers
10) Statistics toolkit
11) lcd
12) gcd

The code is cut-into sections:
1) User input validation:
2) helper functions: Tools will be used in applications:
3) User's choice depended run_time application function call:
4) Applications:
5) Menu:
6) Integrating the applications and switch-casing each one in accordance to the user's choice:

*/
unsigned const int MAX_ELEMENTS = 500;
float data_arr[MAX_ELEMENTS];


// Section(1):
// User input validation:
void user_input_number_validation(float &user_inp)
{
    while(!(cin >> user_inp))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        printf("Illegitimate input, re-enter again: ");
    }
}
void user_choice_validation(char &user_input_char)
{
    cin >> user_input_char;
    while(user_input_char != 'y' && user_input_char != 'Y' && user_input_char != 'n' && user_input_char != 'N')
    {
        printf("Illgetimate input, please, enter either {(Y/y) for continue or (N/n) for halting}: ");
        cin >> user_input_char;
    }
}

void in_list_check(char &choice)
{
    while(toascii(choice) < 97 ||toascii(choice) > 108)
    {
        if(toascii(choice) < 97 ||toascii(choice) > 108) printf("Invalid choice, enter again: "); 
        cin >> choice;
    }
}

void number_range_validator(int &num, int low_lim, int high_lim)
{
    float d = 0.0f;
    do
    {
        user_input_number_validation(d);
        if(d > high_lim || d < low_lim) printf("The input must be between %i to %i, enter again: ",low_lim ,high_lim);
    }while(d > high_lim || d < low_lim);
    num = (int)(d);
}


/////////////////////////////////////////////////////////////////////////////////////
// Section(2):
// Helper functions: Tools will be used in applications:
int calculate_number_of_digits(long long int a)
{
    int n = 0;
    if(a == 0) return 1;
    while(a != 0) {n ++; a /= 10;}
    return n;
}

long long int reverse_number(long long int input)
{
    bool is_neg = false;
    is_neg = (input < 0);
    is_neg? (input  *= -1): (input = input);
    long long int output_rev = 0;
    int n = calculate_number_of_digits(input);
    for(int i = 1; i < n + 1; i++)
    {
        int digit = ((int)(input) % 10) * (int)(pow(10.0f, (n) - i));
        input /= 10;
        output_rev += (long long int)(digit);
    }
    return is_neg? output_rev *- 1: output_rev;
}

int largest_digit(long long int input)
{
    (input < 0)? (input  *= -1): (input = input);
    int max = 0;
    input < 0? input *= -1: input = input;
    while(input > 0)
    {
        int digit = input % 10;
        if (digit > max) max = digit;
        input /= 10;
    }
    return max;
}

int smallest_digit(long long int input)
{
    (input < 0)? (input  *= -1): (input = input);
    int min = largest_digit(input);
    while(input > 0)
    {
        int digit = input % 10;
        if (digit < min) min = digit;
        input /= 10;
    }
    return min;    
}


int digit_count(long long int input, int specific_digit)
{
    (input < 0)? (input  *= -1): (input = input);
    int count = 0;
    while(input != 0)
    {
        if(specific_digit == input % 10) count ++;
        input /= 10;
    }
    return count;
}

void spacing(int limit)
{
    while(limit > 0){printf(" "); limit -- ;}
}

bool prime_checker(int input_int) 
{
    if (input_int < 2 || input_int % 2 == 0) return false;
    if (input_int == 2) return true;
    
    for (int i = 3; pow(i, 2)<= input_int; i += 2)
    {
        if (input_int % i == 0) return false;
    }
    return true;
}


float mean(float arr[], unsigned const int n)
{
    float value = 0;
    for(int i = 0; i < n; i++){value += arr[i];}
    return (value/n);
}

float stat_range(float maximium, float minimum)
{return maximium - minimum;}

float median(float arr[], unsigned const int n)
{
    bool is_even = n % 2 == 0; 
    if(is_even) return (arr[n/2] + arr[n/2 -1])/2;
    else {return arr[n/2];}
}

float mode(float arr[], unsigned const int n) 
{
    if (n == 0) return -1;

    unsigned int max_count = 1;
    unsigned int current_count = 1;
    float mode_value = arr[0];
    bool multiple_modes = false;

    for (unsigned int i = 1; i < n; i++) 
    {
        if (arr[i] == arr[i - 1]) current_count++;
        else 
        {
            if (current_count > max_count) 
            {
                max_count = current_count;
                mode_value = arr[i - 1];
                multiple_modes = false;
            } 
            else if (current_count == max_count && max_count > 1){multiple_modes = true;}
            current_count = 1; 
        }
    }
    if (current_count > max_count) 
    {
        max_count = current_count;
        mode_value = arr[n - 1];
        multiple_modes = false;
    } 
    else if (current_count == max_count && max_count > 1) {multiple_modes = true;}

    if (multiple_modes) {printf("Cannot find a single mode; multiple numbers share the highest frequency.\n"); return -1;}
    return mode_value;
}

float variance(float arr[], unsigned const int n, float mean)
{
    float var_val = 0;
    float squared_diff_arr[n];

    for(unsigned int i = 0; i < n; i ++){squared_diff_arr[i] = pow(abs(arr[i] - mean), 2);}
    
    for(int i = 0; i < n; i++){var_val += squared_diff_arr[i];}
    var_val /= n;
    return var_val;
}

float standard_deviation(float variance)
{return sqrt(variance, 2);}

void input_array(float array[], unsigned const int size)
{
    for(int i = 0; i < size; i ++)
    {   
        printf("Enter value for element {%i}: ", (i + 1));
        user_input_number_validation(array[i]);
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
float max(float arr[], int n)
{
    float max = arr[0];
    for(int i = 1; i < n; i ++){if(arr[i] > max) max = arr[i];}
    return max;
}
float min(float arr[], int n)
{
    float min = arr[0];
    for(int i = 1; i < n; i ++){if(arr[i] < min) min = arr[i];}
    return min;
}

void bubble_sort(float arr[], int n)
{
    for(int i = 0; i < (n - 1); i++)
    {
        for(int j = 0; j < (n - i - 1); j++)
        {
            if(arr[j] > arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void stat_report(float array[], int n)
{
    float maximum = max(array, n);
    float minimum = min(array, n);
    float mean_variable = mean(array, n);
    float var_val = variance(array, n, mean_variable);


    printf("\n\nStatistic Displaying: \n");
    printf("Array: ");
    print_array(array, n);
    printf("\n");
    printf("Sorted Array: ");
    bubble_sort(array, n);
    print_array(array, n);
    printf("\n");
    printf("Minimum: %f\n", minimum);
    printf("Maximum: %f\n", maximum);
    printf("Mean: %f\n", mean_variable);
    printf("Mode: %f\n", mode(array, n));
    printf("Median: %f\n", median(array, n));
    printf("Range: %f\n", stat_range(maximum, minimum));
    printf("Variance: %f\n", var_val);
    printf("Standard deviation: %f\n", standard_deviation(var_val));
}
/////////////////////////////////////////////////////////////////////
// Section(3):
// User's choice depended run_time application function call:
void run_time_application(void (*callback_func)(void)) // Callback function
{
    char choice = 'N';
    do
    {
        callback_func();
        printf("Would you like to continue: {y/Y} for continue, {N/n} for exiting: ");
        user_choice_validation(choice);       
        printf("\n"); 
    }while(choice == 'y' || choice == 'Y');
}
/////////////////////////////////////////////////////////////////////
// Section(4):
// Applications:
void two_number_simple_calculator() // #1#
{
    float a = 0;
    float b = 0;
    char operator_char = 'a';
    printf("Two Number Simple Calculator: \n");
    printf("Number {1}: ");
    user_input_number_validation(a);

    printf("\nEnter the operation:\n1) Addition (+)\n2) Subtraction (-)\n3) Multiplication (x)\n4) Division (/)\n");
    printf("Enter the operator: ");
    cin >> operator_char;
    while (operator_char != '+' && operator_char != '-' && operator_char != 'x' && operator_char != '/')
    {
        printf("Your operator does not belong to the list given above: \nRe-enter the operator: ");
        cin >> operator_char;
    }

    printf("\nNumber {2}: ");
    user_input_number_validation(b);

    float value = 0;
    bool unique_flag = false;
    
    switch (operator_char)
    {
        case '+': value = a + b; break;
        case '-': value = a - b; break;
        case 'x': value = a * b; break;
        case '/':
        {
            if (b == 0) unique_flag = true;
            else value = a / b;
            break;
        }
        default: break;
    }
    
    if (unique_flag){printf("Invalid, Division by zero"); unique_flag = false;}
    else printf("\n%.2f   %c   %.2f  =  %.2f", a, operator_char, b, value);
    printf("\n\n");    
}

void palindrome_checker() //#2#
{
    long long int number = 0;
    float a = 0;
    printf("Palindrome Number Checker: \n");
    printf("Enter the number: ");
    user_input_number_validation(a);
    number = (long long int)(a);
    
    number == reverse_number(number)? printf("It is a palindrome Number. \n"): printf("It is {not} a palindrome number. \n");
}

void find_smallest_digit()
{
    float input = 0;
    printf("This is 'The smallest digit in an integer':\nEnter the number: ");
    user_input_number_validation(input);
    printf("The smallest digit: %i\n", smallest_digit((long long int)(input)));
}

void find_largest_digit()
{
    float input = 0;
    printf("This is 'The largest digit in an integer':\nEnter the number: ");
    user_input_number_validation(input);
    printf("The largest digit: %i\n", largest_digit((long long int)(input)));    
}

void find_digit_frequency()
{
    float input = 0;
    int specific_dig = 0;
    printf("This is 'Digit frequency counter': \n");
    printf("Enter the number: ");
    user_input_number_validation(input);
    printf("Enter the digit: ");
    number_range_validator(specific_dig, 0, 9);
    printf("Digit (%i) appeared in (%lli): {%i} times\n", specific_dig, (long long int)(input), digit_count((long long int)(input + 1), specific_dig));
    // The conversion from long long int to float subtracts 1 from the original number.
}

void armstrong_checker()
{
    float input = 0;
    long long int lli_input = 0;
    printf("This is the Armstrong Number checker:\n");
    printf("Enter the number: ");
    user_input_number_validation(input);
    lli_input = (long long int)(input);

    int n = calculate_number_of_digits(lli_input);
    long long int new_number = 0;
    long long int temp = lli_input;
    while(temp > 0)
    {
        int digit = temp % 10;
        new_number += (long long int)(pow(digit, n));
        temp /= 10;
    }
    (lli_input == new_number)?(printf("%lli is an Armstrong Number\n", lli_input)):(printf("%lli is {not} an Armstrong Number\n", lli_input));
}

void reverse_app()
{
    float input = 0;
    long long int lli_input = 0;
    printf("This is the 'Reverse integers': \n");
    printf("Enter the number: ");
    user_input_number_validation(input);
    lli_input = (long long int)(input);
    printf("The number: (%lli) -- The reversed number: (%lli) \n", lli_input, reverse_number(lli_input));
}

void triangle_printing()
{
    int choice_int = 0;
    int height = 0;
    printf("This is 'Triangle printing':\n");
    printf("Enter:\n(1) For Right-angled triangle right:\n(2) For Right-angled triangle lest:\n(3) For Equalatrial triangle:\n");
    printf("Your choice: ");
    number_range_validator(choice_int, 1, 3);
    printf("Now enter the height of the pyramid between 3 to 26 (lines): ");
    number_range_validator(height, 3, 26);
    printf("\n\n");
    switch(choice_int)
    {
        case 1:
        {
            printf("\nRight-angled triangle right: \n");
            for(int i = 0; i < height; i++)
            {
                spacing(height - i);
                for(int j = 0; j <= i; j++){printf("*");}
                printf("\n");
            }
            break;
        }
        case 2:
        {
            printf("\nRight-angled triangle left: \n");
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j <= i; j++){printf("*");spacing(1);}
                printf("\n");
            }
            break;
        }
        case 3:
        {
            printf("\nEqualaterial triangle: \n");
            for(int i = 0; i < height; i++)
            {
                spacing(height - i);
                for(int j = 0; j <= i; j ++){printf("*");spacing(1);}
                printf("\n");
            }
            break;
        }
        default: break;
    }
    printf("\n\n");
}


void prime_number_generator() 
{
        float limit = 0;
        long long int lli_limit = 0;
        printf("\nPlease enter the number: ");
        user_input_number_validation(limit);
        lli_limit = (long long int)(limit);

        printf("Primes found till (%lli): [", lli_limit);
        
        bool first_prime = true;
        for (int i = 2; i <= limit; i++) 
        {
            if (prime_checker(i)) 
            {
                if (!first_prime) printf(", ");

                printf("%i", i); 
                first_prime = false;
            }
        }
        printf("]\n");
}

void stats_tool()
{
    printf("This is the statistic tool-kit: \n");
    printf("Please, enter the number of elements,\n{min: 3 max: 500}: ");
    int n = 0;
    number_range_validator(n, 3, 500);
    printf("Fill the array: ");
    input_array(data_arr, n);

    stat_report(data_arr, n);
    printf("\n\n");
}
void lcm_app()
{
    long long int lli_a = 0;
    long long int lli_b = 0;
    float c = 0.0f;
    printf("This is the 'Least common multiple': \n");

    printf("Please, enter number {1}: ");
    user_input_number_validation(c);
    lli_a = (long long int)(c);

    printf("Please, enter number {2}: ");
    user_input_number_validation(c);
    lli_b = (long long int)(c);

    printf("LCM of (%lli) and (%lli) is {%lli}\n\n", lli_a, lli_b, lcm(lli_a, lli_b));
}
void gcd_app()
{
    long long int lli_a = 0;
    long long int lli_b = 0;
    float c = 0.0f;
    printf("This is the 'Greatest common divisor': \n");

    printf("Please, enter number {1}: ");
    user_input_number_validation(c);
    lli_a = (long long int)(c);

    printf("Please, enter number {2}: ");
    user_input_number_validation(c);
    lli_b = (long long int)(c);

    printf("LCD of (%lli) and (%lli) is (%lli)\n\n", lli_a, lli_b, gcd(lli_a, lli_b));
}


/////////////////////////////////////////////////////////////////////////
// Section(5): 
// Menu:
void menu()
{
    printf("Program lists: \n");
    printf("a) Two number simple calculator:\nb) Check Palindrome:\nc) Largest Digit:\nd) Smallest Digit:\ne) Count a Digit:\nf) Check Armstrong:\ng) Reverse number:\nh) Triangles:\ni) Generate Prime numbers:\nj) Statistics toolkit:\nk) Least Common multiplier (LCD)\nl) Greatest common divisor (GCD)");
}
//////////////////////////////////////////////////////////////////////////
// Section(6): 
// Integrating the applications and switch-casing each one in accordance to the user's choice:
void integrated_applications()
{
    char choice = 'c';
    do
    {
        menu();
        printf("\nWhat is your choice: ");
        cin >> choice;
        in_list_check(choice);
        printf("\n\n");
        switch(choice)
        {
            case 'a':{run_time_application(two_number_simple_calculator);break;}
            case 'b':{run_time_application(palindrome_checker);break;}
            case 'c':{run_time_application(find_largest_digit);break;}
            case 'd':{run_time_application(find_smallest_digit);break;}
            case 'e':{run_time_application(find_digit_frequency);break;}
            case 'f':{run_time_application(armstrong_checker);break;}
            case 'g':{run_time_application(reverse_app);break;}
            case 'h':{run_time_application(triangle_printing);break;}
            case 'i':{run_time_application(prime_number_generator);break;}
            case 'j':{run_time_application(stats_tool);break;}
            case 'k':{run_time_application(lcm_app);break;}
            case 'l':{run_time_application(gcd_app);break;}
            default:{break;}                               
        }
        printf("Would you like to continue using applications: (y/Y), if you want to exit: (n/N) ");
        user_choice_validation(choice);
        printf("\n");
    }while(choice == 'y' || choice == 'Y');
}


void program()
{
    printf("Welcome to 'Multi-functions program':\nHere are the different applications: \n\n");
    integrated_applications();
    printf("\n\n");
}

int main()
{
    program();
}
