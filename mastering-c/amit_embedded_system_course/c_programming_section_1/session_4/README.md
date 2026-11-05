# Session (4):
Learned (with mixed research):
```
    (1) Control flow:
        It is a controller for which holds how the compiler read the code from start to finish.

        (1.1) Sequential control flow:

            It is reading the code from upside down, functions as an example.

        (1.2) Conditional control flow:
            
            Selectively reading code based on true conditional statements and skipping
            the false ones.

            For example:

                if(){}, else if(){}, else(){}, and switch()case{} keywords.

                (1.2.1) Rules of if(), else(), and else if(){} keywords:
                    (1.2.1.1) No code between if(), else if(){}, and else(){}

                    (1.2.1.2) else(){} is optional but can not be repeated.

                    (1.2.1.3) else if(){} is optional but can be repeated.

                    (1.2.1.4)  Round brackets are used for compound conditional statements:
                    For example:
                            
                        int x = 0, y = -2, z = 4, k = 8;
                        if((y < x) && (k > 5)) --> if(true && true) --> if(true) --> compiler will read the code inside this
                                                                                     if() block.

                    (1.2.1.5) Curly braces can be ignored if there is only one code operation:
                    For example:

                    if(x > 10) printf("Hello World!");

                    But that is not recomended.

                    For example:
                        int x = 0, y = 2;
                        if(y > 2) { printf("y is bigger"); }
                        else if( x > y) { printf("x is bigger"); }
                        else {printf("x and y are equals");}



                
                (1.2.2) Rules for switch:
                    (1.2.2.1) Switch input must be an integer (int or char (that data type is ASCII based integer)). 

                    (1.2.2.2) case must be a constant integer, not a variable, and unique from other cases.

                    (1.2.2.3) Only one default is allowed.

                    (1.2.2.4) Break ends the switch()





                



        (1.3) Iterative(counter) control flow:

            Repeating the reading of a code based on number of repetitions/iterations

            For example:

                for(){}, while(){}, and do{}while() loops.

                (1.3.1) for(){} loop:

                    It is the "finite iterative loop" where the compiler reads the code in
                    numbers of repetitions.

                    Structure:
                        int i = 0;
                        for(i; i < 10; i++ ) { "code" }

                        The compiler reads the code inside the for loop ten time where:

                        - Initialization is with i.

                        - Conditional statement (i < 10).

                        - step (i += 1, i--, or i = i + 2).
                    


                    Note: for loop can be turned to be inifinte loop  by writing for(;;).
                    Note: for loop can hold multiple initialized variable at once:
                    for example:
                        for(int i = 0, int j = 0; (i < 10 && j * 2 <= 30); (i++, j += 2))




            (1.3.2) while(){} loop:

                It is "infinite iterative loop" where the compiler will read the code infintely
                until either, the conditon set is false or reaching disruptive control flow keywords: break or return for exiting the loop.

                For example:

                int x = 0; y = -10;
                while(y < x) { y += 1; }
                this continues until the program checks the condition after y became 0 after 10 iterations.

            
            (1.3.3) do{}while() loop:

                It functions identically as while loop but only two exceptions:
                    (1) The code runs first and validate the condition later.

                    (2) There must be a semi-colon at the end after "while" loop keyword.





        (1.4) Jump (transfer/disruptive) control flow:

            They are keywords that directly cut/skip the current flow.

            For example:

                break, continue, return.

                (1.4.1) break keyword:

                    It exits the loop entirely.
                
                (1.4.2) continue keyword:

                    It forces the compiler to skip rest of the code for the current iteration. after encountering "continue" keyword
                
                (1.4.3) return keyword:

                    It exits the function entirely.
            


    (2) Why learn control flow:
        
        Because it is the block of code that directs the compiler to read data in specific manner;
        and by this direction, the compiler computes and manages data as to how the developer orchestrated the
        code instructions (control flow) across the code; yielding to expected results.
        
```