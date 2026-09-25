# Session (8):
Learned (mixed with personal research):
````
    (1) Details on functions and arrays:
        (1.1) Passing Array and size in a function:
        For example:
````
```C
            void print_array(int arr[], int size)
            {
                /* Let: size = 6, arr[] = {-1, 4, 3, 6, -19, 4}*/

                int i = 0;
                printf("Array: ");

                for(i; i < size; i++) { printf(" %d", arr[i]); }

                /* Output = Array: -1 4 3 6 -19 4 */
            }
```
````
        (1.2) Passing value methods:

            (1.2.1) Pass by value:

                It copies the variable's value and stores in temporary variable with same orignal variable's name
                but has no shared memory address with the original variable in the CPU/Microcontroller.

                Undergone series of operations
                throughout the function and then returns the value.
                For example:
````
```C                
                    int set_to_zero(int number)
                    {
                        /* Was 11234*/
                        number = 0; /* Now 0*/
                        return number;
                    }

                    int main(void)
                    {
                        int num_1 = 11234, num_2 = -32;
                        num_2 = set_to_zero(num_1); /* num_1 = 11234 but num_2 = 0 */
                        
                        return 0;
                    }
```
````                    
            (1.2.2) Pass by reference:

                It is updating the value of the reference variable because it does receive the variable's value
                and its memory address location, where every change in the variable's value will eventually be updated
                inside a function that receives the variable as input parameter.

                For example:
````
```C                
                    void set_to_zero(int *number) /* The return type is: "void" and  */
                    {
                        /* Was 11234*/
                        number = 0; /* Now 0*/
                        return number;
                    }

                    int main(void)
                    {
                        int num_1 = 11234, num_2 = -32;
                        num_2 = set_to_zero(num_1); /* num_1 = 11234 but num_2 = 0 */
                        
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
                            The physical space in the memory that is occupied; it is "how tight" the procedural is.

                    For example:
                        A structure optimized for lightning-fast search (Good Time Complexity) might be terribly slow for
                        frequent data insertions (Bad Space complexity).

                    For example: 'Bad Time Complexity, Good Space complexity'.
````    
```c
    int bubble_sort(int arr[], int size) /* A sorting method */
    {
        
    }
```
````

        (2.2) Algorithms:
            (2.2.1) Measuring running time of an alogrithm:
                (2.2.1.1) Experimental method:
                (2.2.1.2) Asymptotic analysis:



    (3) Why learn:
        (3.1) Pass by reference and pass by value:

            Both are different methods in variable assignment, pass by value
            assignment is through equating a variable to return value from a function.

            While otherwise (pass by reference) is more flexible but dangerous when not handeld correctly,
            as there is no need to manually assign the value since it changes the 
            variable already.

        (3.2) Array as a parametric input of a function:

            Essential for assessing a whole storaged data without the need to process the copy-pasting
            the array, as the default condition for return method for parametric arrays is pass by reference
            which cuts power and especially the time for runtime consumption

        
        (3.3) Data Structure and Algorithms:

            Answering the two question of "How" and "What" prepares the developer
            to build more robust (Error free), optimized (Fast runtime execution) and
            modular (facilitates debugging an troubleshooting). 

``` 