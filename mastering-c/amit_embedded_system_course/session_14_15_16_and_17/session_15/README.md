# Session (15): Embedded System Architecture & Memory Concepts

Learned (mixed with personal research):

Note:
````
    This session zooms out from C programming syntax to look at the physical silicon hardware 
    that actually executes the code. It maps out the anatomy of an Embedded System, the internal 
    workings of the CPU (Fetch-Decode-Execute cycle), architectural philosophies (RISC vs. CISC), 
    and the fundamental physics of how bits are stored in Memory.
````

${\color{red}\text{VERY IMPORTANT NOTE: (1)}}$
````
    What makes an "Embedded System" different from a standard "Computer"?
    A standard Computer is a general-purpose machine designed to handle an infinite variety of tasks.
    An Embedded System contains the exact same three core pillars (Processor, Storage/Memory, I/O) 
    but is strictly engineered for a SPECIFIC purpose at a lower scale and cost.
````

<br>

&emsp; ${\color{red}\text{(1)}}$: **Embedded System Implementation**
<br>

&emsp;&emsp; ${\color{blue}\text{(1.1)}}$: **System on Board (SOB) vs. System on Chip (SOC)**  
````
            Embedded hardware can be physically manufactured in two primary ways:
            
            1. System on Board (SOB): Components (Processor, Memory, ADC, UART) are separate discrete 
               IC chips soldered onto a single Printed Circuit Board (PCB).
            
            2. System on Chip (SOC): All modules (Processor, Memory, Peripherals) are miniaturized 
               and fabricated inside a SINGLE Integrated Circuit (IC) package.
               Example: Microchip ATmega328 (The brain of the Arduino Uno).
````

| Parameter | System on Board (SOB) | System on Chip (SOC) |
| :--- | :--- | :--- |
| **Performance** | Standard | Standard (comparable) |
| **Cost** | Higher $\uparrow$ | **Lower** $\downarrow$ (Better) |
| **Physical Size** | Larger $\uparrow$ | **Smaller** $\downarrow$ (Better) |
| **Power Consumption**| Higher $\uparrow$ | **Lower** $\downarrow$ (Better) |
| **Configuration/Flexibility**| **Better** (Can swap parts easily) | Worse (Hardwired at the factory) |

<br>

&emsp; ${\color{red}\text{(2)}}$: **How the Processor Works (CPU Architecture)**
<br>

&emsp;&emsp; ${\color{blue}\text{(2.1)}}$: **The Fetch-Decode-Execute Cycle**  
````
            The Control Unit (CU) of the CPU is responsible for orchestrating a continuous 3-step loop:
            
            1. FETCH: Retrieve the next instruction from Memory.
            2. DECODE: Understand the instruction (translate Opcode/Operand).
            3. EXECUTE: Implement the logic via the Arithmetic Logic Unit (ALU).
````

```
            Internal CPU Architecture Map:

            +-------------------------------------------------------------+
            |                             CPU                             |
            |                                                             |
            |  +----+      +----+      +----+      +-----+                |
            |  | PC | ---> | IR | ---> | ID | ---> | ALU | <---> GPRS     |
            |  +----+      +----+      +----+      +-----+ (General Regs) |
            |    |           ^                       |                    |
            |    v           |                       v                    |
            |  [ Address Bus ]                 [ ACC / PSW ]              |
            +-------------------------------------------------------------+
                 |           ^
                 v           | [ Data Bus ]
            +----------------------------------+
            |          Memory (RAM/ROM)        |
            +----------------------------------+
```

&emsp;&emsp; ${\color{blue}\text{(2.2)}}$: **Core CPU Registers** <br>
````
            - PC (Program Counter): Holds the memory ADDRESS of the NEXT instruction to be fetched.
            - IR (Instruction Register): Holds the actual INSTRUCTION just fetched from memory.
            - ID (Instruction Decoder): Translates the raw binary into hardware control signals.
            - ACC (Accumulator): Stores the direct mathematical result from the ALU.
            - GPRS (General Purpose Registers): Fast on-chip storage for variables and data.
            - PSW (Processor Status Word): A flag register updated by the ALU after operations.
              > Z-Flag (Zero): Set if result is 0.
              > N-Flag (Negative): Set if result is less than 0.
              > OV-Flag (Overflow): Set if result exceeds register bit-capacity.
````

<br>

&emsp; ${\color{red}\text{(3)}}$: **Instruction Set Architecture (ISA): RISC vs CISC**
<br>

${\color{red}\text{VERY IMPORTANT NOTE: (2)}}$
````
    If we want the CPU to execute `int x = z * y;`, there are two completely different architectural 
    philosophies on how to build the silicon to achieve this: RISC and CISC.

    This dictates who does the heavy lifting: The Compiler (Software) or the CPU (Hardware)?
````

&emsp;&emsp; ${\color{blue}\text{(3.1)}}$: **RISC (Reduced Instruction Set Computing)** <br>
````
            - Philosophy: Keep the hardware simple. 
            - Instruction Set: Small number of basic instructions (~100-200).
            - Logic Design: Instructions are "Hardwired" directly into logic gates (Fast).
            - Burden: The Compiler must work harder to break complex C code (like a multiply) into 
              many simple assembly instructions (e.g., looping ADD instructions).
            - Major Vendor: ARM (Used in almost all mobile phones and embedded microcontrollers).
````

&emsp;&emsp; ${\color{blue}\text{(3.2)}}$: **CISC (Complex Instruction Set Computing)** <br>
````
            - Philosophy: Keep the software/compiler simple.
            - Instruction Set: Massive library of complex instructions (~1000-5000).
            - Logic Design: Relies on "Microprograms" inside the CPU to execute complex multi-step 
              instructions (Slower per instruction, but does more work).
            - Burden: The CPU silicon is massive and complex. The compiler's job is easy.
            - Major Vendor: Intel / AMD (Used in desktop PCs and servers).
````

| Parameter | RISC (Embedded / ARM) | CISC (PCs / Intel) |
| :--- | :--- | :--- |
| **Instruction Decoder (ID)** | Hardwired Logic (Fast) | Microprogrammed (Complex) |
| **Compiler Complexity** | High $\uparrow$ (Must optimize heavily) | Low $\downarrow$ |
| **Hardware Complexity** | Low $\downarrow$ | High $\uparrow$ |
| **Power Consumption** | **Low** (Ideal for battery devices) | High |

<br>

&emsp; ${\color{red}\text{(4)}}$: **Memory Technologies**
<br>

&emsp;&emsp; ${\color{blue}\text{(4.1)}}$: **Volatile Memory (RAM)** <br>
````
            Volatile memory loses all data when power is removed.
            There are two fundamental ways to build RAM bits:
            
            1. DRAM (Dynamic RAM): Uses a Capacitor.
               - Mechanics: Capacitor charges (1) or discharges (0).
               - Flaw: Capacitors leak charge and must be constantly "refreshed" by the CPU.
               - Use: Main memory in Desktop PCs (Gigabytes).
               
            2. SRAM (Static RAM): Uses Transistors (Flip-Flops).
               - Mechanics: Transistors act as open/short circuits. No refreshing needed.
               - Advantage: Extremely fast.
               - Flaw: Takes up massive physical space on the silicon.
               - Use: Embedded Systems RAM and CPU Cache (Kilobytes to Megabytes).
````

| Characteristic | DRAM (Capacitor-Based) | SRAM (Transistor-Based) |
| :--- | :--- | :--- |
| **Speed / Performance** | Slower $\downarrow$ (~ms) | **Faster** $\uparrow$ (~ns) |
| **Density (Capacity)** | High $\uparrow$ (GBs) | Low $\downarrow$ (KBs) |
| **Cost per Bit** | Cheap $\downarrow$ | Expensive $\uparrow$ |
| **Embedded System Usage** | Rare | **Primary RAM** |

<br>

&emsp;&emsp; ${\color{blue}\text{(4.2)}}$: **Non-Volatile Memory (ROM / Flash)** <br>
````
            Non-volatile memory retains data even when power is disconnected.
            Modern embedded Flash memory uses "Floating Gate MOSFETs".

            Physics of a Floating Gate Transistor:
            Standard transistors have a Source, Drain, and Gate.
            A Floating Gate MOSFET adds a completely isolated "Floating Gate" surrounded by oxide insulation.
            
            - Writing (1/0): A massive voltage spike (${\Delta}$V) forces electrons to tunnel through 
              the oxide and become permanently trapped in the Floating Gate.
            - Erasing: A massive reverse voltage forces them out.
            - Reading: Normal low-voltage checks if electrons are blocking the current path.
````

```
            Floating Gate MOSFET Architecture (Flash Memory):

                     [ High Voltage to Write/Erase ]
                              +----------+
                              |   Gate   |
                              +----------+
            +-----------------| Insulator|-----------------+
            |                 +----------+                 |
            |     +----------------------------------+     |
            |     |        FLOATING GATE             |     | <-- Traps Electrons
            |     |   (Isolated by Oxide layer)      |     |
            |     +----------------------------------+     |
            |   N-Type                           N-Type    |
            | +--------+                       +--------+  |
            | | Source |         P-Type        | Drain  |  |
            | |        |      (Substrate)      |        |  |
            +-+--------+-----------------------+--------+--+
```
<br>

${\color{red}\text{VERY IMPORTANT NOTE: (3)}}$
````
    Flash Memory Quirks:
    1. It requires very High Power to Write or Erase data (forcing electrons through oxide).
    2. It requires very Low Power to Read data.
    3. Flash memory degrades over time. Because high voltage physically damages the oxide 
       layer, Flash memory has a limited lifespan (e.g., 10,000 to 100,000 Write/Erase cycles) 
       before the bit "dies" and can no longer trap electrons.
````