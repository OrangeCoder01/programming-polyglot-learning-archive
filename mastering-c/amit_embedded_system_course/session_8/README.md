# Session (7):
Learned:
```
    (1) Details on functions:
        (1.1) Passing Array and size in a function:
            For example:
            """"
                void print_array(int arr[], int size)
                {
                    /* Let: size = 6, arr[] = {-1, 4, 3, 6, -19, 4}*/

                    int i = 0;
                    printf("Array: ");

                    for(i; i < size; i++) { printf(" %d", arr[i]); }

                    /* Output = Array: -1 4 3 6 -19 4 */
                }
            """


        (1.2) Passing value methods:

            (1.2.1) Pass by value:

                It copies the variable's value and stores in temporary variable with same orignal variable's name
                but has no shared memory address with the original variable in the CPU/Microcontroller.

                Undergone series of operations
                throughout the function and then returns the value.

                For example:
                """
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
                """

            (1.2.2) Pass by reference:

                It is updating the value of the reference variable because it does receive the variable's value
                and its memory address location, where every change in the variable's value will eventually be updated
                inside a function that receives the variable as input parameter.

                For example:
                """
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
                """
```