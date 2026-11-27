# Session (8):
Learned (mixed with personal research):
````
    (1) Details on functions and arrays:
        (1.1) Passing Array and size in a function:
        For example:
````
```C
            #include <stdio.h>

            void print_array(int arr[], int size) 
            {
                /* Example input: arr = {-1, 4, 3, 6, -19, 4}, size = 6 */
                int i = 0;
                printf("Array: ");

                for (i = 0; i < size; i++) { 
                    printf("%d ", arr[i]); 
                }
                printf("\n");
            }
            /* Output: Array: -1 4 3 6 -19 4 */
```
````
        (1.2) Passing value methods:

            (1.2.1) Pass by value:

                It copies the variable's value and stores in temporary variable with same original variable's name
                but has no shared memory address with the original variable in the CPU/Microcontroller.

                Undergone series of operations
                throughout the function and then returns the value.
                For example:
````
```C                
                    #include <stdio.h>

                    int set_to_zero(int number) 
                    {
                        /* 'number' is a local copy created on the stack */
                        number = 0; 
                        return number;
                    }

                    int main(void) 
                    {
                        int num_1 = 11234;
                        int num_2 = -32;

                        num_2 = set_to_zero(num_1); 
                        /* num_1 remains 11234 (unchanged) */
                        /* num_2 receives the returned value: 0 */

                        return 0;
                    }
```
````                    
            (1.2.2) Pass by reference:

                It is updating the value of the reference variable because it does receive the variable's memory address location,
                where every change in the variable's value will eventually be updated
                inside a function that receives the variable as input parameter.

                For example:
````
```C                
                    #include <stdio.h>

                    void set_to_zero(int *number) 
                    {
                        /* Dereferencing '*number' directly modifies the variable at that address */
                        *number = 0; 
                    }

                    int main(void) 
                    {
                        int num_1 = 11234;

                        /* Pass the memory address of num_1 using the '&' operator */
                        set_to_zero(&num_1); 
                        
                        /* num_1 is now 0 because set_to_zero modified its memory location */

                        return 0;
                    }
```
````
    (2) Program development:

        Program development is the process required to build and develop an integrated program, but for
        a developer to do so, the developer must ask two essential questions:
            - How to represent and maintain the data?
            - What is the best way (efficient) to process data?


        Data structures and Algorithms are two very large and distinct concepts, that they acquired an entire field of study
        due to the expansiviness of their individual content.
        Data structures answer the first question while Algorithms answer the latter.


        (2.1) Data structures:
            Data structures are specialized formats for organizing, processing, retrieving, and storing data.

                (2.1.1) Representing Data Efficiently
                    Data must be processed (stored, removed, assigned, swapped, sorted, searched, etc...)
                    But such operation has a two costs:
                        - Time Complexity:
                            The time for a procedure to produce the output; it is how the "how fast" the procedural is.

                        - Space Complexity:
                            The physical space in the memory that is occupied; it is "how memory efficient" the procedural is.

                    For example:
                        A structure optimized for lightning-fast search (Good Time Complexity).

                    For example: 'Bad Time Complexity, Good Space complexity'.
````    
```c
                        void bubble_sort(int arr[], int size) 
                        {
                            int i, j, temp;

                            /* Nested loops produce a time complexity of O(n^2) - SLOW for large inputs */
                            for (i = 0; i < size - 1; i++) {
                                for (j = 0; j < size - i - 1; j++) {
                                    if (arr[j] > arr[j + 1]) {
                                        /* Swap elements in-place */
                                        temp = arr[j];
                                        arr[j] = arr[j + 1];
                                        arr[j + 1] = temp;
                                    }
                                }
                            }
                        }
```
````

        (2.2) Algorithms:

            An algorithm is a finite sequence of well-defined instructions used to solve a specific class of problems or perform a computation. If data structures are
            the nouns of programming, algorithms are the verbs.

                (2.2.1) Measuring the Running Time of an Algorithm:

                    When solving a problem, multiple algorithms might work, but some will be vastly more efficient than others.
                    
                    We need reliable ways to measure this efficiency, specifically focusing on how the algorithm behaves as the
                    amount of input data increases.


                (2.2.1.1) Experimental method:

                    This involves actually writing the code, running it with various inputs, and using timing functions to measure the exact milliseconds it takes to
                    complete:

                        Pros: 
                            Gives you real-world, concrete performance data.

                        Cons: 
                            Highly inconsistent. The results depend heavily on the specific hardware, the operating system, the programming language used, and whatever
                            background processes happen to be running on the machine at that moment.


                (2.2.1.2)Asymptotic Analysis (Big O Notation):
                    Because the experimental method is hardware-dependent, computer scientists use asymptotic analysis to evaluate algorithms mathematically.
                    It measures how the running time (or space requirements) of an algorithm grows as the input size (labeled as n) approaches infinity.
                    - Hardware Independent:

                        It evaluates the logic of the algorithm, not the machine running it.

                    - Worst-Case Focus (Big O): 

                        It typically looks at the worst-case scenario. If an algorithm scales linearly, it is denoted as O(n).
                        If it scales quadratically (like a loop inside another loop), it is O(n^2).

                    - Advantage: It allows developers to confidently predict whether an algorithm that works fine for 100 users will
                      crash the server when scaled to 1,000,000 users.




    (3) Why learn:
        (3.1) Pass by reference and pass by value:

            Both are different methods in variable assignment, Pass-by-value refers to how parameters 
            are passed into the function (copying input values).

            While otherwise (pass by reference) is more flexible but dangerous when not handeld correctly,
            as there is no need to manually assign the value since it changes the 
            variable already.



        (3.2) Array as a parametric input of a function:

            Essential for assessing a whole stored data without the need to process the copy-pasting
            the array, arrays in C undergo pointer decay when passed into functions (the function receives a pointer to the first element)
            which cuts power and especially the time for runtime consumption



        (3.3) Data Structure and Algorithms:

            Answering the two questions of "How" and "What" prepares the developer
            to build more robust (Error free), optimized (Fast runtime execution) and
            modular (facilitates debugging and troubleshooting). 

``` 