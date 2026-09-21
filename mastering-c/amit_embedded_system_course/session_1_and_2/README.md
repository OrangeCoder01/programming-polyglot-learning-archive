# Session (1) and (2):
Learned (mixed with personal research):
```
    (1) Session (1):
        (1.1) Introduction to Embedded Systems:
            (1.1.1) Computer system:

                It is a large-scale general purpose system that acquires:
                    (1) High resources.

                    (2) Big size.

                    (3) High cost.

                (1.1.1.1) Processor sytem:

                    It is the CPU short for "Central Processing Unit" that is
                    responsible performing different types of operations:

                    The CPU work on the "Instruction Cycle":
                    Fetch -> Decode -> Execute -> Store.

                    (1.1.1.1.1) CU short for "Control Unit":

                        It is the managerial section responsible for managing, fetching instructions,
                        order and control the flow of the data.

    
                    (1.1.1.1.2) ALU short for "Arithmetic Logic Unit":

                        It is the arithmetic calculator section responsible for perfoming:
                            - Mathematical calculations [" '+', '-', '*', and '/' "].
                            - Logical comparison [" '&&', '||', '!', and '^' "].
                            - Relational operators:[ " '>', '>=', '==', '<=', and '<' ].
                            - Bitwise manipulations: " ['&', '|', and '~' "].


                    (1.1.1.1.3) Registers:

                        It is the internal storage slots inside the CPU, storing data, and their address.

                        It is integrated with the CPU, it lacks enough space storage; but due to
                        its close location with the CPU, operations done through it are executed
                        in extreme fast speed.

                        The data stored in registers are volatile area, data are lost whenever system shot down or power off.
                    









                (1.1.1.2) Memory system:

                    It stores data, instructions and data address.

                    It is different from registers, as it is located outside the CPU,
                    it is the same as an extension with respect to CPU but still embedded in the device internal structure.

                    It has larger storage space than registers; but the data tranfer from the memory to the CPU operation area costs time due to transit latency.

                    Memory system has three sections:

                    (1.1.1.2.1) Primary memory (Main memory/ RAM):

                        The RAM memory short for "Random Access Memory" is a volatile worksapce;
                        due data can be easily lost when the system shut down or powered off, same as
                        register's.
                    

                    (1.1.1.2.2) Cache memory:

                        It is a buffer data storage between the CPU (operational area) and
                        the RAM (Large-sized data storage area) which is built; to resolve the
                        latency of data transition between RAM and CPU.

                        It stores frequently used code data.
                    

                    (1.1.1.2.3) Secondary storage:

                        It is not volatile as the RAM or registers but the data stored inside is permenantly saved regardless of
                        system shut down ot power off.

                        It could be native to the device internal structure by using "Solid State Drive" long for "SSD"
                        or "Hard Disk Drive" long for "HDD".
                        It could also be non-native such as USB drive.







                (1.1.3) The Input/Output (I/O) system:

                    Input is the unit that is externally received and output is the result after an operation.

                    In computer system, the input must be an external signal caught from the external actions that
                    can be translated into readable instructions to the CPU (Binary numerial) such as: Mouse click or keyboard key button click.

                    The output could then be differnt form such as: music display, opening website page or running a program.








            (1.1.2) Microcontroller system:

                It is a small-scale specific purpose system that acquires:
                    (1) Low resources.

                    (2) Small Size.

                    (3) Low cost.




                (1.1.2.1) Processor system:
                        (1.1.2.1.1) Control Unit (CU).

                        (1.1.2.1.2) Arithmetic Logic Unit (ALU).

                        (1.1.2.1.3) Registers.
    
                

                (1.1.2.2) Memory system:
                    (1.1.2.2.1) RAM.


                    (1.1.2.2.2) Program memory ( Internal Flash / ROM ( Read only memory ) ):

                        It holds the compiled code and its stored data is non-volatile, equivalent representation for "Secondary storage" in computer system. ROM is only written once by manufacturers and can not be edited by
                        the developer. While Flash can erased and be rewritten, it is large in size and stores infrequently
                        written data.



                    (1.1.2.2.3) EEPROM (Electrically Erasable Programmable ROM).

                        It holds data about setting, IDs or device's data. Unlike Internal Flash: it is small in size and
                        stores data that is frequently written.



                    
                (1.1.2.3) Input/Output (I/O) and Peripheral System:

                    GPIO stands for "General purpose Input/Output": these are protruding pins that can receive electrical
                    signal from sensors or send ones to actuators.








        (1.2) Introduction to C programming language:
            (1.2.1) History of C programminf language:

                1960 -> ALGOL programming language (Father of all programming langauges).

                1967 -> BCPL programming language (Basic combined system programming language).

                1970 -> B programming language by (Unix System) from (Bell Labs) (It is said it is the first letter from "BCPL" or probably from "Bell labs").

                1972 -> C programming language by (Dennis Ritchie) (C is the next letter after B due to its reference of its advancement).

                C is combination of ALGOL, BCPL, B, and many added features in one.



            (1.2.2) Official C versions and standards:

                (C89/90), (C95), (C99), (C11), (C17/18), (C23).
            


            (1.2.3) Applications of C programming language:
                - Widely used in Embedded System.

                - System application.

                - Operating System (OS) such as (Linux, Windows, and MAC)

                - Database (MySQL)



            (1.2.4) Core Toolchain architecture:
                (1.2.4.1) What is Toolchain:

                    It is a block of softwares that one receives the previous blocks output as its input and
                    process the input to produce an output that the next software will use as input.

                    Thus the name "Toolchain" is about chain of tool softwares that cooperate with each other and
                    the final output is presented to the user.


                (1.2.4.2) Compilation Toolchain

                    In programming language, there is a toolchain called "Compilation Toolchain":

                        It is the responsible for converting programming language text into machine-readable code that can be compiled.
                        Vice-versa with showcasing/displaying the result/output.
                        
                    It is composed of 4 core softwares:
                        - Preprocessor.

                        - Compiler.

                        - Assembler.

                        - Linker.




                                                                                                                           




        (1.3) Perplexing details:
            (1.3.1) UNIX:

                It is the foundational operating system which established the standards of the modern computing enviroments.

            (1.3.2) GNU:

                It is an open source (free) project used that focuses in producing efficient software toolchain GCC and debuggers GDB. 
                It is not founded by UNIX, and GNU stands for "GNU not UNIX" (Recursive acronym).

            (1.3.3) GCC:
                
                It stands for "GNU Compiler Collection"; it is a compilation engine.
            
            (1.3.4) MinGW:

                It stands for "Minimalist GNU for windows"; software combining GNU and GCC.









        (1.4) Why is the following important:
            (1.4.1) Why learn Embedded System:
                - Deep Understanding of Computing; understanding small electronics chips' utilities, features
                  and labels in small-scale system as the Microcontroller aids well in designing and implementing
                  real cascaded small-scale systems that get finished as large-scale system as more powerful such as
                  "Microprocessor", then "Computer System". 

                It aids in understanding the standard electronics internal composition architecture.

                - Optimization; one of the most important skill from developers in general is code optimization,
                  but for embedded system engineer; optimization expands toward limiting opertations for best
                  performance; due to lack of storage space.

                - Ability to develop robotics and automation.
            
            (1.4.2) Why C programming language:
                - It is modular and structured programming language that focuses in enhancing developers skills in compromising 
                  large problem into manageable pieces.

                - Simplicity and difficulty; there are 32 keywords with no built-in functions; it directs the developer to create
                  modules and solve problem, and understand binary mathematics all from scratch.
                  It hands the developer all the responsibilities such as memory management without any backup.

                - Fast runtime; due to its simplicity, which makes it demanded in Embedded system.






    (2) Session (2):

        MinGW is a compilation toochain for windows which contains the basic four softwares: Compiler, Assembler, Linker, and Preprocessor.

        What is learned from this session:
        - basic terminal command given to the toolchain to perform certian tasks
          such as generating executable file and running the executable file.

        - Code portability from different types of standards such as using "/* */" for commenting instead of
          "//" due to some C standards does not recognize such feature.
        
        - Basic Syntax such as semi-colon ";" such as in int x = 10;.

        - Function call with parenthesis "()" such as in printf("Hello World!");

        - Key difference between strings and characters as one string is composed of stream of characters,
          parsed in double quotation mark ""String"".
          While characters is a singular ASCII-value that has distinct physical shape, parsed in single quotation
          "'c'".
        
        - Library importing.


        (2.1) Important labels:
            (2.1.1) Text Editor:
                It is the software on which the developer write the code on, each text editor has
                helpful features that helps the developer to write code efficiently such as highlighting
                a variable's name across the whole code.

                The used text editor is "vscode" short for "Visual Studio code".

            (2.1.2) Files:
                (2.1.2.1) Code files:

                    This is the file where code is written on: it has the extension of ".c" at the end of the name, to indicate
                    it contains 'C' programmable code.

                (2.1.2.2) Executable file:

                    This is the resultant file from compiling the code file into an "executable" file with ".exe" extension on the file's name.

                    The program runs from executing this file. The executable file is not readable for humans as it only include machine code.


        (2.2) Terminal Commands:

            The terminal is responible for giving command to the compiler directly.

            Note: To check the correct terminal for the code file, open "integrated terminal environments" to open the termninal in correspondence to the target file's directory of folders.

            Name a file with the name "work_1.c" as an example to be used in the subsections.

            (2.2.1) Compiling a code file:

                " gcc work_1.c " 
                
                It creates an executable file "a.exe" where "a" is the default executable file name.
                Or you could compile the code file with different executable file name instead of default "a":

                " gcc code_1_c.c -o code_2_c.c "

            (2.2.2) Renaming a file:

                    " Rename-Item a.exe code_1_c.exe "
                    
                    Or write any name you would like instead of "code_1_c.exe"
                

            (2.2.3) Runing a code file:

                " .\a.exe "
                Where a.exe is the found executable file found.



        
        (2.3) Comments in C:

            Comments can be written with "//" or "/**/" whereas the compiler ignore when compiling the 
            code file into executable file, thus labeled as "non-code block".

            It is used to give insight about the code, for giving other developers or reviewers
            understanding what is the purpose for a code piece.

            But "//" is a single line code comment, meaing it comments from line
            meanwhile "/**/" comments what is parsed between "/*" and "*/" symbols.

            "/**/" is the recognizable by C standards while "//" is not, thus using "//" will cause
            code portability issue.


        (2.4) Printf() function from <stdio.h> and some details about it:
            (2.4.1) How to use printf():
                
                printf() function receives text string input parsed by " " to print the text in the
                terminal. 
                For example:

                    printf("Hello World!");
                    will result into:

                        Hello World!


            (2.4.2) Data type input:
                
                The "data type space" left for inserting the value of a variable such as:

                    int num_pencils = 100;
                    int num_students = 20;
                    int num_teachers = 1;'
                    printf("There are %d pencils, %d students and %d teacher.", num_pencils, num_students, num_teachers);

                    which outputs in terminal:

                        There are 100 pencils, 20 students and 1 teacher.

            (2.4.3) Escape sequence:

                The escape sequence is a set of instruction given inside the string text in printf().
                It is composed of backslash and one of the symbols of sets.

                - '\n': New line.
                - '\t': Horizontal tab.
                - '\\': insert blackslash safely.
                for example:

                    printf("5\4 is equal to 1.25") will output: 5 is equal to 1.25 (unexpected output).
                    printf("5\\4 is equal to 1.25") will output: 5\4 is equal to 1.25.
                
                -'\'': insert single quotation safely.
                for example:

                    printf("Jamjon\'s bone"); outputing: Jamjon's bone.
                
                -'\"': insert double quotation safely:
                for example:

                    printf("\"Fortune favors the bold\"."); outputting: "Fortune favors the bold".
        
        (2.5) Variables:
            (2.5.1) Types of primitive/basic data types:
                (2.5.1.1) Decimal values:
                    (2.5.1.1.1) "int" (integer).

                        It holds 4 bytes which is 32 bits where a byte is 8 bits.
                        the max value it can hold: 2^32 = 4,294,967,296, but it is signed;
                        meaning it is distributed across the negative and positive timeline:
                        ranging between: -2,147,483,648 to 2,147,483,647.

                    (2.5.1.1.2) "char" (character) (ASCII integer).
                        
                        It is signed 8-bit (1-byte) integer whereas each value represent a character in ASCII table.
                        The signed version is a constraints of the C programming language; ASCII letters are not represented by negative decimals
                        but by positive ones.

                        It ranges between -128 to 127. A range of 256 or (2^8).


                (2.5.1.2) Floating value (integer + fraction):
                    (2.5.1.2.1) "float".
                        It contains 4 bytes (32 bits).

                    (2.5.1.2.2) "double".
                        It contains 8 bytes (64 bits).

            (2.5.2) Declaration/definition:
                Declaration takes place by introducing the type of the data type, name of the variable, and adding initializing value is an option:

                    int x = 10;
                    float z;
                    char y = 'a';
                    char k = 35; (which is '#').
                    double m = -2.0;

            (2.5.3) Data type name:
                (2.5.3.1) Rules for naming basic datatype variables:

                    - can contain capital letters.

                    - Can contain small case letters.

                    - First letter must be an alphabet.

                    - Must not have the same of one of the reserved keywords such as "return".

                    - Variable naming is case sensitive: declaring variable as 'x' and calling 'X' will have unexpected
                      consequences.

                    - No length limit.

                    - Can not declare two identically-named variable inside the same scope (Check Local and Global scopes).

                    - Must not use space " " for word separation, but can use underscore "_" instead.





        (2.6) Why learn:
            (2.6.1) Important name labels:

                Recognizing softwares is first and the most crucial step for comprehending their functionality in the middle 
                of many softwares that have overlapping utilities will benefit in having a profound background knowledge in
                the software technicalities.

            (2.6.2) Terminal commands:

                Despite presence of premade extension that can handle the commands by a click of a bottom,
                it is very educative to interact with the compiler by pushing commands, whereas one gets to know
                the command keywords.

            (2.6.3) Commenting:

                It is crucial for code clarifications for other technical reviewers.

            (2.6.4) printf() function:

                Important function for printing on the user's terminal.

            (2.6.5) Concepts related to variables:

                Understanding how the compiler stores the variables by storing a specific
                data type and its value as a set of stream of binary data.
```