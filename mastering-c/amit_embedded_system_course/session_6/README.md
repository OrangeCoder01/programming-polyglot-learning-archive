# Session (6):
Learned:
```
    (1) Recursion:
        
        It is coding method by perfoming operations that can be done by function recursion (fetching inside it self by itself inside its function body).
        For example:

            int factorial(int num)
            {
                if(num == 1 || num == 0) {return 1;}
                return num * factorial(num - 1)
            }

        It is not recommended as for every recursion operation done, a place in the stack is filled. 
        In case of exceess recursions, the stack will run out of space and will result in "stack overflow"
        issue.

        (1.1) Disadvantages of recursions:
            (1.1.1) High stack memory consumption.

            (1.1.2) High execution time and high storage.

            (1.1.3) Might cause "stack overflow".
    


    (2) Why learn recursions:

        It is a method for solving a problem, through which one gained insight on the stack memory,
        and the possible issue of encountering a stack overflow when over exceeding the use of recursion
        or relating programming methods that can cause the same risk.

    ```