# Day 2:
Learned:
```
    (1) Data types:
        (1.1) Types:
            (1.1.1) Integer:
                (1.1.1.1) Integer converter:
                
                    int(): can be used with floats,
                            and (numerical)/(single character) strings.


            (1.1.2) Float:
                (1.1.2.1) Float converter:

                    float(): can be used with integers
                            numerical strings.



            (1.1.3) String:
                    (1.1.3.1) String converter:

                    str(): can be used with integers
                        for ASCII convertion to char.


                    (1.1.3.2) Text character extractor:

                        "Hello" --> H[0] e[1] l[2] l[3] o[4]
                        print("Hello"[0]) = H



            (1.1.4) Boolean:
                (1.1.4.1) Boolean converter:

                    bool(): can be used with integer
                            and floats, where 0 is "False" and any non-zero number convert to "True".



        (1.2) Data type specifier:
            type(): Used for identifying the variable's
                    type.



    (2) Arithmetic operations:
        (2.1) Addition: '+'.

        (2.2) Multiplication: '*'.

        (2.3) Division:
            (2.3.1) Float division: '/'.

            (2.3.1) Integer division: '//'.
                
                Doing regular float division and cuts the
                fraction off.

        (2.4) Subtraction: '-'.

        (2.5) Exponetial power: '**'.

            The number before the operator is the base number and what is after is the exponential power.

        (2.6) Incrementation/decrementation: '+=' and '-='.


    (3) f-string:

        embedding a value inside a string text found in
        input() and print().
        
    (4) round function:

        The round() function receives the values and rounds it to the integer's order automatically, but can also receives the digit order in the second parameter slot.

        round( value, digit_order ) or jusr round( value )

        for example: round(3.56, 1) = 3.6
                        round(3.56) = 4.0,
                        round(3.367, 0) = 3.0        

```