# Session (5):
Learned:
```
    (1) More rules of loops:
        (1.1) Multiple expression in for loop as example: for( (i = 0,j = 0); (i + j < 100); (i++, j++ ))
        (1.2) Infinite looping in for loop: for(;;)
        (1.3) Infinite looping in while loop, a condition that is always true: while(1)
        (1.4) Do while loop
        (1.5) Nested loops are allowed, but it is suggested not to exceed three.
    
    (2) Mid-loop manipulators:
        (2.1) break
        (2.2) continue

    (3) Functions
        (3.1) Input as parameters and outputs as returns.

            Parameters are specific input that is expected when calling a function, using the
            input for series of operations and process. The final result is the output and it
            is returned.

            The parameter list is called "function's header" while the code inside is the "function's body":
            For example:

                int Add(int num1, int num2) --> Function's header.
                {
                    code --> Function's body.
                }

        (3.2) Return types:

            It is the data type of the functions output.

            (3.2.1) float

            (3.2.2) int

            (3.2.3) char


        (3.3) Implementations:

            It is defining the function before the "main()" function, where it contains only the header and neglecting the body, after the main function, full body code with header are built.

        (3.4) Function calling:

            Through the use parnethesis, a function is called, either waiting for input parameters or not.

        (3.5) Types of functions:
            (3.5.1) Receives input, returns output.

            (3.5.1) Does not receive input, returns output.

            (3.5.1) Receives input, does not return output.

            (3.5.1) does not receive input, does not return output.





    (4) Variable scope:
        (4.1) Global and local scopes
        (4.2) Scope rule: local declared with the same name with the global are priroritized first in a function
            for example:

                #include <stdio.h>
                int result = 0;
                int main(void)
                {
                    result += 13;
                    printf("Result = %d", result); /* printing "Result = 13" */

                    int result = -7;
                    printf("Result = %d", result); /* printing "Result = -7" */
                    return 0;
                }

    (5) Advantages to modular style code:
        - No repetitions (DRY).

        - Function reusability.

        - Easy debugging.

        - Easy modifying.




    (6) Why learn functions, scope, and modular programming:
        (6.1) Functions as simple block:
            Functions contibutes in tranforming big issues into manageable chuncked issue
            which helps the developer to be more focused on problem solving and design
            decision without the frustrations and bewilderment from the big picture.

            In addition to being a tool that can be built once and be reusable across
            the code for clean code plus better optimization and performance.


        (6.2) Scope as a differentiator between an outsider and an insider:

            Scope is helper to distinguish between local scope and global scope variables
            where each one has its own benefits upon implementation.

        (6.3) Modular programming:

            It is a methodology used as a programming style for solving problems and issues
            into cascaded smal-sized problems and issues that can be handled seperately.
            
        

```