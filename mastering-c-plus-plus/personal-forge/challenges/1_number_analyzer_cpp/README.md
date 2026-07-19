# ${\color{blue}\text{Number Analyzer}}$
## ${\color{orange}\text{Concept Explanation:}}$
This code the first finished code, it returns by printing a text, based on some features of number<br>
as "Even/Odd" and "Positive/Negative/Zero/Nan"<br>

It is not a professional way to write code, but it was a simple testing for using both pass by reference `int &user_input_num` in function `void user_input_validation(int &user_input_num)`
and using callback functions `void (*first_callback_func)(int),void (*second_callback_func)(int`
in function `void user_recursive_looping(void (*first_callback_func)(int),void (*second_callback_func)(int))`

${\color{blue}\text{Number Analyzer}}$ is program that takes a user input integer<br>
validates it using `user_input_validation()` which takes an input and undergoes a while loop<br>
until it getsn broke by the internal state flag of cin. if it is still not broken, then the internal<br>
state flag is reset `cin.clear()`, and buffer where the invalid input is stored is cleared character by character<br>
until reaching the ([Enter] or "\n") or when it has removed more than 1000 characters and not yet<br>
reaching "\n"`cin.ignore(1000, '\n')`<br>

Then uses functions: 
`void number_sign_analyzer( int user_input_num)` for printing the number's sign, it will<br>
"The user input number is positivie\negative\zero\nan" based on the number<br>
and `void number_odd_even_identifier( int user_input_num)` for printinf "even\odd" using the
modulus 2 condition logic<br>

Then the user input looping, which loops by asking the user the number and prints the analysis<br>
done, until the user responds by typing any key other than 'y' ot 'Y' when asked whether he or she<br> would like to continue inserting numbers.

The callback functions are `number_sign_analyzer` and `number_odd_even_identifier` respectively




