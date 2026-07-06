#include <iostream>
using std::cin;

int input_user_integer()
{
    int inp_user_int = 0;
    printf("Please, Enter your input integer: ");
    while (true)
    {
        if (!(cin >> inp_user_int)){printf("Illegal Input, retry again: ");}
        else{break;}
    }
    return inp_user_int;
}

bool Negative_sign_checker_for_integer(int inp_user_int)
{
    bool is_negative = false;
    (inp_user_int < 0)? is_negative = true :is_negative = false;
    return is_negative;
}

int calculate_the_number_of_digits(int inp_user_int)
{
    int num_of_digits_with_sign = 0;
    bool is_negative = Negative_sign_checker_for_integer(inp_user_int);
    //is_negative == true? printf("It is negative\n"):printf("Its is positive\n"); 

    
    for (int i = 10; i < 10e8; i = i * 10)
    {  
        //static int j = 0;
        num_of_digits_with_sign ++;
        //printf("Index (%i) ---> digit: {%i}:\n", j, num_of_digits_with_sign );
        //j ++;
        if (inp_user_int == 0 || inp_user_int/(i) == 0){break;}
    }

    num_of_digits_with_sign = num_of_digits_with_sign + is_negative;
    return  num_of_digits_with_sign;
}

int reversing_the_input_integer_order(int inp_user_int, int num_of_digits_with_sign)
{
    inp_user_int = input_user_integer();
    num_of_digits_with_sign = calculate_the_number_of_digits(inp_user_int);

    bool is_negative = Negative_sign_checker_for_integer(inp_user_int);
    int int_user_arr[num_of_digits_with_sign];
    int divider = 1;

    // 1) Sample & invert,
    // 2) Convert int array to char array,
    // 3) concatenate,
    // 4) revert back to int

    // This samples the integer into an array plus it samples from reverse order
    int negative_inverter = 0;
    is_negative? negative_inverter=-1: negative_inverter=1;

    for(int i = 0; i < (num_of_digits_with_sign - is_negative); i++)
    {
        int_user_arr[i] =  (negative_inverter) * ( ( ( inp_user_int ) / divider ) % 10 );
        divider = 10 * divider;
        printf("\nDigit in index [%i], int value: ---> {%i}\n", i, int_user_arr[i]);
    }
    printf("\n\n");
    // This converts into char array
    char converted_to_char_arr[num_of_digits_with_sign + 1];
    converted_to_char_arr[num_of_digits_with_sign] = '\0';

    for(int i = 0; i < num_of_digits_with_sign; i++)
    {
        if(is_negative && i == 0)
        {   
            converted_to_char_arr[0] = '-';
            converted_to_char_arr[num_of_digits_with_sign] = int_user_arr[0] + '0';
            printf("char in index [%i], Char: ---> {%c}\n", i, converted_to_char_arr[i]);
            continue;
        }
        printf("Digit in index [%i], int value: ---> {%i}\n", i-is_negative, int_user_arr[i-is_negative]);
        converted_to_char_arr[i] = int_user_arr[i-is_negative] + '0';
        printf("char in index [%i], Char: ---> {%c}\n", i, converted_to_char_arr[i]);
    } 

    //This will concatenate the elements in the char array into a singular string unit
    int reversed_user_int = 0;
    printf("\n\n");
    for(int j = 0; !(converted_to_char_arr[j] == '\0'); j++)
    {
        if(j > (num_of_digits_with_sign - is_negative)){break;}
        if(converted_to_char_arr[j] == '-'){continue;}
        reversed_user_int = 10*(reversed_user_int) + (converted_to_char_arr[j] - '0');
        printf("Current index {%i}: ---->>> Char: {%c}\t", j , converted_to_char_arr[j]);
        printf(" ---->>> +ve Int: {%i}\n" ,reversed_user_int);

        // Think of an input: 18394,
        // @1st iter.:   = 10*(0) + ('4' - '0') ----> 4
        // @2nd iter.:   = 10*(4) + ('9' - '0') ----> 49
        // @3rd iter.:   = 10*(49) + ('3' - '0') ----> 493
        // @4th iter.:   = 10*(493) + ('8' - '0') ----> 4938
        // @5th iter.:   = 10*(4938) + ('1' - '0') ----> 49381
    }

    if(is_negative)
    {
        reversed_user_int = (-1)*reversed_user_int;
    }

    return reversed_user_int;
}

int main()
{
    int inp_user_int = 0;
    int num_of_user_inp_int_dig = 0;

    //printf("\nThe num of digits is/are: {%i}\n", calculate_the_number_of_digits(inp_user_int));
    //printf("\nThe integer order is: {%i}\n", inp_user_int);
    printf("\nThe reversed integer order is: {%i}\n", reversing_the_input_integer_order(inp_user_int, num_of_user_inp_int_dig));

}