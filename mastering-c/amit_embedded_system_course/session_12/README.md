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

&emsp;&emsp; ${\color{blue}\text{(1.1)}}$ **typedef**  
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

&emsp;&emsp; ${\color{blue}\text{(1.2)}}$ **inline**  

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

&emsp;&emsp;&emsp; ${\color{blue}\text{(1.3)}}$ **union**:
````
            A union is a user-defined data type that is syntactically very similar to a struct.
            However, the critical difference lies in how they handle memory: while a structure allocates
            separate memory for every single member, all members of a union share the exact same memory location.


            The primary purpose of a union is memory conservation and flexible data representation.
            Because all members overlap in memory, the compiler only allocates enough space for the 
            largest member inside the union.

            It searches for the highest size data type, and apply it as the default data type
            for the rest of the data type, by padding space 
````
&emsp;&emsp;&emsp;&emsp; **${\color{red}\text{(Note)}}$**:<br>
````
                that does not affect the data types 
                (int, float, etc...) outside the defined union,
                inside the user-defined union only 

                For example:
````
```c
                    typedef union 
                    {
                        char X;       // 1 Byte
                        short int Y;  // 2 Bytes
                        int Z;        // 4 Bytes
                    } My_union;
```
````
    
        integer: 4 bytes.
        short int: 2 bytes
        char: 1 byte.

        +---------------------------------------------------------------+
        |               |               |               |               |    
        |  1 byte       |  1 byte       |  1 byte       |  1 byte       |    Integer
        |               |               |               |               |  
        +---------------------------------------------------------------+
        |               |               |               |               |    
        |  1 byte       |  1 byte       |  pading       |  pading       |    Short Integer
        |               |               |               |               |  
        |_______________|_______________|_______________|_______________|    
        |               |               |               |               |    
        | 1 byte        |   pading      |  pading       |    pading     |    Char
        |               |               |               |               |    
        +---------------------------------------------------------------+   

````
````
        (1.4) enum:
        (1.5) goto: (used in session (9) code example but was not explained)
        (1.6) struct

````