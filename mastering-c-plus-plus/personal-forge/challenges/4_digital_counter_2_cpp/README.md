# ${\color{blue}\text{Digital Count 2}}$
## ${\color{orange}\text{Concept Explanation}}$:
In this code, I replaced digit count using arrays to using integer division method<br>
There are two blocks:<br>
First: `int input_user_interface()` that returns a validated input integer<br>
Second: `void counting_the_num_of_digits_of_user_input_integer()` that returns the number of the digits of the received input.<br>

${\color{pink}\text{for example }}$: Input: 1924 -> 1924/10 ---->> 192 -> 192/10 ---->> 19 -> 19/10 ---->> 1 -> 1/2 -----> 0<br>
In this ${\color{pink}\text{example}}$ using integer division removes and integer, so utilizing a very big for loop
that starts from i = 1 and breaks when i > (10e24) which is 10²⁴ and iterating by multiplicating by 10
and if the result from the integer division is not yet zero, the num_of_dig is iterated.

