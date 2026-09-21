# Task 5:
Question:
```
    (5) Write a program to reverse a number.
```
Explanation:
```
    The program prints the reversed user input integer number; digit by digit.
    The Algorithm:

        The program first calculates the number of digits (number_of_digits) by using
        a temporary variable (temp) that is initialized by the value of the
        user input integer (user_number). 
        while {temp > 0} where the temporary variable loses one digit each new iteration {temp /= 10}
        whilst the number of digits increments by 1 {number_of_digits += 1}.


    For example:

        (user_number) = 209462.
        (temp) = (user_number) = 209462.

        Calculating number of digits:

            {temp > 0} = true ---> {temp /= 10} ---> (temp) = 209462 ---> (number_of_digits) = 1.
            {temp > 0} = true ---> {temp /= 10} ---> (temp) = 20946 ---> (number_of_digits) = 2.
            {temp > 0} = true ---> {temp /= 10} ---> (temp) = 2094 ---> (number_of_digits) = 3.
            {temp > 0} = true ---> {temp /= 10} ---> (temp) = 209 ---> (number_of_digits) = 4.
            {temp > 0} = true ---> {temp /= 10} ---> (temp) = 20 ---> (number_of_digits) = 5.
            {temp > 0} = true ---> {temp /= 10} ---> (temp) = 2 ---> (number_of_digits) = 6.
            {temp > 0} = true ---> {temp /= 10} ---> (temp) = 0 ---> (number_of_digits) = 7.
            {temp > 0} = False ---> exit loop.
        
        

        Then the (multiplier) get assigned and multiplied by 10 in each iteration with respect to the {number_of_digits - 1};
        the minus 1 is for the extra incrementation of number_of_digits when temp = 0.



        Three other variables are initialized:

            (Multiplier) is initialized by 1 and get multiplied by 10 in each iteration in the next while loop.
            (rev_user_number) is initialized by 0 and gets added by a digit each iteration in the next loop.
            (digit) is initialized by 0 and is assigned to the extracted digit from the number.

        Step (1): Using {digit = temp % 10} to extract the least significant digit.
        Step (2): Assignment and adding (rev_user_number) with (digit *multiplier) to append the digit in the correct digital order (ones, tens, thousands, etc...).
        Step (3): Dividing {temp /= 10} and {multiplier /= 10}, and incrementing by iterator {i += 1}.
    
            
        

        Re-intializing the temporary variable and iterator:

            {temp = user_number}.
            {i = 0}.


        Reversing the number (from terminal after using the commented out debugging code line):
            

            temp = 209462, rev_user_number = 200000, digit = 2, multiplier = 100000. ---> (i  = 1).
            temp = 20946, rev_user_number = 260000, digit = 6, multiplier = 10000. ---> (i  = 2).
            temp = 2094, rev_user_number = 264000, digit = 4, multiplier = 1000. ---> (i  = 3).
            temp = 209, rev_user_number = 264900, digit = 9, multiplier = 100. ---> (i  = 4).
            temp = 20, rev_user_number = 264900, digit = 0, multiplier = 10. ---> (i  = 5).
            temp = 2, rev_user_number = 264902, digit = 2, multiplier = 1. ---> (i  = 6).

```
Input:
```
    (1) The integer number which the user inputted.
```
Output:
```
    (1) The printing of the reversed integer of the input integer.
```
Why building this program:
```
    Implementing algorithmic strategies to extract the digit and correctly placing its corresponding order, requires understanding of modulus, integer division, and
    iterative control flow for managing the correct the correct number of iterations.
```