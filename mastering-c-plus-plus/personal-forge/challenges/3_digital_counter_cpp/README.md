# ${\color{blue}\text{Digital Counter}}$:
## ${\color{orange}\text{Concept Explanation}}$:
${\color{blue}\text{Digital Counter}}$ code takes a valiated user input integer and outputs the number of the digits.<br>
Using sprintf() mapping of the integer input `user_inp_int_num` and every digit is placed as a char in corresponence to array's index `char_array`<br>

Then adding a method to escape the negative sign "-", by using three booleans, first boolean `is_above_zero_contained` which checks if a number<br>
is more than 0, same thing with `is_below_nine_contained` for checking that the number is less than 9.<br>
Then boolean is_contained which is the result of the logical AND of both boolean.<br>
Using `is_contained` to decide either to add the number of digits count or not.<br>





