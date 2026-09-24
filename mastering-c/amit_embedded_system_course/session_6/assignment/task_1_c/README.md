## Task (1):
Question:
```
    (1) Write the intermediate bit manipulation operators for bitstream's bit manipulation:
        - Set bit.
        - Clear bit.
        - Toggle bit.
        - Check bit.
```
Explanation:
```
    Main concpts:
        
        An integer type is a 4 byte, a byte is 4 bits, and a bit is a boolean 1 or 0, composing a total of 16 bits.
        A bitstream is a combination of bits.
        
        A bit order is the order, index, or position of a bit inside a bitstream. Its position represents a
        numerical value. The count start from 0 from the leftmost. The numberical significance of the bit in the bitstream
        is defined by this equation:

            2^(position) --> Note that the position is recorded from 0 from the leftmost bit. 
        
        For example a bit at position 4 has a numerical significance of 2^4 = 16.

        The numerical value of the bitstream (in case of a positive integer) is the summation of each numerical significance of bits with boolean 1.


        so an integer as 27 is manifested as:

            Bitstream:                          0        0      0      0          0      0      0    0          0    0   0   1         1  0  1  1
            Bit order:                          15       14     13     12         11     10     9    8          7    6   5   4         3  2  1  0
            Numerical significance bit:         32768   16384   8192   4096       2048   1024   512  256        128  64  32  16        8  4  2  1 

            
            The numerical value of the bitstream: (2^4 + 2^3 + 2^1 + 2^0) = (16 + 8 + 2 + 1).


    (1) Set bit:
        It is setting a bit's boolean state in a bitstream with 1, if the bit is 0, the bit becomes 1; if bit is 1, then nothing changes.

        Operation: integer | ( 1 << bit_position ).

    Process:
            Let integer = 25.
            bit_position = 5.

        Step (1): 1 << bit_position:

            {0000 0000 0000 0001 << 5} ---> 0000 0000 0010 0000 = result_1.

        Step (2): integer | result_1:

            {0000 0000 0001 1001 | 0000 0000 0010 0000} = 0000 0000 0011 1001 = 32 + 16 + 8 + 1 = 55.




    (2) Clear bit:
        It is clearing bit's boolean state in a bitstream to be 0, if the bit is 0, then nothing changes; if bit is 1, the bit becomes 0.

        Operation: integer & ( ~(1 << bit_position) ).
        
        Process:

            Let integer = 25.
            bit_position = 4.

        Step (1): 1 << bit_position:

            {0000 0000 0000 0001 << 4} ---> 0000 0000 0001 0000  = result_1.

        Step (2): ~result_1:

            ~{0000 0000 0000 0000} = 1111 1111 1110 1111 = result_2.
        
        Step (3): integer & result_2:

            {0000 0000 0001 1001 & 1111 1111 1110 1111} = 0000 0000 1001 = 9.




    (3) Toggle bit:
        It is toggling the bit's boolean state, if bit is 0, the bit becomes 1; if bit is 1, the bit becomes 0.

        Operation: integer ^ (1 << bit_position);

        Process:

            Let integer = 25.
            bit_position = 4.

        Step (1): 1 << bit_position:

            {0000 0000 0000 0001 << 4} ---> 0000 0000 0001 0000  = result_1.

        Step (2): integer ^ result_1:

            {0000 0000 0001 1001 ^ 0000 0000 0001 0000} = 0000 0000 1001 = 9.




    (4) Get bit: ( integer & ( 1 << bit_position) ) && 1.
        It gets the bit's boolean state, if bit is 0, the operators return 0; if bit is 1, the operator returns 1.

        Operation: ( integer & ( 1 << bit_position) ) && 1;
        
        Process:

            Let integer = 25.
            bit_position = 4.

        Step (1): 1 << bit_position:

            {0000 0000 0000 0001 << 4} ---> 0000 0000 0001 0000  = result_1.

        Step (2): integer & result_1:

            {0000 0000 0001 1001 & 0000 0000 0001 0000} ---> {0000 0000 0001 0000} = result_2.
        
        Step (3): result && 1:

            {0000 0000 0001 0000 && 0000 0000 0000 0001} = 1

```
Input:
```
    (1) An integer number (integer).
```
Output:
```
    (1) An integer number or a boolean state of the integer number (integer).
```
Why building this library:
```
    This library holds intermediate bit manipulation operators that are essential in electronic due to the
    fact that the electronic device have internal instruction written in bitstream where the bit position
    have a hardware meaning.
```