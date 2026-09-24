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
                          {Analyzes the logical structure of your program to make it run faster, consume less memory, or use less battery power without altering its
                          intended behavior: (if (false) or replaces 24 * 60 * 60 directly with 86400)}.
        
                
            (1.1.3) The composition:
                - Preprocessor: Cleans code, expands macros, and attaches header file (referals) declarations.
                - Compiler: Translates high-level (human-readable) language into target-specific Assembly code.
                - Assembler: Converts Assembly code into relocatable binary object files (.o / .obj) (Machine code).
                - Linker: Combines object files and libraries into a final executable binary (referal explanation).


            Note: Explaining what is a macro:
                In programming (specifically C/C++), a macro is a rule that tells the Preprocessor to replace a specific name or keyword with a block of text before
                the compiler ever reads the code.
                
                It is essentially a smart text search-and-replace mechanism.

                The preprocessor does not understand language rules, data types, or mathematics—it simply swaps string A withstring B.In C/C++, macros are declared
                using the #define directive.

                For example:

                    #define PI = 3.14
                    int main(void)
                    {
                        float r = 5; /* In units of centimeter */
                        float area =  PI * r * r /* Instead of writting {3.14 * r * r;} */ 
                        return 0;
                    }

            
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
                


------------------------------------------------------------------------------------------------------------------------------------------------------------------------



        (1.2) Preprocessor:

            (1.2.1) What is a preprocessor:

                The Preprocessor is the first software tool executed in the compilation pipeline.
                It is a text-manipulation utility that processes special instructions (called directives) in the source code before the actual compilation begins.
                
                It does prepare the code before being compiled such as removing comments: " /* Hello, World! */ ", macros definitions: " #define PI = 3.14 ", or
                references to external files binding: " #include "Library.h" ".

            Note:
                The preprocessor does not understand programming language syntax, data types, or logic.
                It operates purely as a text parser, expander, and cleaner.
            
            (1.2.2) What does it do:
                (1.2.2.1) Header inclusion:

                    It binds the source code file (with extensions ".c" or ".cpp") with a referenced library that ends with (".h" or ".hpp").


                (1.2.2.2) Macro Expansion ("#define"):

                    Macros replace identifiers with target string tokens throughout the file.

                    (1.2.2.2.1) Object-like Macros (Constants):
                    
                        """
                        #define e  2.71828 
                        """
                        Every occurrence of e (Euler's constant) is directly swapped with 2.71828.



                    (1.2.2.2.2) Function-like Macros & Special Operators:

                        """
                        #define SQUARE(x) ((x) * (x)) 
                        """ 
                        The preprocessor also supports two special macro operators:


                        (1.2.2.2.2.1) Stringification (#): Converts a macro parameter into a string literal.

                            """
                            #define TO_STR(x) #x
                            TO_STR(123) /* (Expands to "123") */
                            """

                        (1.2.2.2.2.2) Token pasting / Concatenation (##): Glues two tokens together to form a new single token.

                            """
                                #define MAKE_VAR(name, id) name##_##id
                            """
                            int MAKE_VAR(user, 10) = 5; /*Expands to: int user_10 = 5;



                    (1.2.2.2.3) Critical Macro Pitfalls:

                    Because macros do string substitution rather than evaluation, they can introduce subtle bugs:

                        (1.2.2.2.3.1) Precedence Bugs (Missing Parentheses):
                            """
                            #define MULTIPLY(a, b) a * b
                            int result = MULTIPLY(1 + 2, 3 + 4); /* Expands to: 1 + 2 * 3 + 4  --> Evaluates to 11 (Not 21!) */
                            """
                        Fix: Always wrap every parameter and the entire expansion in parentheses: #define MULTIPLY(a, b) ((a) * (b))

                        (1.2.2.3.2) Double Evaluation Side Effects:
                            """
                            #define MAX(a, b) ((a) > (b) ? (a) : (b)) /* Ternary operation */
                            int x = 5, y = 2;
                            int m = MAX(x++, y);
                            """





                (1.2.2.3) Conditional compilation:

                (1.2.2.4) Source code cleanup and line marking:

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        (1.3) Compiler:
------------------------------------------------------------------------------------------------------------------------------------------------------------------------        
        (1.4) Assembler:
------------------------------------------------------------------------------------------------------------------------------------------------------------------------        
        (1.5) Linker:
------------------------------------------------------------------------------------------------------------------------------------------------------------------------        
    
    (2) Introduction to array:

```