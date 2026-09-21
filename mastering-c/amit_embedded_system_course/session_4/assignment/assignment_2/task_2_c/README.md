# Task 2:
Question:
```
    (2) Write a program that reads a positive integer and
        checks if it is a perfect square.
```
Explanation:
```
    The program validates if the input integer a perfect square or not:
    The Algorithm:

        Starting with iteration "i = 0", until reaching that i * i < (user input integer number)
        and incrementing by one; such that breaking the loop happens when either i * i = input integer
        which indicates that the integer is indeed a prime number or when it is more than the input integer (i * i > input integer).

    For example:
        Number = 25.

        i = 0: (0 * 0) = 0
        i = 1: (1 * 1) = 1
        i = 2: (2 * 2) = 4
        i = 3: (3 * 3) = 9
        i = 4: (4 * 4) = 16
        i = 5: (5 * 5) = 25 --> Loop breaks

        The Number "25" is a perfect square.

    Another example:
        Number = 44.
        i = 0: (0 * 0) = 0
        i = 1: (1 * 1) = 1
        i = 2: (2 * 2) = 4
        i = 3: (3 * 3) = 9
        i = 4: (4 * 4) = 16
        i = 5: (5 * 5) = 25
        i = 6: (6 * 6) = 36
        i = 7: (7 * 7) = 49

        The number "44" is not a perfect square.
```
Input:
```
    (1) The number that the user wants to check if a perfect square number (integer).
```
Output:
```
    (1) Printing text indicating if the number a perfect square or not.
```
Why building this program:
```
    Implementing algorithm that helps in checking if the input integer a perfect square or not.
```