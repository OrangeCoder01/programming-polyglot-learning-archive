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
    until reaching the ([Enter] or "\n"), but a limit of 1000 characters permissible to be removed,
    exceeding the limit will force halt the checking  process for ([Enter] or "\n").
    
    "\n"`cin.ignore(1000, '\n')`
```

Then uses functions: 
`void number_sign_analyzer( int user_input_num)` for printing the number's sign, it will<br>
"The user input number is positivie\negative\zero\nan" based on the number<br>
and `void number_odd_even_identifier( int user_input_num)` for printinf "even\odd" using the
modulus 2 condition logic<br>

Then the user input looping, which loops by asking the user the number and prints the analysis<br>
done, until the user responds by typing any key other than 'y' ot 'Y' when asked whether he or she<br> would like to continue inserting numbers.

The callback functions are `number_sign_analyzer` and `number_odd_even_identifier` respectively




