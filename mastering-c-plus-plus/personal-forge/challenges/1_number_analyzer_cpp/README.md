# ${\color{blue}\text{Number analyzer}}$
## ${\color{orange}\text{Concept explanation:}}$
This code is the first challenge code, it returns by printing a text, based on some features of number<br>
as "Even/Odd" and "Positive/Negative/Zero/Nan"<br>

It is not a professional way to write code, but it is for simple testing by using both pass by reference `int &user_input_num` in function `void user_input_validation(int &user_input_num)`
and using callback functions `void (*first_callback_func)(int),void (*second_callback_func)(int`
in function `void user_recursive_looping(void (*first_callback_func)(int),void (*second_callback_func)(int))`

${\color{blue}\text{Number analyzer}}$ 
```
    The "Number analyzer" program (1) receives a user input integer, (2) validates it using
    "user_input_validation()" which takes an input and undergoes a while loop
    until the conditional is falsified by the internal state flag of cin.

    In case of false conditional statement of while loop, the internal
    state flag is reset using "cin.clear()", and buffer is cleared using "cin.ignore(1000, '\n')"
    where the buffer containing the invalid input is cleared out of its storage character by character
    until reaching the ([Enter] or "\n"), but a limit of 1000 characters are permissible to be removed,
    exceeding the limit will force halting the checking process for ([Enter] or "\n").


    Then using functions: 
    (1) "void number_sign_analyzer( int user_input_num)" for printing the number's sign, it will
    "The user input number is positivie\negative\zero\nan" based on the number.
    
    (2) `void number_odd_even_identifier( int user_input_num)` for printf "even\odd" using the
    modulus 2 condition logic

    Printing the analysis done, until the user responds by typing any key other than 'y' ot 'Y',
    as a choice-based loop using user decision for rerunning the program.
```







