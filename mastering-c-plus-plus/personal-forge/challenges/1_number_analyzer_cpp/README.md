# ${\color{blue}\text{Number Analyzer}}$
## ${\color{orange}\text{Code Explanation:}}$
This code the first finished code, it returns by printing a text, based on some features of number<br>
as "Even/Odd" and "Positive/Negative/Zero/Nan"<br>

${\color{blue}\text{Number Analyzer}}$ is program that takes a user input integer<br>
validates it using `user_input_validation()` which takes an input and undergoes a while loop<br>
until it getsn broke by the internal state flag of cin. if it is still not broken, then the internal<br>
state flag is reset `cin.clear()`, and buffer where the invalid input is stored is cleared character by character<br>
until reaching the ([Enter] or "\n") or when it has removed more than 1000 characters and not yet<br>
reaching "\n"`cin.ignore(1000, '\n')`
