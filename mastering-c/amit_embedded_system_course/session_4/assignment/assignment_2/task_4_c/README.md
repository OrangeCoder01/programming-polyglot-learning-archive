# Task 4:
Question:
```
    (4) Write a program to calculate the power of a number.
        The number and its power are input from user.
```
Explanation:
```
    The program calculate integer power exponetiation of a base integer number.
    Algorithm:

        The result is initialized as the base integer's value, and gets assigned by the muliplication of the current result's
        value with the base number
        with each new iteration spanning from "i = 1" (Actually starting from 0, but the for pre-increments it) until 
        "i < power" condition becomes false.
    
    For example:

        Number = 5.
        power = 3.
        result should be 5³ = 125.

        result = Number = 5.

        @ i = 1: result = 5 * 5 = 25.
        @ i = 2: result = 25 * 5 = 125.
```
Input:
```
    (1) 2 integers:
        (1.1) Base number.

        (1.2) Exponential power.
```
Output:
```
    (1) The printing of the exponentiation of the base integer number.
```
Why building this program:
```
    Implementing simple mathematical tool, positive integer exponential power.
```