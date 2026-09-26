# ${\color{orange}\text{AMIT Embedded System Course}}$
What is ${\color{orange}\text{AMIT Embedded System Course}}$:
```
    AMIT stands for "Assosiation of management and information technology".

    The assosiation located in Egypt, aimed for graduates and undergraduates 
    who are interested or with a profession within STEM (Science-Technology-Engineering-Math) domain
    to help expand their professional skills in their desired field.

    The current course I got enrolled is "Embedded System" course, a helpful course for understanding
    low-level programming and hardware architecture sophistications through implementations.

    This course spans 100 hours, 3 hours per session, 3 sessions per week, 9 hours per week, 36 hours per month,
    spans approximately 3 months with respect to holidays and possible delays.
 
```
<br>

Notes:
```
    Basic understanding of binary mathematics is required with understanding binary related concept such as ASCII,
    but the course starts from basic C programming syntax whilst introducing the software and hardware intricacies 
    such as profound clarification of "Compilation Toolchain", "Memory and its type" and "File I/O".
```

<br>

What will be learned at the end of the course:
````
    (1) Electronics basics:
        (1.1) Communication protocols.
            (1.1.1) CAN (Control Area Network) protocol. 
            (1.1.2) I2C (Inter-Integrated Communication) protocol.
            (1.1.3) UART (Universal Asynchronous Receiver-Transmitter) protocol.
            (1.1.4) SPI (Serial Peripheral Interface) protocol.


        (1.2) RTOS (Real-Time Operating System).
        


        (1.3) Hardware:
            (1.3.1) Compilation toolchain:
                (1.3.1.1) Types of compilation toolchain products:
                    (1.3.1.1.1) gcc toolchain for C programming language.
                    (1.3.1.1.2) g++ toolchain for C++ programming language.

                (1.3.1.2) Core software compositions of compilation toolchain:
                    (1.3.1.2.1) Pre-processor.
                        (1.3.1.2.1.1) macros.
                        
                    (1.3.1.2.2) Compiler.
                    (1.3.1.2.3) Assembler.
                    (1.3.1.2.4) Linker.
                        (1.3.1.2.4.1) Provided/needed table.
                

                (1.3.1.3) Powershell terminal commands:
                    (1.3.1.3.1) Compile file command.
                        {g++ file.cpp -o file}

                    (1.3.1.3.2) File rename. 
                        {Rename-Item}



            (1.3.2) Computer system:
                (1.3.2.1) Types of memory:
                    (1.3.2.1.1) RAM's memory sectioning:
                        (1.3.2.1.1.1) Static memory.
                            (1.3.2.1.1.1.1) .bss segment.
                            (1.3.2.1.1.1.2) .data segment.

                        (1.3.2.1.1.2) Stack memory.
                        (1.3.2.1.1.3) Heap memory.
                    
                    (1.3.2.1.2) CPU register.
                    (1.3.2.1.3) Second storaging (HDD/SSD).
                

                (1.3.2.2) File I/O.
            


            (1.3.3) Microcontroller system:
                (1.3.3.1) Types of memory.
                    (1.3.3.1.1) EEPROM memory
                    (1.3.3.1.2) Flash memory

````
````

    (2) C/C++ programming languages:

        (2.1) Operations:
            (2.1.1) Bit manipulations (Bitwise operations):
                (2.1.1.1) Bitwise operations:
                    (2.1.1.1.1) Built-in bit operations:
                        (2.1.1.1.1.1) Bitwise AND '&'.
                        (2.1.1.1.1.2) Bitwise OR '|'.
                        (2.1.1.1.1.3) Bitwise XOR '^'.
                        (2.1.1.1.1.4) Bitwise NOT `~`.
                        (2.1.1.1.1.5) Bit shift:
                            (2.1.1.1.1.5.1) Left shift '<<'.
                            (2.1.1.1.1.5.2) Right shift '>>'.
                    

                (2.1.1.2) specific purpose bit operations:
                    (2.1.1.2.1) Clear bit (set to 0).
                    (2.1.1.2.2) Toggle bit.
                    (2.1.1.2.3) Get bit.
                    (2.1.1.2.4) Set bit (set to 1).




            (2.1.2) Boolean operations:    
                (2.1.2.1) Logical AND '&&'.
                (2.1.2.2) Logical OR '||'.
                (2.1.2.3) Logical NOT '!'.




            (2.1.3) Arithmetic operations:
                (2.1.3.1) Unary operators:
                    (2.1.3.1.1) Pre-incrementation '++i'.
                    (2.1.3.1.2) Pre-decrementation '--i'.
                    (2.1.3.1.3) post-incrementation 'i++'.
                    (2.1.3.1.4) post-decrementation 'i--'.

                (2.1.3.2) Binary operators:
                    (2.1.3.2.1) Addition '+':
                    (2.1.3.2.2) Subtraction '-':
                    (2.1.3.2.3) Multiplication '*':
                    (2.1.3.2.4) Division '/':
                    (2.1.3.2.5) Modulus '%':
            


            (2.1.4) Relational operators:
                (2.1.4.1) More than or equal '>='.
                (2.1.4.2) More than '>'.
                (2.1.4.3) equate to '=='.
                (2.1.4.4) Less than '<'.
                (2.1.4.5) Less than or equal '<='.
            

            (2.1.5) Assignment operators
                (2.1.5.1) Addition assigning '+='.
                (2.1.5.2) Subtraction assigning '-='.
                (2.1.5.3) Multiplication assigning '*='.
                (2.1.5.4) Division assigning '/='.
                (2.1.5.5) Modulus assigning '%='.
                (2.1.5.6) Bitwise AND assigning '&='.
                (2.1.5.7) Bitwise OR assigning '|='.
                (2.1.5.8) Bitwise XOR assigning '^='.
                (2.1.5.9) Left bit shift assigning '<<='.
                (2.1.5.10) Right bit shift assigning '>>='.
                (2.1.5.11) Assign '='.
        


        
        (2.2) Alogrithms:
            (2.2.1) Big O Notation:
                (2.2.1.1) Time Complexity.
                (2.2.1.2) Space Complexity.
                (2.2.1.3) Estimating Algorithm.
                (2.2.1.4) Algorithm designs implementation:
                    (2.2.1.4.1) Sorting algorithm:
                        (2.2.1.4.1.1) Bubble Sort O(n^2).
        


        (2.3) Data structures:
            (2.3.1) Types of data type:
                (2.3.1.1) Integer (int).
                (2.3.1.2) Float (float).
                (2.3.1.3) Character (char) (signed 8-bit integer).
                (2.3.1.4) Structures (struct).


            (2.3.2) Types of data storaging:
                (2.3.2.1) Single variable.
                (2.3.2.2) Array (multi-variables):
                    (2.3.2.2.1) Static allocated array.
                (2.3.2.3) Pointers.
            
            (2.3.3) Storage classes:
                (2.3.3.1) Automatic variables (auto keyword).
                (2.3.3.2) Static allocated variables (static keyword).
                (2.3.3.3) Externally allocated variables (extern keyword).
                (2.3.3.4) Register variables (register keyword).


        

        (2.4) Control flow:
            (2.4.1) Sequential control flow.
            (2.4.2) Iterative control flow.
                (2.4.2.1) for() loop keyword.
                (2.4.2.2) while() loop keyword.
                (2.4.2.3) do{}while() loop keyword.

            (2.4.3) Conditional control flow:
                (2.4.3.1) Conditional statements control flow:
                    (2.4.3.1.1) if() keyword.
                    (2.4.3.1.2) else if() keyword.
                    (2.4.3.1.3) else keyword.
                    
                (2.4.3.2) Switch-case control flow:
                    (2.4.3.2.1) Switch() keyword.

            (2.4.4) Jump and exception control flow.
                (2.4.4.1) Break.
                (2.4.4.2) Return.
                (2.4.4.3) continue.
        



        (2.5) Functions:
            (2.5.1) Function declaration vs. definition.
            (2.5.2) Parameter passing (input).
            (2.5.3) Return values (output).
            (2.5.3) Recursion:
                (2.5.3.1) Stack Overflow due recursion.
            
        (2.6) Modular Programming:
            (2.6.1) Header files ('.h' extension).
            (2.6.2) Source files ('.c'/'.cpp' extensions).
            (2.6.3) extern keyword.
        
```
