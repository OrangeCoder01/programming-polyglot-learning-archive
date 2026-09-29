# Session (10) and Session (11):
Learned(mixed with personal research)<br>
${\color{red}\text{Note}}$:
````    
        Learned about Pointers and macros (and preprocessor directive).
        
        I have already explained Macros in the top-level README of Session (9),
        the current README focuses only on Pointers.
````
````
    (1) Pointers:

        (1.1) Pointer Fundamentals & Syntax:
            (1.1.1) Definition:
                A pointer is a specialized variable that stores the memory address of another variable rather than a direct value.

            (1.1.2) Declaration & Initialization Syntax:
                    - Declaration: pointed_type *pointer_name;
                      Example:
````                    
```c
                        int variable; /* Variable */
                        int *ptr;   /* pointer*/
``` 

````                   
                    - Assignment: pointer_name = &variable_name;
                      Example:
````
```c
                        ptr = &variable /* The pointer is assigned with the value of the address of the "variable" */
```

````                    
                    - Combined: pointed_type *pointer_name = &variable_name;
                      Example:
````
```c
                        int variable;
                        int *ptr = &variable;
```

````

            (1.1.3) Pointer Operators:
                - Address-of Operator (`&`): Returns the physical memory address of a variable.
                - Dereferencing Operator (`*`): Accesses or modifies the value stored at the memory address pointed
                  to by the pointer.

            (1.1.4) Memory Representation Example:
````
```c
                int x = 10;      /* Allocated at address 0x100 storing value 10 */
                int *Ptr = &x;   /* Stored at address 0x200, holding value 0x100 */
                *Ptr = 20;       /* Overwrites value at 0x100 from 10 to 20 */
```
````
        (1.2) Passing Pointers to Functions (Pass by Reference / Address):
            - Allows functions to directly manipulate variables in the caller's stack frame.
            Example:
````
```c
                int Add(int *Ptr1, int *Ptr2) 
                {
                    int Sum = 0;
                    Sum = *Ptr1 + *Ptr2; /* Dereference and sum values */
                    return Sum;
                }

                int main(void) 
                {
                    int x = 10, y = 20;
                    int Res = Add(&x, &y); /* Passes addresses 0x100 and 0x300 */
                    return 0;
                }
```
````
    (1.3) Relationship Between Pointers and Arrays:
        (1.3.1) Key Rules:
            (1.3.1.1) Array Decay:
                The name of an array (Arr) acts as an alias / constant pointer to its first element (Arr == &Arr[0]).

            (1.3.1.2) Memory Identity: 
                An array name is NOT a true pointer variable because it does not occupy a distinct memory address location itself.

            (1.3.1.3) Element Dereference Equivalence:
                Arr[i] sames as *(Arr + i)


        (1.3.2) Function Parameters with Arrays:
            - Function signature int func(int Arr[], int Size) translates identically to int func(int *Arr, int Size)
            Example:
````
```c
                int func(int Arr[], int Size) /* same as */ int func(int *Arr, int Size)
```

````            

    (1.4) Multi-Dimensional Arrays & Pointer Mapping:
        (1.4.1) Memory Layout:
            - 2D arrays are flattened contiguously in RAM row-by-row
        
        
        (1.4.2) Pointer Calculations for Arr[ROW][COL]:
            - Base Address of Row i: Arr[i] sames as *(Arr + i)

            - Element Address: &Arr[i][j] sames as Arr[i] + j sames as *(Arr + i) + j

            - Element Access: Arr[i][j] sames as *(*(Arr + i) + j)

            For example:
                For int Arr[3][2] starting at 0x100 (where sizeof(int) = 4):

                    Row 0 Base Address (Arr[0]): 0x100
                    Row 1 Base Address (Arr[1]): 0x100 + (1 * 2 * 4) = 0x108 (2 for columns, 1 for row order, 4 for int size)
                    Row 2 Base Address (Arr[2]): 0x100 + (2 * 2 * 4) = 0x116 (2 for columns, 2 for row order, 4 for int size)
                    Element Arr[2][1]: address is 0x116 + (1 * 4) = 0x120

            Mathematical method for retreiving address of each place in a 2D Matrix array (Arr[i][j]):
                (Arr) + ((i * number_of_columns) + j)*datatype_size



    (1.5) Pointer Arithmetic Rules:
        (1.5.1) Adding a Scalar Value:
            - Formula: Ptr + i -> Ptr + (i * sizeof(pointed_type))
            - Advances the pointer by i elements rather than i raw bytes.


        (1.5.2) Subtracting a Scalar Value:
            - Formula: Ptr - i -> Ptr - (i * sizeof(pointed_type))
            - Moves the pointer backward by i elements.


        (1.5.3) Subtracting Pointer from Pointer:
            - Formula: Element Distance = Ptr1 - Ptr2
            The result in the difference is the number of elements.
            Example:
````
```c
                int *Ptr1 = (int*)2000;
                int *Ptr2 = (int*)1000;
                int x = (int)(Ptr1 - Ptr2); /* (2000 - 1000) / 4 = 250 elements */
                /*  */
```
````
            - Useful for determining element count/distance within array boundaries.

        (1.5.4) Invalid Pointer Operations:
            - Multiplication (Ptr1 * Ptr2 or Ptr * 2) is invalid.
            - Division (Ptr1 / Ptr2 or Ptr / 2) is invalid.

    (1.6) Special Pointer Types & Pitfalls:
        (1.6.1) Dangling Pointer:
            A pointer that references a memory location that has been deallocated or deleted.
            Returning the address of a local stack array from a function.
            Example:
````
```c
                int* func(void) 
                {
                    int Arr[3];
                    return Arr; /* Returns address of temporary stack memory after the function stack frame is deleted from stack memory*/
                }
```
````
        (1.6.2) wild Pointer:
            It is a pointer that is declared but not initialized by a value.


        (1.6.3) Null Pointer:
            A pointer pointing to address zero (NULL), explicitly indicating it points to no valid memory.
            Prevents uninitialized wild pointers from writing to arbitrary memory addresses.

            pointer intentionally assigned the value NULL (or 0). 
            It signifies that the pointer does not point to any valid memory location. 
````
```c
                #include <stdio.h>

                int main(void) 
                {
                    /* wild Pointer  */
                    int *ptr; /* Uninitialized: holds a garbage address */
                    int *safe_ptr = NULL; /* Explicitly points to address 0 (Safe) */   
                    int num = 50;
                    ptr = &num; /* Now ptr holds a valid address and is no longer wild */
                    return 0;
                }
```   

````            

        (1.6.4) Void Pointer (void / Generic Pointer):
            - Definition: A generic pointer type that can hold memory addresses of any data type without explicit casting.

            - Uses:
                1. Function prototype parameters requiring generic data handling.
                2. Return type for dynamic memory allocation functions (e.g., malloc).
                
            - Limitation: Cannot be dereferenced or incremented directly without casting to a concrete data type.
            Example:
````
```c
                #include <stdio.h>

                int main() {
                    int int_var = 42;
                    float float_var = 3.14;

                    void *generic_ptr;

                    generic_ptr = &int_var;
                    /* To print it, cast generic_ptr to an int pointer (int*) before dereferencing (*) */
                    printf("Integer value: %d\n", *(int*)generic_ptr);

                    /* Point the exact same pointer to a float */
                    generic_ptr = &float_var;
                    /* To print it, cast generic_ptr to a float pointer (float*) before dereferencing (*) */

                    printf("Float value: %.2f\n", *(float*)generic_ptr);

                    return 0;
                }

```
````


    (2) Dynamic Memory Allocation (Heap):
        Memory allocated dynamically on the Heap at runtime persists until explicitly released.
        void* malloc(int Bytes); allocates raw memory of specified size.
        Example: 
````
```c        
            int *x = (int*)malloc(20); /* allocates 20 contiguous bytes on Heap. */
```
````

    (3) Why learn:
        (3.1) Pointers:

            - Hardware & Embedded Systems Control: 

                Directly manipulate memory-mapped I/O registers, peripheral control,
                and bare-metal memory structures.

            - Efficient Function Call Overhead: 

                Pass large structures and arrays by reference (`address`) using
                lightweight pointers rather than copying large chunks of data across stack frames.

            - Advanced Data Structures: 

                Serve as the fundamental building block and a tool
                for complex system that require Matrix arithmetic,
                efficiently managed by the pointers.



        (3.2) Dynamic Memory Allocation (Heap):

            - Flexible Runtime Sizing: 

                Allocate memory based on runtime conditions (e.g., user input or file sizes)
                instead of hardcoding array limits at compile time.

            - Lifetime Management: 

                Control object persistence beyond function return bounds,
                allowing data to remain available across program modules.

            - Memory Optimization:

                Allocate memory strictly when needed and release it immediately after use,
                reducing the RAM footprint in constrained systems.
````