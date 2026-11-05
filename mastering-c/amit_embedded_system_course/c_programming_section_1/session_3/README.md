# Session (3):
Learned (mixed with personal research):
```
    (1) User input:
        (1.1) scanf() function from <stdio.h> header library.

            It receives from the user input depending on data type.
            For example:

                user_num = 0;
                printf("Please, enter an integer number: "); scanf(" %d", &user_num); 
            
            The user inputs an integer number and the program stores the input data in the "user_num" variable's address.
        
        (1.2) Format specifier.
            It is the data type the user is supposed to type the input it belongs to, such as:

                '%d' for integer, '%f' for precision-free floating point, '%c' for char and '%.2f' for precision 2 floating point.
                For example:

                    int integer_num = 10;
                    float pi = 3.14159;
                    char alphabet = 'a';

                    printf("pi = %d, pi (with precision 3) = %.3f, and \'%c\' is the first letter in the English alphabet system.");
                    outputs: pi = 3.14159, pi (with precision 3) = 3.142, and 'a' is the first letter in the English alphabet system.
        
    





    (2) C programming language's operators:
        (2.1) Arithmetic operators:
            (2.1.1) Unary arithmetic operators:

                Unary arithmetic operator that requires one operand (one variable) and perform arithmetic operation.

                (2.1.1.1) Incremental "++" operator:

                    It increments the value of a variable by one.
                    For example:

                        int x = 0;
                        x ++;
                        printf("x = %d", x); -> x = 1
                
                (2.1.1.2) Decremental "--" operators:

                    It decrements the value of a variable by one.
                    For example:

                        int x = 10;
                        x --;
                        printf("x = %d", x); -> x = 9

                

                Note: There are:
                    - Post-incrementation:
                    For example:

                        int x = 10;
                        int y = x ++
                        printf("x = %d, y = %d",x, y) ---> x = 11, y = 10


                    - Pre-incrementation:
                    For example:

                        int x = 10;
                        int y = ++x 
                        printf("x = %d, y = %d",x, y) ---> x = 11, y = 11


                    - Post-decrementation:
                    For example:

                        int x = 10;
                        int y = x-- 
                        printf("x = %d, y = %d",x, y) ---> x = 9, y = 10


                    - Pre-decrementation:
                    For example:
                        int x = 10;
                        int y = --x 
                        printf("x = %d, y = %d",x, y) ---> x = 9, y = 9


            




            (2.1.2) Binary arithmetic operators:

                Binary arithmetic operator that requires two operands (two variables) and perform arithmetic operation.
                Example for the following subsections:

                        int x = -4;
                        int y = 2;    
                        int z;

                (2.1.2.1) Addition '+':

                    It adds two variables and store the result in a variable.

                    z = x + y;
                    printf("z = %d", z); -> z = -2


                (2.1.2.2) Subtraction '-':

                    It subtracts two variablse and store the result in a variable.

                    z = x - y;
                    printf("z = %d", z); -> z = -6


                (2.1.2.3) Multiplication '*':

                    It multiplies two variablse and store the result in a variable.

                    z = x * y;
                    printf("z = %d", z); -> z = -8


                (2.1.2.4) Division '/':

                    It divides two variablse and store the result in a variable.

                    z = x / y;
                    printf("z = %d", z); -> z = -2


                (2.1.2.5) Modulus '%':

                    It returns the numerator of the fraction that does not evenly be divided by the divisor:
                        for example:
                            5 % 4 -> (5/4) = (4/4 + 1/4) -> returns 1.
                        
                        z = x % y; -> (-4 % 2) --> (2/2 + 2/2 + 0/2) --> returns 0
                        printf("z = %d", z); -> z = 0
                    
                    Note: Modulus operates only on integer variables only and
                          always return an integer with the sign of the first operand.




        (2.2) Bitwise operators:
        Example for the following subsections:
                For 8 bit integer representation:

                int x = 14; (0 0 0 0  1 1 1 0)
                int y = 5;  (0 0 0 0  0 1 0 1)
                int z;
            
            A binary number is composed of stream of booleans:
                '1' for true.
                '0' for false.
            
            true  AND false = false -> 1 AND 0 = 0
            true  AND true  = true  -> 1 AND 1 = 1
            false AND false = false -> 0 AND 0 = 0

            true  OR false = true  -> 1 OR 0 = 1
            true  OR true  = true  -> 1 OR 1 = 1
            false OR false = false -> 0 OR 0 = 0

            true  XOR false = true  -> 1 XOR 0 = 1
            true  XOR true  = false -> 1 XOR 1 = 0
            false XOR false = false -> 0 XOR 0 = 0


        Very important Note:

            There are 8 bits:
                                 1       0       0       0       0       0       0       0
            Position:            7       6       5       4       3       2       1       0
            Decimal weight:     -128     64      32      16      8       4       2       1

            There are multiple methods in integer expression:
            but the standard and the most predominantly used in the modern computing systems:

            The "Two complements" binary integer expression.

                The MSB short for "Most Significant Bit" is the bit with highest decimal weight and lie on the leftmost part.
                The LSB short for "Least Significant Bit" is the bit with lowest decimal weight and lie on the rightmost part.


            When most the MSB is zero then the number is positive (+128), and when it is a one then it is a negative integer (-128).
            For example:


                (34)  = 32 + 2                          ----> ( 0 0 1 0  0 0 1 0 )
                (-6)  = -128 + (128 - 6)  = -128 + 122  ----> ( 1 1 1 1  1 0 1 0 ) = -128 + (64 + 32 + 16 + 8 + 2)
                (-34) = -128 + (128 - 34) = -128 + 94   ----> ( 1 1 0 1  1 1 1 0 ) = -128 + (64 + 16 + 8 + 4 + 2)
                (-128)                                  ----> ( 1 0 0 0  0 0 0 0 )
                (15)                                    ----> ( 0 0 0 0  1 1 1 1 )

                (2.2.1) Bitwise AND operator '&':


                        For example:

                            z = x & y; -> 4
                            Dynamic explanation:

                                x: 0 0 0 0   1 1 1 0
                                y: 0 0 0 0   0 1 0 1
                                z: 0 0 0 0   0 1 0 0

                                z = (2^2) =  4
                        
                    Note: it is similar to arithmetic multiplication but in bitwise level.


                (2.2.2) Bitwise OR operator '|':

                        For example:

                            z = x | y; -> 15
                            Dynamic explanation:

                                x: 0 0 0 0   1 1 1 0
                                y: 0 0 0 0   0 1 0 1
                                z: 0 0 0 0   1 1 1 1

                                z = (2^3  + 2^2 + 2^1 + 2^0) =  (8 + 4 + 2 + 1) = 15

                    Note: it is similar to arithmetic addition but in bitwise level.


                (2.2.3) Bitwise NOT operator '~':

                        For example:

                            z = ~ x; -> -15
                            Dynamic explanation:

                                flip bits and add with (0 0 0 0  0 0 0 1)

                                x:  0 0 0 0   1 1 1 0
                                ~x: 1 1 1 1   0 0 0 1


                                z = -128 + 64 + 32 + 16 + 1 = -128 + 113 = -15.

                    Note: Bit flipping includes flipping the sign bit.


                (2.2.4) Bitwise XOR operator '^':

                    Even numbered true (1) will result into false (0) otherwise odd numbered true (1) will result into true (1).
                        For example:

                            z = x ^ y; -> 11
                            Dynamic explanation:

                                x: 0 0 0 0   1 1 1 0
                                y: 0 0 0 0   0 1 0 1
                                z: 0 0 0 0   1 0 1 1   

                                z = (2^3 + 2^1 + 2^0) =  8 + 2 + 1 = 11


                (2.2.5) Bit manipulation:
                    (2.2.5.1) Right bit shift '>>':

                        For example:

                            z = x >> 2; -> 3
                            Dynamic explanation:

                                x: 0 0 0 0   1 1 1 0
                                z: 0 0 0 0   0 0 1 1

                                z = (2^1 + 2^0) =  3



                    (2.2.5.2) Left bit shift '<<':

                        For example:

                            z = x << 1; -> 28
                            Dynamic explanation:

                                x: 0 0 0 0   1 1 1 0
                                z: 0 0 0 1   1 1 0 0

                                z = (2^4 + 2^3 + 2^2) =  28






        (2.3) Assignment operators:

            These are operators that perform an (arithmetic or bitwise) operation and assigning value to the variablr simultaneously except '=' assignment operator.

            (2.3.1) Equate "=":
                For example:

                    int x = 0;
                    printf("x = %d", x); -> x = 0



            (2.3.2) Add and equate "+=":
                For example:

                    int x = 0;
                    x += 10;
                    printf("x = %d", x); -> x = 10




            (2.3.3) Subtract and equate "-=":
                For example:

                    int x = 0;
                    x -= 4;
                    printf("x = %d", x); -> x = 4



            (2.3.4) Multiply and equate "*=":
                For example:

                    int x = 1;
                    x*= 5
                    printf("x = %d", x); -> x = 5



            (2.3.5) Divide and equate "/=":
                For example:

                    int x = 6;
                    x /= 2;
                    printf("x = %d", x); -> x = 3



            (2.3.6) Modulus and equate "%=":
                For example:

                    int x = 8;
                    x %= 3;
                    printf("x = %d", x); -> x = 2



            (2.3.7) Bitwise AND and equate "&=":
                For example:

                    int x = 16;
                    x &= 20
                    For visualization:

                        x:      0 0 0 1  0 0 0 0
                        20:     0 0 0 1  0 1 0 0 
                        new x:  0 0 0 1  0 0 0 0

                    printf("x = %d", x); -> x = 16



            (2.3.8) Bitwise OR and equate "|=":
                For example:

                    int x = 10;
                    x |= -2
                    For visualization:

                        x:      0 0 0 0  1 0 1 0
                        -2:     1 1 1 1  1 1 1 0
                        new x:  1 1 1 1  1 1 1 0

                    printf("x = %d", x); -> x = -2





            (2.3.9) Bitwise XOR and equate "^=":
                For example:

                    int x = 10;
                    For visualization:

                        x:      0 0 0 0  1 0 1 0
                        9:      0 0 0 0  1 0 0 1
                        new x:  0 0 0 0  0 0 1 1

                    printf("x = %d", x); -> x = 3




            (2.3.10) Shift right and equate ">>=":
                For example:

                Note: shifting Negative number, means adding 1s with crossed bit places.
                      but shifting positive number, means addinf 0s with the crosded bit places.

                    int x = -128;
                    x >>= 3
                    For visualization:

                        x:      1 0 0 0  0 0 0 0
                        new x:  1 1 1 1  0 0 0 0

                    printf("x = %d", x); -> x = -16



            (2.3.11) Shift left and equate "<<=":
                For example:

                    int x = 1;
                    x <<= 5
                    For visualization:

                        x:      0 0 0 0  0 0 0 1
                        new x:  0 0 1 0  0 0 0 0

                    printf("x = %d", x); -> x = 32






        (2.4) Relational operators:

            These operators result in a single bit (boolean) which indicate the
            validity of a statement with underlying condition, where 0 is a false argument (statement)
            while 1 is a true one.

            (2.4.1) Less than '<'.
            For example:

                5 < 6 -> 1
                5 < 1 -> 0

            (2.4.2) Less than or equal '<='.
            For example:

                -10 <= -1 -> 1
                7 <= 6    -> 0

            (2.4.3) is equal to '=='.
            For example:

                12 == 12   -> 1
                -53 == 420 -> 0

            (2.4.4) is not equal to '!='.
            For example:

                10 != -1 -> 1
                9 != 9   -> 0

            (2.4.5) More than or equal '>='.
            For example:

                4 >= -5 -> 1
                5 >= 6 -> 0

            (2.4.6) More than '>'.
            For example:

                5 > 1 -> 1
                5 > 6 -> 0
        





        (2.5) Logical operators.

            These operators perform single bit operation:

                Any non-zero number is true (1), and zero is false (0).

            (2.5.1) Logical AND "&&":
            For example:

                5 && 1 -> 1
                5 && 0 -> 0

            (2.5.2) Logical OR "||":
            For example:

                0 || -1341 -> 1
                0 || 0     -> 0

            (2.5.3) Logical NOT "!":
            For example:

                !0 = 1
                !1 = 0

        



        (2.6) Other operators:
            (2.6.1) Comma and link related operators:
            For example:
                int user_id = 20513;
                printf("Hello user %d", 20513); (Comma in functions)
            
            Another example:
                int x, y, z = 0; (Comman in same data type declaration).
            

            (2.6.2) sizeof().

            (2.6.3) Ternary.


            (2.6.3) Dereference '*'.


            (2.6.3) Subscription {}.


            (2.6.3) Address of a variable '&'.




                    

    (3) Type casting:

        It is temporarily converting a variable type into another type.
        For example:

            int x = 19;
            float y = -20.62;
            int z;

            z = x + (int)(y); --> 19 - 20 = -1

            printf("z = %d", z); -> z = -1




    


    (4) Why learn:
        (4.1) User input scanf() function:

            It is helpful to transfer user's input text from the terminal, and present the text
            data to be processable input.
        
        (4.2) C programming language's arithmetics:

            It is the backbone and essential operators where each operators is the very basic
            tools to use to make more powerful tool such as root power, exponentiation, logarithm
            or any other crucial mathematical tools.

            Using these simple, with proficient and optimized algorithmic design, will yield to
            powerful fast large-scale softwares. Thus, for these reasons it is required in Embedded System
            for resolving the data storage space and MCU's (Microcontroller Unit) lack of capabilities into
            a powerful and efficient gadget.

            Bitwise operations is the top crucial operators in C programming language, due the fast paced
            and less cost CPU (Center Processing Unit) code cycles in runtime (running the program);
            thus saves time.
        
        (4.3) Type casting:

            It is crucial for temporary data type conversion, which is heavily
            used in code for the cross data type operations.


```