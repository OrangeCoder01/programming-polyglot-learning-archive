# Session (12):
Learned (mixed with personal research):
Note:
````
    This session started to explain the user-defined data type as the
    previous session covered both Primitive: 
    [char, int, float, void: [function's parameter, function's return, void pointer]]

    and derived data types:
    [functions, arrays, pointers]
````
&emsp; ${\color{red}\text{(1)}}$: **Important Keywords**
<br>

&emsp;&emsp; ${\color{blue}\text{(1.1)}}$: **typedef**  
````
            The typedef keyword creates a user-defined alias or nickname for an existing data type.
            It does not create a new type or allocate memory; it simply improves code readability, portability,
            and abstraction—especially when working with complex types like struct, union, or function pointers.
            For example:
````
```c
                #include <stdio.h>
                typedef unsigned char u_i_8; /* 'u' for unsigned (positive integer representation), 'i' for integer, and '8' for the number of bits (1 bytes) */
                /* Note: chars are integers but require 1 byte, 8 bits.*/
                typedef unsigned int u_i_32; /* containing 32 bits*/
                typedef float s_f_32;
                typedef double s_f_64; 
                /* same as */
                /*
                typedef signed double s_f_64; 
                */
                /* But that will yield to compilation; the default datatype declaration is signed */

                int main(void)
                {
                    u_i_32 x = 3;
                    s_f_32 y = 5.0;
                    s_f_64 z = 0;

                    z = (s_f_64)x + (s_f_64)y;
                    printf("z = %.2f", z); /* z = 8.0 */
                    return 0;
                }
```
<br>

&emsp;&emsp; ${\color{blue}\text{(1.2)}}$: **inline**  

````            
            The inline keyword is a function specifier in C used to optimize program execution speed.
            When declaring a function as inline, the compiler is requested to replace every
            call to that function with the actual body of the function's code.

            For very small, frequently executed functions, this overhead takes more time than executing 
            the function's actual logic. 

            The inline keyword removes this overhead by pasting the function's code
            directly into the calling function during compilation.

            But VERY IMPORTANT REMARK:

                It is not a command the compiler will execute,
                it is the scenario as requesting the CPU to consider a variable inside its register,
                the compiler can refuse using the inline function if the function is too larger.


            Benefits:
                Execution Speed: Eliminates function call overhead, making it ideal for time-critical operations
                (like toggling a GPIO pin or reading a fast sensor).

                Stack Memory Savings: Since no variables or return addresses are pushed to the stack,
                it saves precious RAM on constrained microcontrollers.

                Better than Macros: While preprocessor macros (#define SQUARE(x) (x*x)) also substitute code,
                inline functions are much safer because the compiler strictly checks data types and evaluates arguments properly.
                


            Comparing Macros with Inlining:
````
|Feature|Preprocessor Macro (`#define`)|Inline Function (`inline`)|
|:---|:---|:---|
|`Processed By`|**Preprocessor** |**Compiler**|
|`Mechanism`|**Blind text substitution/replacement**|**Code is inserted at the call site, but treated as a function**|
|`Type Checking`|**None**|**Strict** The compiler checks parameter and return data types|
|`Argument Evaluation`|**Arguments are evaluated wherever they appear in the text**|**Arguments are evaluated exactly once** before the function logic executes, just like standard functions|
|`Debugging`|**Difficult** The macro name disappears after preprocessing, so it does not exist in the debugger symbol table|**Easier** The compiler retains symbol information, allowing you to step through the code during debugging|
|`Scope & Encapsulation`|**Global** Macros do not respect C scope rules unless manually removed by `#undef` |**Local** Follows standard C scope rules and can be restricted to a single file using static inline|
|`Compiler Control`|**Forced** The preprocessor will always substitute the text regardless of code size|The **compiler evaluates** if inlining is **optimal** and can **refuse** to inline it if the function is **too complex**|
<br>

````
            For example:
````
```c
                #include <stdio.h>
                static inline int SetBit(int bitstream, int bit_order) {return (bitstream |( 1 << bit_order));}
                static inline int ClrBit(int bitstream, int bit_order) {return (bitstream & (~(1 << bit_order)));}
                static inline int GetBit(int bitstream, int bit_order) {return ((bitstream >> bit_order) & 1);}
                static inline int Togbit(int bitstream, int bit_order) {return (bitstream ^ (1 << bit_order));}


                int main(void)
                {
                    printf("SetBit(8, 4) = %d\n", SetBit(8, 4));
                    printf("ClrBit(16, 4) = %d\n", ClrBit(16, 4));
                    printf("GetBit(34, 5) = %d, GetBit(34, 3) = %d\n",GetBit(34,5), GetBit(34, 3));
                    printf("TogBit(128, 7) = %d, TogBit(128, 0) = %d\n", Togbit(128, 7), Togbit(128, 0));
                    return 0;
                }
```

<br>

&emsp;&emsp;&emsp; ${\color{blue}\text{(1.3)}}$: **union**:
````
            A union is a user-defined data type that is syntactically very similar to a struct.
            However, the critical difference lies in how they handle memory: while a structure allocates
            separate memory for every single member, all members of a union share the exact same memory location.


            The primary purpose of a union is memory conservation and flexible data representation;
            Because all members overlap in memory, the compiler only allocates enough space for the 
            largest member inside the union.

            It searches for the highest size data type, and apply it as the default data type
            for the rest of the data type, by padding space.

            
            For example:
````
```c
                union Payment 
                {
                    long long credit_card; /* 8 bytes */ 
                    char paypal[20];       /* 20 bytes */ 
                }; /* Total: 20 bytes per customer */

                union SensorData 
                {
                    int whole_number; /* Looks at the 4 bytes as one big number */ 
                    char individual_bytes[4]; /* Looks at the exact same 4 bytes as a list of small pieces */  
                };
```
````
            There is only one variable "Payment" or "SensorData"
            where each have the characteristics of both highest size.
            They can store char string or integers, only one at a time.
````
```c
                union 
                {
                    int X;        /* 4 Bytes */ 
                    short int Y;  /* 2 Bytes */ 
                    char Z;       /* 1 Byte */ 
                } My_union;
```
````
    
        int X: 4 bytes.
        short int Y: 2 bytes.
        char Z: 1 byte.

        +---------------+---------------+---------------+---------------+
        |               |               |               |               |    
        |       X       |      X        |        X      |         X     |    Integer
        |               |               |               |               |  
        +---------------+---------------+---------------+---------------+
        |               |               |               |               |    
        |       Y       |      Y        |   pading      |     pading    |    Short Integer
        |               |               |               |               |  
        +---------------+---------------+---------------+---------------+    
        |               |               |               |               |    
        |       Z       |   pading      |    pading     |    pading     |    Char
        |               |               |               |               |    
        +---------------+---------------+---------------+---------------+   

````
````
            Another example:
````
```c
                #include <stdio.h>

                typedef union 
                {
                    int var1; /* 4 bytes */ 
                    int var2; /* 4 bytes */ 

                } SharedMemory;

                int main(void) 
                {
                    SharedMemory my_union;

                    printf("Size of union: %zu bytes\n\n", sizeof(my_union)); /* The size will be exactly 4 bytes, not 8 bytes! */ 
                    my_union.var1 = 10; /* Assign a value to var1 */ 
                    
                    printf("--- Assigned 10 to var1 ---\n"); /* Both will print 10 because they look at the exact same 4 bytes of memory */ 
                    printf("var1 = %d\n", my_union.var1);
                    printf("var2 = %d\n\n", my_union.var2);

                    my_union.var2 = 99; /* Assign a value to var2 */
                    
                    printf("--- Assigned 99 to var2 ---\n");/* Both will print 99 because var2 overwrote the shared memory */ 
                    printf("var1 = %d\n", my_union.var1);
                    printf("var2 = %d\n", my_union.var2);

                    return 0;
                }
```
<br>

&emsp;&emsp;&emsp; ${\color{blue}\text{(1.4)}}$: **enum** <br>
````
            An enumeration (enum) is a user-defined data type that assigns readable text names to integer constants. 
            It replaces meaningless "magic numbers" (like 0, 1, or 2) in code with descriptive words, making developer's code's logic
            much easier to read and maintain.

            Default Numbering: If you do not assign a number, the compiler automatically assigns 0 to the first name, 1 to the second, 2 to the third, and so on.
            Explicit Numbering: You can manually assign specific integer values. Any unassigned names that follow will just increment by 1 from the previous value.

            To the CPU, an enum is just a standard integer. 
            The text names only exist to help the programmer.
            For example:
```` 
```c
                #include <stdio.h>

                /* Define a generic enum for Days */ 
                typedef enum {
                    SUNDAY,     /* Auto: 0 */
                    MONDAY,     /* Auto: 1 */
                    TUESDAY,    /* Auto: 2 */
                    WEDNESDAY,  /* Auto: 3 */
                    Friday = 6, /* Explicitly 5*/
                    THURSDAY,   /* Auto: 4 */
                    Saturday    /* Auto: 6 */
                } DayOfWeek;

                int main(void) 
                {
                    DayOfWeek today = MONDAY;

                    printf("Today is day number: %d\n", today);
                    if (today == MONDAY)  { printf("It is Monday, back to work!\n"); } /* readable name */
                    return 0;
                }
```
<br>

&emsp;&emsp;&emsp; ${\color{blue}\text{(1.5)}}$: **goto** ${\color{red}\text{(used in session (9) code example but was not explained)}}$ <br>

````
            The goto keyword is a jump statement. 

            It tells the CPU to instantly jump to a specific labeled line of code within the same function,
            skipping everything in between.

            It is heavily discouraged using "goto" due to renders code less readable
            and introduce desultories in the sequential control flow causing confusion
            and that confusion remarks that code as "Spaghetti Code".

            For example:
````
```c
                #include <stdio.h>

                int main(void) {
                    printf("Step 1: Program starts.\n");
                    goto target_destination; /* Instantly jump to 'target_destination' */
                    
                    printf("Step 2: You will never see this print.\n"); /* This code is completely skipped */
                    printf("Step 3: Or this one.\n");

                
                    target_destination: 
                    printf("Step 4: Landed at the destination!\n");

                    return 0;
                }
```
<br>

&emsp;&emsp;&emsp; ${\color{blue}\text{(1.6)}}$: **struct** <br>
````
            A structure (struct) is a user-defined data type that allows you to group related variables
            of completely different data types together under one single name.

            It can be thought as a digital filing cabinet for a specific entity.

            Instead of having three separate variables floating around the code for a 
            person's name, age, and height as an example, bundling them neatly inside one struct.


            Memory Allocation: 

                Unlike a union a struct gives every single member
                its own dedicated memory space lined up one after another.

            The Dot Operator (.): 

                store or read data inside a specific member of the structure, requires using dot (.)
                operator between the structure's name and the member's name.
                For example:
````
```c
                #include <stdio.h>
                #include <string.h>

                
                struct Person /* Define the struct blueprint */
                {
                    char name[20]; /* 20 bytes */
                    int age;       /* 4 bytes */
                    float height;  /* 4 bytes */
                };

                int main(void) 
                {
                    struct Person person1;

                    /* Assign values to the individual members using the dot (.) operator */
                    strcpy(person1.name, "Alice");
                    person1.age = 25;
                    person1.height = 1.68;
             
                    printf("--- Person Profile ---\n");    
                    printf("Name: %s\n", person1.name);
                    printf("Age : %d years old\n", person1.age);
                    printf("Tall: %.2f meters\n\n", person1.height);

                    
                    printf("Total size of struct: %zu bytes\n", sizeof(person1)); 
                    return 0;
                }
```
````
        For non_optimized_union:

            int x: 4 bytes.
            char y: 1 bytes.
            int z: 4 bytes.
            char A: 1 bytes.

        +---------------+---------------+---------------+---------------+
        |               |               |               |               |    
        |       x       |      x        |        x      |         x     |    Integer
        |               |               |               |               |  
        +---------------+---------------+---------------+---------------+
        |               |               |               |               |    
        |       Y       |   pading      |   pading      |     pading    |    Char
        |               |               |               |               |  
        +---------------+---------------+---------------+---------------+    
        |               |               |               |               |    
        |       z       |       z       |        z      |        z      |    Integer
        |               |               |               |               |     
        +---------------+---------------+---------------+---------------+    
        |               |               |               |               |    
        |       A       |   pading      |    pading     |    pading     |    Char
        |               |               |               |               |    
        +---------------+---------------+---------------+---------------+   

        That cost 16 bytes --> 4 + 4 + 4 + 4 = 16


    For optimized_union:
    
            int x: 4 bytes.
            char y: 1 bytes.
            int z: 4 bytes.
            char A: 1 bytes.

        +---------------+---------------+---------------+---------------+
        |               |               |               |               |    
        |       x       |      x        |        x      |         x     |    Integer
        |               |               |               |               |  
        +---------------+---------------+---------------+---------------+
        |               |               |               |               |    
        |       y       |       A       |   pading      |     pading    |    Char
        |               |               |               |               |  
        +---------------+---------------+---------------+---------------+    
        |               |               |               |               |    
        |       z       |      z        |       z       |       z       |    Integer
        |               |               |               |               |    
        +---------------+---------------+---------------+---------------+   

        That cost 12 bytes --> 4 + 4 + 4

````