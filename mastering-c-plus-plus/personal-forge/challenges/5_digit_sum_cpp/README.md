# ${\color{blue}\text{Digit Sum}}$
## ${\color{orange}\text{Concept Explanation}}$:
${\color{blue}\text{Digit Sum}}$ is simply taking every digits of a validated user input integer, and summing them up.<br>
Function `int calc_num_of_inp_dig(int user_inp_int_num)` takes the user's valid input integer and returns the number of digits<br>
Function `int digit_sum(int user_inp_int_num)` takes a valid user's input, uses `int calc_num_of_inp_dig(int user_inp_int_num)` to
calculate the number of digits of that input then using:
${\color{red}\text{Left}}$ `_` ${\color{red}\text{to}}$ `_` ${\color{red}\text{right}}$ and
${\color{blue}\text{right}}$ `_` ${\color{blue}\text{to}}$ `_` ${\color{blue}\text{left}}$ filtering method:<br>

filtered `_` ${\color{red}\text{Left}}$ `_` ${\color{red}\text{to}}$ `_` ${\color{red}\text{right}}$ `_` sequence takes the input
and filtered `_` ${\color{blue}\text{right}}$ `_` ${\color{blue}\text{to}}$ `_` ${\color{blue}\text{left}}$ `_` sequence
places every index in the array a different copy of the input integer with different stages of integer division and according to the direction of integer division:

${\color{pink}\text{for example:}}$<br>
input : 9623, ${\color{blue}\text{filtered}}$ `_` ${\color{blue}\text{right}}$ `_` ${\color{blue}\text{to}}$ `_` ${\color{blue}\text{left}}$ `_` ${\color{blue}\text{sequence}}$ 
= `[9623, 623, 23, 3]`<br>
input : 9623, ${\color{red}\text{filtered}}$ `_` ${\color{red}\text{Left}}$ `_` ${\color{red}\text{to}}$ `_` ${\color{red}\text{right}}$ `_` ${\color{red}\text{sequence}}$ 
= `[9, 96, 962, 9623]`<br>

so the idea is to peform the ${\color{blue}\text{first}}$ operation and use it as input for the ${\color{red}\text{second}}$:<br>
input = 3572593 ➡️ `[3572593 357259 35725 3572 357 35 3 ]` ➡️ `[3,5,7,2,5,9,3]`<br>

The final output is hold in ${\color{red}\text{filtered}}$ `_` ${\color{red}\text{Left}}$ `_` ${\color{red}\text{to}}$ `_` ${\color{red}\text{right}}$ `_` ${\color{red}\text{sequence}}$ <br>
by looping through it, and summing every digit, finally the sum is returned



