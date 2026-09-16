# Session (1) and (2):
Learned (mixed with personal research):
```
    (1) Introduction to Embedded Systems:
        (1.1) Computer system:

            It is a large-scale general purpose system that acquires:
                 (1) High resources.

                 (2) Big size.

                 (3) High cost.

            (1.1.1) Processor sytem:

                It is the CPU short for "Central Processing Unit" that is
                responsible performing different types of operations:

                The CPU work on the "Instruction Cycle":
                Fetch -> Decode -> Execute -> Store.

                (1.1.1.1) CU short for "Control Unit":

                    It is the managerial section responsible for managing, fetching instructions,
                    order and control the flow of the data.

  
                (1.1.1.2) ALU short for "Arithmetic Logic Unit":

                    It is the arithmetic calculator section responsible for perfoming:
                        - Mathematical calculations [" '+', '-', '*', and '/' "].
                        - Logical comparison [" '&&', '||', '!', and '^' "].
                        - Relational operators:[ " '>', '>=', '==', '<=', and '<' ].
                        - Bitwise manipulations: " ['&', '|', and '~' "].


                (1.1.1.3) Registers:

                    It is the internal storage slots inside the CPU, storing data, and their address.

                    It is integrated with the CPU, it lacks enough space storage; but due to
                    its close location with the CPU, operations done through it are executed
                    in extreme fast speed.

                    The data stored in registers are volatile area, data are lost whenever system shot down or power off.
                





            (1.1.2) Memory system:

                It stores data, instructions and data address.

                It is different from registers, as it is located outside the CPU,
                it is the same as an extension with respect to CPU but still embedded in the device internal structure.

                It has larger storage space than registers; but the data tranfer from the memory to the CPU operation area costs time due to transit latency.

                Memory system has three sections:

                (1.1.2.1) Primary memory (Main memory/ RAM):

                    The RAM memory short for "Random Access Memory" is a volatile worksapce;
                    due data can be easily lost when the system shut down or powered off, same as
                    register's.
                

                (1.1.2.2) Cache memory:

                    It is a buffer data storage between the CPU (operational area) and
                    the RAM (Large-sized data storage area) which is built; to resolve the
                    latency of data transition between RAM and CPU.

                    It stores frequently used code data.
                

                (1.1.2.3) Secondary storage:

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






        (1.2) Microcontroller system:

            It is a small-scale specific purpose system that acquires:
                (1) Low resources.

                (2) Small Size.

                (3) Low cost.

            (1.2.1) Processor system:
                    (1.2.1.1) Control Unit (CU).
                    (1.2.1.1) Arithmetic Logic Unit (ALU).
                    (1.2.1.1) Registers.
            
            (1.2.2) Memory system:
                (1.2.2.1) RAM.
                (1.2.2.2) Program memory ( Internal Flash / ROM ( Read only memory ) ):

                    It holds the compiled code and its stored data is non-volatile, equivalent representation for "Secondary storage" in computer system.

                (1.2.2.3) EEPROM (Electrically Erasable Programmable ROM).

                    It holds data about setting, IDs or device's data.
                
            (1.2.3) Input/Output (I/O) and Peripheral System:

                GPIO stands for "General purpose Input/Output": these are protruding pins that can receive electrical
                signal from sensors or send ones to actuators.








    (2) Introduction to C programming language:
        (2.1) History of C programminf language:

            1960 -> ALGOL programming language (Father of all programming langauges).

            1967 -> BCPL programming language (Basic combined system programming language).

            1970 -> B programming language by (Unix System) from (Bell Labs) (It is said it is the first letter from "BCPL" or probably from "Bell labs").

            1972 -> C programming language by (Dennis Ritchie) (C is the next letter after B due to its reference of its advancement).

            C is combination of ALGOL, BCPL, B, and many added features in one.



        (2.2) Official C versions and standards:

            (C89/90), (C95), (C99), (C11), (C17/18), (C23).
        


        (2.3) Applications of C programming language:
            - Widely used in Embedded System.

            - System application.

            - Operating System (OS) such as (Linux, Windows, and MAC)

            - Database (MySQL)



        (2.4) Core Toolchain architecture:
            (2.4.1) What is Toolchain:

                It is a block of softwares that one receives the previous blocks output as its input and
                process the input to produce an output that the next software will use as input.

                Thus the name "Toolchain" is about chain of tool softwares that cooperate with each other and
                the final output is presented to the user.


            (2.4.2) Compilation Toolchain

                In programming language, there is a toolchain called "Compilation Toolchain":

                    It is the responsible for converting programming language text into machine-readable code that can be compiled.
                    Vice-versa with showcasing/displaying the result/output.
                    
                It is composed of 4 core softwares:
                    - Preprocessor.

                    - Compiler.

                    - Assembler.

                    - Linker.





    


    (3) Perplexing details:
        (3.1) UNIX:

            It is the foundational operating system which established the standards of the modern computing enviroments.

        (3.2) GNU:

            It is an open source (free) project used that focuses in producing efficient software toolchain GCC and debuggers GDB. 
            It is not founded by UNIX, and GNU stands for "GNU not UNIX" (Recursive acronym).

        (3.3) GCC:
            
            It stands for "GNU Compiler Collection"; it is a compilation engine.
        
        (3.4) MinGW:

            It stands for "Minimalist GNU for windows"; software combining GNU and GCC.






    (4) Why section:
        (4.1) Why learn Embedded System:
            - Deep Understanding of Computing; understanding small electronics chips' utilities, features
              and labels in small-scale system as the Microcontroller aids well in designing and implementing
              real cascaded small-scale systems that get finished as large-scale system as more powerful such as
              "Microprocessor", then "Computer System". It aids in understandinf the standard electronics internal
              composition architecture.

            - Optimization; one of the most important skill from developers in general is code optimization,
              but for embedded system engineer; optimization expands toward limiting opertations for best
              performance; due to lack of storage space.

            - Ability to develop robotics and automation.
        
        (4.2) Why C programming language:
            - It is modular and structured programming language that focuses in enhancing developers skills in compromising 
              large problem into manageable pieces.

            - Simplicity and difficulty; there are 32 keywords with no built-in functions; it directs the developer to create
              modules and solve problem, and understanding binary mathematics all from scratch.
              It hands the developer all the responsibilities such as memory management without any backup.

            - Fast runtime; due to its simplicity, which makes it demanded in Embedded system.

```