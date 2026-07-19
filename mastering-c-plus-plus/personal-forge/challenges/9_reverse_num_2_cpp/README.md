# ${\color{red}\text{Reverse Number 2}}$
## ${\color{orange}\text{Concept Explanantion:}}$
${\color{red}\text{Reverse Number 2}}$ is different than # ${\color{red}\text{Reverse Number 1}}$
as it does not use array in storing, and does not convert to char, and then concatenate.<br>
It only uses three digit manipulation operators: (*10), (/10) and (%10)<br>

The function `reversing_the_input_integer_order(int inp_user_int, int num_of_digits_with_sign)`<br>
takes the input, its number of digits and a boolean to check whether is negative or not.
using the boolean, to revert the number to positive, and using it later to revert the positive reersed number back to negative<br>

This part, is responsiblr for building the reversed integer:<br>

```
    for(int i = 0 ; i < num_of_digits_with_sign - is_negative; i ++)
    {
        result = (result*10) + (temp)%10;
        temp = temp/10;
    }
```
<br>
initializing with result = 0 outside the loop: let input = 6834<br>
result = 0*10 + (6834%10) ➡️ 0 + 4 = 4 ----> temp = 6834 / 10 = 683<br>
result = 4*10 + (683%10)  ➡️ 40 + 3 = 43 ----> temp = 683 / 10 = 68<br>
result = 43*10 + (68%10)  ➡️ 430 + 8 = 438 ----> temp = 68 / 10 = 6<br>
result = 438*10 + (6%10)  ➡️ 4380 + 6 = 4386 ----> temp = 6 / 10 = 0<br>




