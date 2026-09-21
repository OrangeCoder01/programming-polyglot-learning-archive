# Lab (1):
Explanation:
```
    The program uses intermediate bit manipulation technique:

        Setbit which is about setting a bit of an input integer with a user specific bit order to 1.
        Algorithm:

            Left bit shifting integer 1 and performing bitwise OR to equate the specific bit to 1.
        
        For example:

            Number = 77.
            Bit order = 4
            Binary representation =  0 1 0 0  1 1 0 1
            Corresponding bit order: 7 6 5 4  3 2 1 0

            Operation (1): Left shifting the bit (1) by the bit order {1 << bit_order}.
                
                 0 0 0 0  0 0 0 1    --->     0 0 0 1  0 0 0 0
                
            Operation (2): Perform bitwise OR with the input integer.

                0 1 0 0  1 1 0 1
                        |
                0 0 0 1  0 0 0 0
                        =
                0 1 0 1  1 1 0 1

                Output: Number = 

        Another example:

```
Input:
```
    (1) The integer number undergoing the set bit (integer).
    (2) The bit order (integer).
```
Output:
```

```
Why is this program important:
```

```