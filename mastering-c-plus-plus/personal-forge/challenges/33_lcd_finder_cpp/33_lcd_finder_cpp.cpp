#include <iostream>
using std::cin;

/*
Concept Explanation:
    lcm stands for "least common multiple" which receives two integer inputs and outputs one integer
    lcm(16, 42) must return the least multiple between 16 and 42.

    16 = 2* 8 =
     2 * 2 * 2  * 2 =
      2^4

    42 =
     2 * 21 =
      2 * 3 * 7
    The multiple the highest power primes:

    (2)^4 * 3 * 7 =
     16 * 3 * 7 =
      16 * 21 = 336

    Importance of lcm:
    Imagine two different lighting-sign traffic lights; one red and the other is green:
    one turns green after 30 second and the other at 60 seconds
    When will be the first time, the two traffic lights turn green.
    lcm(30, 60) = 60
    They will turn green simultaneously after 60 seconds

    15 sec red -- 15 sec green -- 15 sec red -- 15 sec red
    30 sec red -- -- -- -- -- --  30 sec green -- {Still green}
    
    There is an ancient algorithm called the Euclidean algorithm for finding the greatest common divisor (GCD) of two numbers.
    We can then use the GCD to compute the LCM.

    lcm(a, b) = (a * b)/gcd(a, b)

    Also a multiple means a result of multiplication
    so lcm tries to find the least multiple possible that can also be divided by both numbers without a floating decimal point
    lcm(32, 60) = 480
    there is no positive number smaller than 480 that is a multiple of both 32 and 60, therefore 480 is the least common multiple of 32 and 60


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
        printf("Illgetimate input, please, enter either {(Y/y) for continue or (N/n) for halting}: ");
        cin >> user_input_char;
    }
}

long long int gcd(long long int user_int_inp_1, long long int user_int_inp_2)
{
    long long int a = (user_int_inp_1 < 0) ? -user_int_inp_1 : user_int_inp_1;
    long long int b = (user_int_inp_2 < 0) ? -user_int_inp_2 : user_int_inp_2;

    if(a == 0 && b > 0) return b;
    if(b == 0 && a > 0) return a;
    if(a == b) return a;      

    long long int remainder = 0;

    while(b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

long long int lcm(long long int user_int_inp_1, long long int user_int_inp_2)
{
    long long int a = user_int_inp_1;
    long long int b = user_int_inp_2;
    return (a / gcd(a, b)) * b;
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
            printf("Please, enter the first integer: ");
            user_input_integer_validation(a);
        
            printf("Please, enter the second integer: ");
            user_input_integer_validation(b);
            a = (a < 0) ? -a : a;
            b = (b < 0) ? -b : b;

            is_both_zero = (a == 0) && (b == 0);
            if (is_both_zero) printf("Can not have two input with a value of zero, re-enter values again: \n\n");
        }while(is_both_zero);

        printf("lcm(%lli, %lli) = %lli\n", a, b, lcm(a,b));
        printf("Would you like to continue: {y/Y} for continue, {N/n} for exiting: ");
        user_choice_validation(choice);       
        printf("\n"); 
    }while(choice == 'Y' || choice == 'y');
}

int main()
{
    printf("Welcome to 'lcm' or 'least common multiple', here you input two integers and the output\nis the least multiple \n\n");
    run_time_loop();
}