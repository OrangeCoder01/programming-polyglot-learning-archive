# Session (16): Embedded Memories, System Buses & CPU Architecture

Learned (mixed with personal research):

Note:
````
    This session transitions from software into pure digital hardware design, exploring the physical 
    silicon structures that store code (ROM/Flash/EEPROM), how the CPU physically communicates with them 
    using System Buses, and the foundational paradigms of CPU Architecture (Von Neumann vs. Harvard).
````

${\color{red}\text{VERY IMPORTANT NOTE: (1)}}$
````
    The distinction between Flash and EEPROM is often misunderstood. Both are non-volatile and electrically 
    erasable, but their architectural access methods dictate their use cases in embedded systems.

    Flash is erased in bulk blocks/pages. Because it handles large chunks of data efficiently, 
    it is cheap, compact, and ideal for storing the main Program Code (.text section).

    EEPROM allows true Byte-level access. If you need to update a single 8-bit variable (like a 
    saved user setting), EEPROM can erase and rewrite just that byte without touching the rest of the memory. 
    However, this granularity makes it expensive and bulky, so it is strictly used for Non-Volatile Data.

    Modern microcontrollers often use a Software mechanism called FEE (Flash EEPROM Emulator) to simulate 
    EEPROM behavior inside standard Flash memory to save hardware costs.
````

&emsp; ${\color{red}\text{(1)}}$: **Embedded System Memories**
<br>

&emsp;&emsp; ${\color{blue}\text{(1.1)}}$: **Types of ROM (Read-Only Memory)**  
````
            1. Masked ROM: Programmed once during physical manufacturing; lowest cost for mass production.
            2. OTP (One-Time Programmable): Can be burned by the user exactly once.
            3. EPROM: Erasable via UV light.
            4. EEPROM: Electrically Erasable Programmable ROM (Byte-level access).
            5. Flash: The modern standard; Electrically Erasable but operates via Block/Page access.
````

&emsp;&emsp; **Flash vs. EEPROM Hardware Comparison:**

| Feature | Flash Memory | EEPROM |
| :--- | :--- | :--- |
| **Access Method** | Erased by Block / Page | Erased by individual Byte |
| **Primary Use Case** | Program Memory (Stores compiled code) | Data Memory (Stores dynamic settings) |
| **Cost & Size** | Lower cost $\downarrow$, smaller silicon footprint | Higher cost $\uparrow$, larger silicon footprint |
| **Write Endurance** | ~10,000 Write/Erase Cycles | ~1,000,000 Write/Erase Cycles |
| **Write Speed (1 Byte)** | Slower (~100 msec due to block handling) | **Faster** (~10 msec) |

<br>

&emsp;&emsp; ${\color{blue}\text{(1.2)}}$: **NVRAM (Non-Volatile RAM)**  
````
            SRAM is extremely fast but loses data when power drops. NVRAM solves this using two methods:
            
            1. Hardware Approach (RTCs/Watches/Laptops): 
               Attach a physical battery directly to the SRAM chip. 
               Disadvantage: Extra size, added cost, and limited durability.
               
            2. Software Approach (Brown-out Emulation): 
               Use a Brown-out detector circuit and a capacitor on the power line. 
               When power drops, an interrupt triggers. The CPU uses the remaining capacitor juice 
               to rapidly copy critical SRAM data into Flash memory before the system completely dies.
````

<br>

&emsp; ${\color{red}\text{(2)}}$: **System Buses & Address Mapping**
<br>

&emsp;&emsp; ${\color{blue}\text{(2.1)}}$: **The Three CPU Buses**  
````
            The CPU communicates with memory and peripherals using unified groups of wires called Buses.

            1. Address Bus: Dictates how many distinct memory locations the CPU can talk to.
               Equation: Max Locations = $2^{Address Bus Size}$.
               Example: An 8-bit Address Bus yields $2^8 = 256$ unique locations.

            2. Data Bus: Dictates how much data can be transferred in a single clock cycle (Word Size).
               Example: An 8-bit Data Bus transfers 1 Byte at a time, meaning values range from 0-255.

            3. Control Bus: Sends command signals (e.g., Read, Write, Enable).
````

&emsp;&emsp; ${\color{blue}\text{(2.2)}}$: **Memory Layout & Mapping Rules**  
````
            When allocating the CPU's total Address Space among physical chips (Flash, SRAM, EEPROM), 
            hardware engineers follow two strict design principles:
               1. Homogeneity: Memory types are grouped continuously in contiguous blocks.
               2. No Fragmentation: No empty address gaps within a specific memory block's allocation.
````

```
            Example Architecture Mapping:
            Processor: 8-bit Address Bus (256 Total Locations available).
            Hardware Attached: 128B Flash, 64B SRAM, 32B EEPROM (Total 224B used).

               Address Space (0 to 255)
            +---------------------------+ 0
            |                           |
            |       Flash Memory        |
            |        (128 Bytes)        |
            |                           |
            +---------------------------+ 127
            |                           |
            |       SRAM Memory         |
            |        (64 Bytes)         |
            +---------------------------+ 191
            |                           |
            |       EEPROM Memory       |
            |        (32 Bytes)         |
            +---------------------------+ 223
            |       Reserved Area       |
            |        (32 Bytes)         |
            +---------------------------+ 255
```

<br>

${\color{red}\text{VERY IMPORTANT NOTE: (2)}}$
````
    The fundamental bottleneck of early computing was the Von Neumann Architecture. 
    
    Because both Code (instructions) and Data (variables) share the exact same physical memory space 
    and the exact same Data/Address buses, the CPU can only do one thing at a time.

    It must Fetch an instruction, then Decode it, then Fetch the data for that instruction.

    Harvard Architecture solves this by physically splitting the memory chips and bus lines.
    The CPU has an independent Address/Data bus routed to Flash, and a separate Address/Data bus routed to SRAM.

    This allows the CPU to fetch the NEXT instruction from Flash while simultaneously reading/writing DATA 
    to SRAM for the CURRENT instruction—a massive performance boost known as Pipelining.
````

<br>

&emsp; ${\color{red}\text{(3)}}$: **Digital Architecture Models**
<br>

| Feature | Von Neumann Architecture | Harvard Architecture |
| :--- | :--- | :--- |
| **Bus/Memory Structure** | Single shared memory space & shared buses | Independent, separate memories & buses for Code vs Data |
| **Execution Flow** | Strictly sequential (Fetch $\rightarrow$ Decode $\rightarrow$ Execute) | Overlapping via **Pipelining** |
| **Performance** | Slower throughput $\downarrow$ | Faster execution $\uparrow$, higher MIPS (Millions of Instructions Per Second) |
| **Hardware Complexity** | Cheaper, smaller silicon footprint | Extra hardware (size and cost $\uparrow$), complex CPU logic |

<br>

&emsp;&emsp; ${\color{blue}\text{(3.1)}}$: **AVR ATmega32 Specific Architecture**  
````
            The ATmega32 microcontroller utilizes a Modified Harvard Architecture.
            - It maintains physically separate Flash (Program) and SRAM (Data) blocks on separate buses.

            - However, it utilizes Memory-Mapped I/O, meaning its peripheral hardware registers (I/O) 
              share the exact same unified address space as the SRAM.
````

```
               AVR ATmega32 Hardware Layout:
               
            [ Flash (Program) ]      [ Processor ]      [ SRAM + I/O ]
            +-----------------+      +-----------+      +------------+
            |                 | <==> |           | <==> |    SRAM    |
            |   Instructions  |      |    CPU    |      |            |
            |                 |      |           |      +------------+
            +-----------------+      +-----------+ <==> | I/O Memory |
               (Bus A)                                  +------------+
                                                           (Bus B)
```

<br>

&emsp; ${\color{red}\text{(4)}}$ **Why Learn**: <br>

&emsp;&emsp; ${\color{blue}\text{(4.1)}}$ **Hardware-Aware Firmware**: <br>
````
            - Memory Optimization: Understanding the physical erase constraints of Flash vs EEPROM explains 
              why saving a single 1-byte user setting to Flash requires loading an entire page into RAM, 
              modifying it, and flashing the whole block—justifying the need for FEE.

            - Performance Bottlenecks: Knowing whether your target MCU is Von Neumann or Harvard dictates 
              how you structure time-critical interrupt routines and instruction pipelining.
````