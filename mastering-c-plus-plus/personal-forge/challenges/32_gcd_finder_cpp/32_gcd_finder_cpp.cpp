#include <iostream>
using std::cin;

/*
Code Explanation:
    gcd stands for "greatest common divisor" which receives two integer inputs and outputs one integer
    gcd(16, 42) must return the greatest divisor between 16 and 42 that does not result into a fraction
    
    {2} works for 16 as 16/2 = 8 || 2 works for 42 as 42/2 = 21
    3 does not work for 16 as 16/3 = fraction || 2 works for 42 as 42/3 = 14
    4 works for 16 as 16/4 = 4 || 4 does not work for 42 as 42/4 = fraction
    8 works for 16 as 16/8 = 2 || 8 does not work for 42 as 42/8 = fraction
    greatest common divisor is 2  
*/
void user_input_integer_validation(long long int &user_int_inp)
{
    while(!(cin >> user_int_inp))
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
        printf("Illgitimate input, please, enter either {(Y/y) for continue or (N/n) for halting}: ");
        cin >> user_input_char;
    }
}

long long int gcd(long long int user_int_inp_1, long long int user_int_inp_2)
{
    if (user_int_inp_1 < 0) user_int_inp_1 *= -1;
    if (user_int_inp_2 < 0) user_int_inp_2 *= -1;
    if(user_int_inp_1 == user_int_inp_2) return user_int_inp_1;      
    
    if (user_int_inp_1 == 0) return user_int_inp_2;
    if (user_int_inp_2 == 0) return user_int_inp_1;


    long long int a = (user_int_inp_1);
    long long int b = (user_int_inp_2);

    long long int quotient = 0;
    
    long long int remainder = 0;

    while(true)// I made the list of printfs for debugging, but I will keep it for any one who wants to understand Eulcidean method in finding the 'gcd'.
    {
        quotient = a/b;
        printf("Quotient: %lli\t", quotient);
        remainder = a % b;
        printf("Remainder: %lli\t", remainder);
        if(remainder == 0){return b;}
        a = b;
        b = remainder;
        printf("b: %lli\t", b);
        printf("a: %lli\n", a);
    }
}

void run_time_loop()
{
    char choice = 'N';
    do
    {
        long long int a = 0;
        long long int b = 0;
        bool is_both_zero = false;
        do{
            printf("Please, enter the first integer: \n");
            user_input_integer_validation(a);
        
            printf("Please, enter the second integer: \n");
            user_input_integer_validation(b);
            a = (a < 0) ? -a : a;
            b = (b < 0) ? -b : b;

            is_both_zero = (a == 0) && (b == 0);
            if (is_both_zero) printf("Can not have two input with a value of zero, re-enter values again: \n\n");
        }while(is_both_zero);

        printf("\ngcd(%lli, %lli) = %lli\n", a, b, gcd(a,b));
        printf("Would you like to continue: {y/Y} for continue, {N/n} for exiting: ");
        user_choice_validation(choice);        
    }while(choice == 'Y' || choice == 'y');
}

int main()
{
    printf("Welcome to 'gcd' or 'Greatest common divsior', here you input two integers and the output\nis the greatest possible integer divider for both integers without resulting into a fractions\n\n");
    run_time_loop();
}