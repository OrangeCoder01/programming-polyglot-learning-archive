# ${\color{blue}\text{Number Mirror}}$
## ${\color{orange}\text{Concept Explanation}}$
${\color{blue}\text{Number Mirror}}$ simply takes an input integer from the user and returns the flipped or reversed number<br>
${\color{pink}\text{for example}}$: Input: 125678, Output: 876521<br>

The first block is the `int user_input_integer_num()` function which checks the user's input is integer and also checks the if the user<br>
would like to even enter a number.<br>

The second block is the `converting_integer_to_character_array_with_reversing(char char_array[100])` which takes a char_array with 
a constant buffer set by 100. This char_array holds the integer digits in its buffer:<br>
${\color{pink}\text{for example}}$: 29472 is interpreted into char\_array using sprintf by filling each index of the array with<br>
a char representation of the digit, meaning, if a number is 19053 then its mapping into char\_array will be `['1','9','0','5','3']`<br>

then calculating the number of digits by looping until reaching the null terminator '\0' <br>

then putting those chars into another arrays called stored\_char\_array which holds all the chars and adding a null terminator '\0'<br>
by using the length of array calculated `length_char` as an index,<br>

After storing the digits, the char\_array is used in a for loop that uses the stored\_char\_array as reference to replace the places of the digits <br>
from the last element to the first inside char\_array.

Finally using `printf()` to print the reversed integer





