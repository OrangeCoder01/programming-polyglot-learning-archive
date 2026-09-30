# Task 1:
Question:
````
    Write the four intermediate bit manipulation functions:
        - Set bit.
        - Clear bit.
        - Toggle bit.
        - Check bit.
````
Explanation:
````
    Writing the four bit manipulation functions in a header file: {bit_math_c.h}
    and calling it inside the {bit_math_c.c} source file where testing the functions.
````
<br>

Why building `bit_math`:
````
    Hardware system configurations and commands are based on stream of bits
    where each bit's order/position reflect a hardware command.

    writing the function in macros is to increase the processing speed
    in order to avoid continuous call of a function in the frame stack
    inside the stack memory.
````