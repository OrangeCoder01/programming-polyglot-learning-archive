# Session (4):
Learned:
```
    (1) More rules of loops:
        (1.1) Multiple expression in for loop as example: for( (i = 0,j = 0); (i + j < 100); (i++, j++ ))
        (1.2) Infinite looping in for loop: for(;;;)
        (1.3) Infinite looping in while loop, a condition that is always true: while(1)
        (1.4) Do while loop
    
    (2) Mid-loop manipulators:
        (2.1) break
        (2.2) continue

    (3) Functions
        (3.1) Input as parameters and outputs as returns.
        (3.2) Return type.
        (3.3) Implementations and function parts:
            (3.3.1) Header
            (3.3.2) Function body

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

```