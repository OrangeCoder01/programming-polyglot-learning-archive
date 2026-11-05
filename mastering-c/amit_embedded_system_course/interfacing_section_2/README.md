# AVR COTS Driver

This folder contains the AVR driver-based project used for the AMIT embedded systems course. The project is structured around a layered driver model:

- `LIB` for reusable helpers and types
- `MCAL` for microcontroller abstraction layers
- `HAL` for hardware device drivers
- `APP` for application logic
- `main.c` as the entry point

This project is intended to be used as a standalone VS Code workspace, not from the repository root.

## Requirements

Before building or flashing the AVR project, install the following tools on your machine.

### 1) AVR GCC toolchain
Install the AVR C/C++ compiler and binutils:

```powershell
winget install --id ZakKemble.avr-gcc --accept-source-agreements --accept-package-agreements --silent
```

This provides tools such as:

- `avr-g++`
- `avr-objcopy`
- `avr-size`

### 2) AVRDUDE
Install the uploader/programmer tool:

```powershell
winget install --id AVRDudes.AVRDUDE --accept-source-agreements --accept-package-agreements --silent
```

This is required to flash the compiled firmware to the AVR board.

### 3) Hardware requirements
- ATmega32 microcontroller board
- 8 MHz clock configuration
- Arduino-compatible programmer / serial upload connection
- USB cable and correct COM port connection

### 4) VS Code setup
Use VS Code with the project opened directly at:

```text
mastering-c/amit_embedded_system_course/interfacing_section_2/avrcots
```

Do not open the repository root and expect the AVR toolchain to work correctly. The project has local settings in `.vscode/settings.json` that are tuned for this folder.

## Required project configuration

The project expects the following configuration values:

```json
{
  "avrBuilder.mcu": "atmega32",
  "avrBuilder.fcpu": 8000000,
  "avrBuilder.programmer": "arduino",
  "avrBuilder.port": "COM4",
  "avrBuilder.sourceDir": ".",
  "avrBuilder.outputDir": "build",
  "avrBuilder.extraCFlags": [
    "-ILIB",
    "-IMCAL/1_DIO",
    "-IHAL",
    "-IAPP"
  ]
}
```

Important notes:

- `avrBuilder.port` must match the actual COM port assigned to the programmer/device.
- `avrBuilder.fcpu` must be set to `8000000` for the ATmega32 board used in this project.
- The code includes paths relative to the project root, so the workspace must be opened in the `avrcots` folder.

## Recommended folder structure

```text
avrcots/
├── .vscode/
│   └── settings.json
├── APP/
├── HAL/
├── LIB/
├── MCAL/
├── build/
├── main.c
└── ...
```

## Procedure to use the AVR drivers successfully

### Step 1: Install the tools
Run the two `winget` commands above and verify that the bin folders are available on the system.

### Step 2: Open the correct folder in VS Code
Open the folder that contains the AVR project itself, not the larger repository root:

```text
C:\Users\Yassin\Documents\programming-polyglot-learning-archive\mastering-c\amit_embedded_system_course\interfacing_section_2\avrcots
```

This ensures the include paths and local build configuration work as expected.

### Step 3: Check the port
In Windows Device Manager, find the COM port assigned to the programmer or board and update `.vscode/settings.json` if needed.

Example:

```json
"avrBuilder.port": "COM4"
```

If the port changes, update it before building or flashing.

### Step 4: Build the firmware
Use the AVR build extension or the configured build task to compile the source files.

The project is expected to generate output into the `build` directory.

### Step 5: Verify the code structure
The source is organized by layers:

- `MCAL/1_DIO` contains low-level digital I/O driver code
- `LIB/bit_math_c.h` provides bit manipulation macros
- `main.c` is the application layer that uses the drivers

### Step 6: Flash the board
After successful compilation, upload the generated firmware using the AVR programmer. The project settings assume `arduino` as the programmer and `atmega32` as the target MCU.

### Step 7: Run and test
Once flashed:

- the board should start running the application
- the program may toggle pins defined in the driver logic
- use an oscilloscope or LED indicators to validate the behavior

## Example validation flow

1. Open the `avrcots` folder as a standalone workspace.
2. Confirm the MCU configuration is `atmega32`.
3. Confirm the clock is `8000000`.
4. Confirm the port is correct.
5. Compile the project.
6. Flash the output to the ATmega32.
7. Observe the expected hardware behavior.

## Troubleshooting

### Build fails because includes are not found
Make sure the project is opened at the `avrcots` folder and that the include flags in `.vscode/settings.json` are set correctly:

```json
"-ILIB",
"-IMCAL/1_DIO",
"-IHAL",
"-IAPP"
```

### Programmer or board not detected
- Check the COM port
- Confirm the board is connected
- Ensure the programmer is compatible with the ATmega32
- Update `avrBuilder.port` to the correct port

### Board does not run the firmware
- Check the MCU configuration (`atmega32`)
- Confirm the clock (`8000000`)
- Rebuild and flash the project after fixing the config

## Final note

This project works reliably when the AVR toolchain is installed correctly and the folder is opened as its own workspace. Once those conditions are satisfied, the driver-based AVR code can be built and uploaded consistently.
