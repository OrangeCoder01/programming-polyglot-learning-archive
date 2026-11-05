# Task 1:
Question:
```
    (1) Write a program that reads a positive integer and
        checks if it is a prime number.
```
Explanation:
```
    The program validates user's input integer for being a positive number, then
    proceed to check if the integer is a prime number or not.

    checks the number modulus the iteration (ranging from 2 till the number halfed equate to zero),
    if that the number modulus the iteration equates to zero, then the number is composite, and the loop breaks.

    else when the iteration exceeds the value of the number halfed and the modulus operation never equated
    to 0, then the number is prime.
    For example:

        Number = 25.
        Loop sequence:

            i = 2 ---> (Number % i == 0) ---> False
            i = 3 ---> (Number % i == 0) ---> False
            i = 4 ---> (Number % i == 0) ---> False
            i = 5 ---> (Number % i == 0) ---> True --w-> break
            
            The number {25} is not a prime number.

    Another example:  

        Number = 7.
        Loop sequence:

            i = 2 ---> (Number % i == 0) ---> False
            i = 3 ---> (Number % i == 0) ---> False
            
            iteration stops at 3.5, but for integer flooring, it is 3.


            The number {7} is a prime number.
```
Input:
```
    (1) A number (integer).
```
Output:
```
    (1) Printing text indicating if the input integer is a prime number or not.
```
Why building this program:
```
    Implementing an algorithm that helps in determining whether the number is prime or not.
```