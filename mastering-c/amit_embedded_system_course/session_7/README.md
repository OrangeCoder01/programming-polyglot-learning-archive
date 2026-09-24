# Session (7):
Learned (mixed with personal research):
```
    (1) Details on Compilation toolchain:
        (1.1) Overview of compilation toolchain and its composition softwares:
            (1.1.1) What is compilation toolchain:
                "Compilation toolchain" is a collection of software development tools linked toghether
                in a sequential order (pipeline) where the output of a software is the input of the next
                software; thus given name "toolchain".

                Its objective is to transform human-readable code into Machine code that the devices
                can comprehend, whereas making a connection between human made instructions and the
                device's execution.


            (1.1.2) Analogy:

                Two people with two different languages, one speaks Spanish and the other speaks Russian.
                The spanish-speaking person wants to write a letter to the russian-speaking person.

                The spanish-speaking person will need a third party that can understand his language
                and the other recipent's language, and has the ability to translate the letter from one language to another
                whilst keeping the context intact.

                But the third-party translator must have specific skills:
                    - Ability to concisely translate one language to another without affecting the meaning or the context.

                    - Explains some cultural referals that the other might not understand such as:
                    "Go, break a leg", the translator must explain that means "Be quick".

                    - Optimizes the sender's message/letter for removing unnecessary and overly abundant
                    remarks without affecting the context.


                The representations of the analogy:

                    The (spanish-speaking person) is the {programmer/developer} who writes
                    a (message/letter) which is the {source code/ Code file} with (Spanish language)
                    which is {Human-readable code} to a (russian-speaking person) who represents {CPU Hardware}
                    who speaks (Russian) which represents {Machine code}.

                    But due to the language barrier, the spanish-speaking person summoned a 
                    third-party interpreter (Compilation toolchain) to help send the message to the recipient
                    russian-speaking person.

                    The third-party translator {Compilation toolchain} has specific skills:
                        - Ability to concisely translate without affecting the meaning or the narrative:
                          {Converts human-oriented programming structures (if statements, functions, classes, loops) into raw
                          architecture-specific instructions}.

                        - Explains some cultural referals that the other might not understand:
                          {Resolves dependencies: connecting libraries called in the source code that is outside of it
                          #include "LIBRARY_NAME"}.

                        - Optimizes the sender's message/letter for removing unnecessary and overly abundant
                          remarks without affecting the context.
                          {Analyzes the logical structure of your program to make it run faster, consume less memory, or use
                          less battery power without altering its
                          intended behavior: (if (false) or replaces 24 * 60 * 60 directly with 86400)}.
        
                
            (1.1.3) The composition:
                - Preprocessor: Cleans code, expands macros, and attaches header file (referals) declarations.
                - Compiler: Translates high-level (human-readable) language into target-specific Assembly code.
                - Assembler: Converts Assembly code into relocatable binary object files (.o / .obj) (Machine code).
                - Linker: Combines object files and libraries into a final executable binary (referal explanation).


            Note: Explaining what is a macro:
                In programming (specifically C/C++), a macro is a rule that tells the Preprocessor to replace a specific name or
                keyword with a block of text before
                the compiler ever reads the code.
                
                It is essentially a smart text search-and-replace mechanism.

                The preprocessor does not understand language rules, data types, or mathematics—it simply swaps string A
                withstring B.In C/C++, macros are declared
                using the #define directive.

                For example:
````
```C
                    #define PI  3.14
                    int main(void)
                    {
                        float r = 5; /* In units of centimeter */
                        float area =  PI * r * r /* Instead of writting {3.14 * r * r;} */ 
                        return 0;
                    }
```
            
            (1.1.4) The block diagram of the compilation toolchain generated by Gemini:

                            +----------------------------------+
                            |      Header Files (.h / .hpp)    |
                            +----------------------------------+
                                                |
                                                | (Injected via #include)
                                                v
                +------------------+   +--------------------------+
                | Source Code File |   |     1. PREPROCESSOR      |
                |    (.c / .cpp)   |-->|      (e.g., `cpp`)       |  <-- Flags: `gcc -E`
                +------------------+   +--------------------------+
                                                |
                                                | Output: Preprocessed Source Text
                                                v
                                    +--------------------------+
                                    |   Preprocessed Source    |
                                    |       (.i / .ii)         |
                                    +--------------------------+
                                                |
                                                v
                                    +--------------------------+
                                    |       2. COMPILER        |
                                    |     (e.g., `cc1`)        |  <-- Flags: `gcc -S`
                                    +--------------------------+
                                                |
                                                | Output: Architecture Assembly Text
                                                v
                                    +--------------------------+
                                    |      Assembly Code       |
                                    |       (.s / .asm)        |
                                    +--------------------------+
                                                |
                                                v
                                    +--------------------------+
                                    |       3. ASSEMBLER       |
                                    |      (e.g., `as`)        |  <-- Flags: `gcc -c`
                                    +--------------------------+
                                                |
                                                | Output: Unlinked Binary Machine Code
                                                v
                                    +--------------------------+
                                    | Relocatable Object File  |
                                    |       (.o / .obj)        |
                                    +--------------------------+
                                                |
                                                |
                +-----------------------------+-----------------------------+
                |                             |                             |
                | (Other Project Objects)     | (Static Libraries)          | (Shared/Dynamic Libraries)
                v                             v                             v
                +------------------+   +------------------+          +------------------+
                |  Other Object    |   | Static Libraries |          | Dynamic Libraries|
                |  Files (.o)      |   |   (.a / .lib)    |          |  (.so / .dll)    |
                +------------------+   +------------------+          +------------------+
                        |                      |                             |
                        +----------------------+-----------------------------+
                                                |
                                                v
                                    +--------------------------+
                                    |        4. LINKER         |
                                    |      (e.g., `ld`)        |  <-- Flags: `gcc -o`
                                    +--------------------------+
                                                |
                                                | Output: Resolved Machine Binary
                                                v
                                    +--------------------------+
                                    |    FINAL EXECUTABLE      |
                                    |  (ELF / PE / Mach-O)     |
                                    +--------------------------+
                




        (1.2) Preprocessor:

            (1.2.1) What is a preprocessor:

                The Preprocessor is the first software tool executed in the compilation pipeline.
                It is a text-manipulation utility that processes special instructions (called directives) in the source code 
                before the actual compilation begins.
                
                It does prepare the code before being compiled such as removing comments: " /* Hello, World! */ ", macros 
                definitions: " #define PI = 3.14 ", or
                references to external files binding: " #include "Library.h" ".

            Note:
                The preprocessor does not understand programming language syntax, data types, or logic.
                It operates purely as a text parser, expander, and cleaner.
            
            (1.2.2) What does it do:
                (1.2.2.1) Header inclusion:

                    It binds the source code file (with extensions ".c" or ".cpp") with a referenced library that ends with 
                    (".h" or ".hpp").


                (1.2.2.2) Macro Expansion ("#define"):

                    Macros replace identifiers with target string tokens throughout the file.

                    (1.2.2.2.1) Object-like Macros (Constants):
                    
````C
                            #define e  2.71828 
                            int main(void)
                            {
                                int result = e * 2; /* result = 5.43656 */
                            }
````
                        Every occurrence of e (Euler's constant) is directly swapped with 2.71828.


                    (1.2.2.2.2) Function-like Macros & Special Operators:

````C
                            #define SQUARE(x) ((x) * (x)) 
                            int main(void)
                            {
                                int result = SQUARE(4) /* result = 4*4 = 16 */
                                return 0;
                            }
```` 
                        The preprocessor also supports two special macro operators:

                        (1.2.2.2.2.1) Stringification (#): Converts a macro parameter into a string literal.

````C
                                #define TO_STR(x) #x
                                TO_STR(123) /* (Expands to "123") */

````
                        (1.2.2.2.2.2) Token pasting / Concatenation (##): Glues two tokens together to form a new single token.

````C
                                #define MAKE_VAR(name, id) name##_##id
                                int main(void)
                                {
                                    int MAKE_VAR(variable, 1) = 4 /*Now there is an initialilzed variable called "variable_1"*/
                                    return 0;
                                }

````
                            int MAKE_VAR(user, 10) = 5; /*Expands to: int user_10 = 5;


                    (1.2.2.2.3) Critical Macro Pitfalls:

                    Because macros do string substitution rather than evaluation, they can introduce subtle bugs:

                        (1.2.2.2.3.1) Precedence Bugs (Missing Parentheses):
                        
````C
                                #define MULTIPLY(a, b) a * b
                                int result = MULTIPLY(1 + 2, 3 + 4); /* Expands to: 1 + 2 * 3 + 4  --> Evaluates to 11 (Not 21!) */

````

                        Fix: Always wrap every parameter and the entire expansion in parentheses: 
````C
                                #define MULTIPLY(a, b) ((a) * (b))
                                int main(void)
                                {
                                    int result = MULTIPLY(3, 4) /* result = 12 */
                                    return 0;
                                }
````

                        (1.2.2.3.2) Double Evaluation Side Effects:

````C
                                #define MAX(a, b) ((a) > (b) ? (a) : (b)) /* Ternary operation */
                                int x = 5, y = 2;
                                int m = MAX(x++, y); /* ((x++) > (y) ? (x++) : (y)), if true, x = 7, else x = 6  */

````



                (1.2.2.3) Conditional compilation:

                    Conditional compilation allows parts of the code to be included or excluded based on macro definitions or
                    environment flags.

                    (1.2.2.3.1) Guarding Platforms:

````C
                            #define NUMBER 404
                            #if defined(NUMBER) printf("404");
                            #endif
````

                        (1.2.2.3.1.1) Header Guards:

                        Traditional Guard: Uses conditional directives.

                            A non-standard but universally supported preprocessor directive that tells the compiler driver
                            to open and include the header file only once per compilation:

````C
                                    #ifndef MY_HEADER_H
                                    #define MY_HEADER_H
                                    MY_HEADER_H = math_library_c.h

                                    #endif
    
````

                        (1.2.2.3.1.2) Pragma once:
````C       
                                        #define MY_HEADER_H
                                        #pragma once
````



                    (1.2.2.3.3) Diagnostic Directives & Predefined Macros:

                            Halts preprocessing immediately and issues a fatal error. 
                            Often used to enforce compilation requirements.
                            For example:
````C
                                    #if __STDC_VERSION__ < 201112L 

                                        #error "This project requires a C11-compliant compiler!"

                                    #endif
    
````
                        
                    (1.2.2.3.4) Built-in Predefined Macros

                        The preprocessor automatically injects several runtime/compile-time diagnostic variables:

                            __FILE__: Name of the current source file (string).
                            __LINE__: Current line number in the source file (integer).
                            __DATE__: Date compilation started ("Mmm dd yyyy").
                            __TIME__: Time compilation started ("hh:mm:ss").


                    (1.2.2.3.5) Command-Line Preprocessor Controls
                        You can inject preprocessor directives directly from your build command:

                        Define a macro via CLI (-D):
                            {gcc -DDEBUG -DMAX_VAL=100 main.c} (Acts as if #define DEBUG and #define MAX_VAL 100 were written at the top of the file).

                        Inspect preprocessed output (-E):
                            {gcc -E main.c -o main.i}

                        Dump all active macros (-dM -E):
                            {gcc -dM -E main.c} (Lists all internal and user-defined macros).




                (1.2.2.4) Source code cleanup and line marking:

                    Comment Removal: Every comment (// or /* ... */) is removed and replaced with a single space character.

                    Before preprocessor cleanup:
```C
                    #include <Stdio.h> // The I/O library
                    int main(void) /* The main function */
                    {
                        int is_here = 0;// A boolean int
                        if(is_here == 1) { printf("It is here!"); } 
                        else { printf("It is not here!"); }
                        return 0;
                    }
```
                    After preprocessor cleanup:
```C
                    #include <Stdio.h> 
                    int main(void)
                    {
                        int is_here = 0;
                        if(is_here == 1) { printf("It is here!"); } 
                        else { printf("It is not here!"); }
                        return 0;
                    }                    
```


        (1.2.3) The output:

                (.i/.ii) file.



        (1.3) Compiler:

            (1.3.1) What is the Compiler:

                The Compiler takes the expanded, preprocessed text file (.i / .ii) and translates it 
                into architecture-specific Assembly language instructions (.s / .asm).

                It ensures the source code strictly adheres to the language grammar rules.


            (1.3.2) The Three Internal Phases of Compilation:

                (1.3.2.1) Front-End (Language-Specific):
                    - Lexical Analysis (Tokenization): Breaks raw character streams into meaningful tokens (keywords, identifiers, operators).
                    - Syntax Analysis (Parsing): Builds an Abstract Syntax Tree (AST) to check if tokens follow language grammar rules.
                    - Semantic Analysis: Performs type-checking, verifies scope rules, and checks function call signatures.


                (1.3.2.2) Middle-End (Architecture-Independent Optimization):
                    - Converts the AST into an Intermediate Representation (IR) (e.g., GCC GIMPLE or LLVM IR).

                    - Performs logical optimizations regardless of target CPU:
                        * Dead Code Elimination: Removes unreachable blocks (e.g., `if (0) { ... }`).
                        * Constant Folding: Pre-calculates constant expressions at compile time (`24 * 60 * 60` -> `86400`).
                        * Function Inlining: Replaces small function calls with actual function bodies to reduce call overhead.


                (1.3.2.3) Back-End (Target Architecture-Specific):
                    - Translates optimized IR into target-specific Assembly code (e.g., x86_64, ARM, RISC-V).
                    - Performs Register Allocation: Decides which variables live in fast hardware registers vs. RAM stack memory.
                    - Performs Instruction Scheduling: Reorders assembly instructions to maximize CPU pipeline efficiency.


            (1.3.3) Command-Line Controls:

                - Generate Assembly text file:
                    {gcc -S main.c -o main.s}
        

            (1.3.4) The Output:

                Assmebly file with extension ".s/.asm".


        (1.4) Assembler (e.g., `as`):

            (1.4.1) What is the Assembler:
            
                The Assembler is a software converts target-specific Assembly code (.s/.asm) into unlinked, relocatable 
                binary Machine Code stored inside Object files (.o / .obj).


            (1.4.2) Key Responsibilities:

                - Translation: Converts human-readable mnemonics (`mov`, `add`, `push`, `jmp`) 
                  directly into binary bitstreams (0s and 1s) understood by the CPU.

                - Organizes Memory Sections: Splits code and data into RAM (Random Access Memory):

                    * .text   : Binary machine code instructions.
                    * .data   : Initialized global and static variables.
                    * .bss    : Uninitialized global/static variables (zero-initialized at runtime startup).
                    * .rodata : Read-only constants and string literals.

                - Symbol & Relocation Table Generation:

                    * Creates a Symbol Table listing all internal/external functions and variables.
                    * Creates a Relocation Table marking memory addresses that cannot be calculated 
                      yet (e.g., calls to external functions like `printf` or variables defined in other files).


            (1.4.3) Command-Line Controls:
                - Stop after assembly stage (Output relocatable object file):

                    {gcc -c main.c -o main.o}

                - Inspect object file details (using binary utility tools):

                    {objdump -d main.o} (Disassembles binary machine code back to assembly)
                    {nm main.o} (Inspects the Symbol Table)



        (1.5) Linker (e.g., `ld`):

            (1.5.1) What is the Linker:

                The Linker is the final stage of the toolchain. It combines one or more relocatable 
                object files (.o) and compiled libraries (.a / .so) into a single executable binary 
                file (ELF on Linux, PE on Windows, Mach-O on macOS).

            (1.5.2) Primary Responsibilities:

                (1.5.2.1) Symbol Resolution:

                    Matches every identifier call/reference with its matching definition.
                    * If a reference is missing across all files/libraries -> Throws `Linker Error: Undefined reference to 'X'`.
                    * If multiple definitions exist for the same symbol -> Throws `Linker Error: Multiple definition of 'X'`.


                (1.5.2.2) Relocation & Address Patching:

                    Merges matching sections from all input `.o` files (e.g., concatenates all `.text`.

                    sections into one master `.text` block) and assigns absolute/relative memory addresses to every instruction, 
                    patching placeholder jump addresses created by the assembler.


            (1.5.3) Linking Strategies:

                (1.5.3.1) Static Linking (.a / .lib):

                    Extracts required machine code directly from static archive libraries and copies it 
                    into the final executable.

                    * Advantage: Binary is completely standalone; requires no external dependencies.
                    * Disadvantage: Larger binary size; requires recompilation to update library bugs.

                (1.5.3.2) Dynamic/Shared Linking (.so / .dll):

                    Inserts stub lookup tables (PLT/GOT) into the binary instead of full library code. 
                    The Operating System's Dynamic Loader loads the shared library into RAM at runtime.

                    * Advantage: Smaller binary size; multiple running applications share a single library in RAM.
                    * Disadvantage: Program fails to run if required `.so`/`.dll` files are missing from target system.

            (1.5.4) Command-Line Controls:

                - Link multiple object files into executable:
                    {gcc main.o math_utils.o -o my_program}

                - Link against an external library (e.g., math library `libm`):
                    {gcc main.o -lm -o my_program}




    (2) Introduction to Arrays:

        (2.1) What is an Array:
            An array is a fixed-size, contiguous sequence of elements of the same data type stored 
            back-to-back in memory under a single variable identifier.

        (2.2) Core Characteristics:
            - Uniform Type: All elements must share the exact same data type (e.g., all `int`, all `char`).
            - Fixed Size: Array size must be specified at definition (or dynamically allocated on heap) 
              and cannot grow or shrink automatically in standard C.
            - Contiguous Memory Allocation: Elements sit in adjacent byte addresses without gaps.

        (2.3) Zero-Based Indexing & Offset Mathematics:
            Array indices start at 0 because the index number represents an offset multiplier from the base address:



    (3) Data types:
        (3.1) Primitive data type:
            (3.2.1) int.
            (3.2.2) float.
            (3.2.3) char.
            (3.2.4) double.
            (3.2.5) void.


        (3.2) Derived data type:
            (3.2.1) Array.
            (3.2.2) pointer.
            (3.2.3) functions.


        (3.3) User defined data type:
            (3.3.1) struct.
            (3.3.2) union.
            (3.3.3) enum.
```