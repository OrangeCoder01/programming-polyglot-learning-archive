# Task 2:
Question:
```
    (2) Write a program that takes a number and a bit number from
        the user, then print the value of this bit in this number.
```
Explanation:
```
    The program check if a bit is 1 or 0, by right shifting
    the bit order and bitwise AND 1
    For example:

        number                         = 54:    0 0 1 >1<  0 0 1 0
        after right bit shift by order = 4:     0 0 0 0  0 0 1 1
        number & 1:                             (0 0 0 0  0 0 1 1) & (0 0 0 0  0 0 0 1) = (0 0 0 0  0 0 0 1) = 1

```
Input:
```
    (1) The integer number.
    (2) The shifting bit.
```
Output:
```
    (1) The bit value of a number: 1 or 0
```
Why is this program important:
```
    Bit value is important for binary data manipulation in C programming language.
    so check bit is useful for detecting the boolean state of the bit.
```