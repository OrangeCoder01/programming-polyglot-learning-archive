# Session (1) and (2):
Learned (mixed with personal research):
```
    (1) Introduction to Embedded Systems:
        (1.1) Computer system:

            It is a large scale general purpose system that acquires:
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








        (1.2) Microcontroller:

            (1.2.1) Processor system:







            (1.2.2) Memory system:








            (1.2.3) Input/Output (I/O) system:








```

    (1) Type Specifier:
        (1.1) int
        (1.2) char
        (1.3) float

    (2) <stdio.h> library