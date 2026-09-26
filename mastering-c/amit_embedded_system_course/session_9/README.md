# Session (9):
Learned (mixed with personal search):
````
    (1) Clarifying keywords, and labels:

        (1.1) What is a RAM:
            (1.1.1) Definition:
                
                Short for "Random Access Memory".
                It is a type of memory where the CPU can read and write to any memory location
                regardless of its physical position.
            
            (1.1.2) How is RAM structured:

                RAM can be visualized as a giant, linear array of byte-sized "mailboxes".
                The RAM is a volatile memory (once power cut or reset, all the data are removed)
                    - Byte Addressing:

                        Every single byte (equivalent to 8 bits) in RAM has a unique, sequential numerical
                        identifier called its "Memory Address"  and it is usually written in hexamdecimal numerical
                        system such as: (0x2000000)
                    
                    - Data Allocation:

                        Whenever a variable is declared in C programming language, the compiler reserves a specific number
                        of contiguous RAM bytes based on the variable's data type.
                        For:

                            - char: 1 byte
                            - int: 4 bytes
                            - float: 4 bytes.

                        For example:
````
```c
                            int x = 10 /* Places the value 10 across 4 memory bytes starting at an address like 0x1000. */
                            x = 20;  /*The value is overwritten with 20 in the 0x1000 memory address */
```
````
                The RAM is composed of 5 layers:
                    - .text Segment (Code Segment).           
                    - .data Segment (Initialized Static Memory).           
                    - .bss Segment (Uninitialized Static Memory).           
                    - Heap Segment (Dynamic Memory).           
                    - Stack Segment (Automatic Memory).    


                (1.1.2.1) What is [".text", ".data", ".bss", "Heap", "Stack"] segments.
                    (1.1.2.1.1) .text segment:

                        It is the segment where the binary machine code (assembly instructions) of a program is stored,
                        it is marked as read-only to prevent accidental modification of program code.
                        Remember: Assembly file resulting from the compiler in the compilation toolchain with extension ".s"/".asm".
                    

                    (1.1.2.1.2) .data segment:

                        It is the segment responsible for storing global (Remember global scope variables) and static variables that
                        is explicitly initialized with non-zero values before runtime (before the program runs).

                        These variables remain in the RAM for the entire execution lifetime of the program.
                        (The variables are not deleted from the start of the program till its end).

                        Note: What is a static variable:
                            
                            A static variable is as any kind of variable but is not deleted
                            regardless when its scope has been fully executed (Functions or Iterative control flow)
                            For example:
````
```c
                                int func()
                                {
                                    static int i = 0; /* It is initilized one time then this code line is as if removed */
                                    i += 1;
                                    return
                                }
                                int main(void)
                                {
                                    j = func(); /* j = 1 */ /* The function has ended but the "i" is still there. */
                                    j = func(); /* j = 2 */ /* The "i" is iterated one more time becoming 2. */
                                    return 0; /* After this line, the program ended, all variables are deleted. */
                                }
```
````

                    (1.1.2.1.3) .bss segment:

                        Stores global and static variables that are either uninitialized or 
                        initialized to zero.

                        The system automatically zeroes out this RAM segment at startup.

                    
                    (1.1.3.1.4) Stack Segment (Automatic Memory):
                    
                        Stores local variables and manages active function call stack frames.

                        Memory for a local variable is automatically allocated when entering its block 
                        and automatically deallocated when exiting the block.



                    (1.1.3.1.5) Heap Segment (Dynamic Memory Allocation):
                        A region of RAM allocated and freed dynamically at runtime. 
                        Memory here persists independently of function calls until explicitly released.

                        That means the CPU grants the user this section, but controlling and maintaing the
                        reason is a question of developer's skill for when memory management is out of control,
                        the overflow and leakage will hence affect the contiguous memory layer creating
                        a system wide catastrophy.



                Note:

                        Stack Memory start from upward and grow downward, while Heap Memory start downward and
                        grow upward, if the Heap and Stack memories collided.
                        There might be:

                            - Deep recursion (causing stack overflow).
                            - Heavy dynamic allocation.
````                            
````

        (1.2) CPU register:
            (1.2.1) What is a CPU register:

                A CPU is short for "Central Processing Unit" which is the unit responsible for allocating variable's value
                and dedicating its addresses, it has its own storage section called "CPU register" unlike the RAM, it is very close to the CPU
                as it boasts the operation speed as there is no required data transmittion that is done by storing data in RAM.

                The CPU register is also called "General-Purpose Registers".

                When the CPU performs operations on variables stored in RAM, it cannot operate directly on RAM memory cells.
                It must first load the data from RAM into registers, execute the operation inside registers,
                and store the result back to RAM.



            (1.2.2) Advantages of CPU register over RAM:
                - Instantaneous Access.
                - Limited capacity.
                - No Memory Address.
````  
````

        (1.3) Storage classes:
            (1.3.1) Attributes of storage class:
                - Storage Duration (Lifetime): It is where and how long does the variable exist in memory (RAM or CPU Registers).
                - Scope: The visibility region of the source code where the variable can be asseseed.
                - Linkage: Whether the variable/function can be referenced from other ".c" source file (Remember: Linker in Compilation Toolchain).
                - Location: Where in hardware the variable is stored (in RAM: [.text, .data, .bss, stack, heap] or in CPU register).

                (1.3.1.1) Storage Duration:
                    (1.3.1.1.1) Automatic Storage Duration:

                        - Memory is created temporarily when execution enters the scope/block "{}" and is automatically deallocatd when exiting "}".
                        - Stored in Stack Memory (or CPU register if requested).
                        - Applies strictly to local variable. 

                    (1.3.1.1.2) Static Storage Duration:
                        - Memory is allocated permenantly at program startup and exists until the program terminates.
                        - Stored im ".data" (if initialized with non-zero) or ".bss" (if uninitialized or zeroed).
                        - Applies with global scope and static local variables declared variables.

                

                (1.3.1.2) Variable scope:
                    - Block scope:
                        Variables declared inside block parsed by "{}" such as Functions and Iterative Control Flow are accessed
                        inside that block.

                    - File Scope: 
                        It is larger scope than the "Block scope" as it extends into file level, the variables in that
                        scope is accessible across all the blocks.

                    -  Function scope:
                        Applies exclusively to labels used for flow control:
````
```c
                            for(int i = 0; i < 10; i++ ) { /* Code */ } /* "i" is a "Function Scope" declared variable */
```

````
                    -  Function Prototype Scope:
                        Applies to parameter input of a function:
````
```c
                            void func(int a, float b, char c) { /* Code */ } /* ["a", "b", "c"] are Function Prototype Scope */
```

````
            (1.3.2) Keywords:
                (1.3.2.1) static:

                (1.3.2.2) auto:

                    It is the default condition for every declared variable to be "auto",
                    it is found in Block Scope, saved Automatic Memory

                (1.3.2.3) register:  

                    It is requesting from the CPU for it to permuit storing the variable.

                    It is very helpful for speeding execution process of the program but there
                    is a hefty cost, the CPU might refuse at any time without alerting and
                    it is instructed to be very strict on accepting user's request for variable storaging inside the CPU.

                For example:
````

```c

```

${\color{red}\text{VERY IMPORTANT NOTE}}$:
````
    static type:
        in local scope:
            In functions:
                It does not get deleted after the function ends
            
            In loop:
                It does not get deleted after each new iteration but gets terminated after the loop ends.

        In file scope:
            It indicates that specific variable must and only be accessed inside the file and can not be used outside.
````


````
    (1) Big O notation:
        (1.1) Time complexity:
    
    (2) Storage duration:
        (2.1) Automatic S.D
            (2.1.1) auto
            (2.1.2) register
            (2.1.3) stack block:
                (2.1.3.1) static storage:
                    (2.1.3.1.1) data layer
                    (2.1.3.1.2) bss layer

                (2.1.3.2) Automatic layer:
                    (2.1.3.2.1) Stack layer

                (2.1.3.3) Dynamic Memory Allocation:
                    Heap layer.

        (2.2) Static S.D:
            (2.2.1) static scope:
            (2.2.2) extern:

    (3) Surface understanding of pointers
````