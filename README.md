# Programming Polyglot Learning Archive

![C++](https://img.shields.io/badge/C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white)
![C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino--IDE-00979D?logo=arduino&logoColor=white)
![License: MIT](https://img.shields.io/badge/license-MIT-green)

A chronological, personal archive of my programming journey — challenges, projects, and reusable libraries — kept as a long-term record of how my code, habits, and problem-solving have evolved, across C++, Python, C, and Arduino IDE (C/C++).

## Table of Contents

1. [Overview](#overview)
2. [Repository structure](#repository-structure)
3. [Organizing principles](#organizing-principles)
4. [Language modules](#language-modules)
5. [Shared documentation](#shared-documentation)
6. [Personal libraries](#personal-libraries)
7. [Development environment](#development-environment)
8. [Color legend](#color-legend)
9. [License](#license)
10. [Author](#author)

## Overview

This repository documents my path from `Hello World` toward writing cleaner, more modular, better-validated, and more efficient code. It mixes:

- **Challenges** — focused exercises that build one concept or algorithmic skill at a time.
- **Projects** — larger, multi-concept builds that demand modularity, data integrity, and system-level thinking.
- **Personal libraries** — reusable code (mostly in C/C++) that keeps later challenges and projects DRY.

Some work follows a formal syllabus (a paid course, a well-known bootcamp); the rest is self-directed, often shaped through iterative feedback from an AI mentor (ChatGPT). Both paths are represented here, and each language currently mixes them a little differently — see [Language modules](#language-modules) below.

## Repository structure

```
programming-polyglot-learning-archive/
├── documents/                         # Shared rules/strategy docs for repeating folder patterns
│   └── personal-forge/
├── mastering-c-plus-plus/
│   ├── personal-forge/
│   │   ├── challenges/                # 30+ standalone exercises
│   │   └── projects/                  # 3 larger builds
│   └── utility_functions/             # yassin_math_cpp.h and friends
├── mastering-python/
│   ├── 100-day-bootcamp/              # Dr. Angela Yu's course
│   │   ├── day_lessions/
│   │   └── day_projects/
│   ├── personal-forge/
│   │   └── challenges/
│   └── testing_bench/                 # scratch/sandbox area
├── mastering-c/
│   ├── amit_embedded_system_course/   # AMIT Embedded Systems course, by session
│   └── testing_bench/                 # scratch/sandbox area
├── mastering-arduino-ide/
│   ├── arduino-mcu/
│   │   └── arduino-uno/
│   │       ├── debuggers/
│   │       └── projects/learning-level/
│   └── espressif-mcu/
│       └── esp32-wroom-38pins/
│           └── debuggers/
├── LICENSE
└── README.md
```

## Organizing principles

### Challenges vs. Projects

| | Challenges | Projects |
|---|---|---|
| **Goal** | Solve one well-defined problem | Solve a larger, real-world-shaped problem |
| **Trains** | Clean code, algorithmic intuition, time/space efficiency | Modularity, data integrity across state, program coherence |
| **Volume** | The majority of the archive | Fewer, and slower to produce |
| **Examples** | `Armstrong Number`, `GCD/LCM finders`, `Bubble Sort` (C++);| `Student Management System`, `Bank Simulator` (C++); `Water Dispenser`, `Laser Trip-Wire + Object Counter` (Arduino) |

A few challenges reappear under the same label with a different implementation — that's intentional, revisiting a problem with a new algorithmic approach as skills grow.

### Personal Forge vs. Course Curriculum

**`personal-forge`** holds work outside any formal syllabus — problems I pose to myself, or tasks set by an AI mentor (ChatGPT) that hands out challenges, reviews my code, and points out mistakes.

**Course-curriculum folders** are named after the actual course and follow *that instructor's* structure rather than the personal-forge template — which is why the pattern isn't identical across languages:

- Python's **100 Day Python Bootcamp** (Dr. Angela Yu) is organized into `day_lessions` and `day_projects`.
- C's **AMIT Embedded Systems Course** is organized by `session_N`, each with `classwork` and `assignment` subfolders.

Rules and naming strategy for repeating folders (like `personal-forge`) live once in [`documents/`](#shared-documentation) rather than being restated in every language folder.

### Naming convention (personal-forge)

Folders follow `(order)_(purpose)_(language)`:

```
15_armstrong_number_cpp
 │  └──────┬───────┘ └┬┘
 │      purpose     language
 └─ chronological order
```

Order reflects when it was written — earlier folders reflect an earlier coding style, later ones a more deliberate one.

## Language modules

### C++

- **`personal-forge/challenges`** — 30+ self-contained exercises (numeric analysis, arrays, recursion, sorting, a statistics toolkit, a grade system).
- **`personal-forge/projects`** — 3 larger builds: a multi-function utility, a bank account simulator, and a student management system.
- **`utility_functions`** — `yassin_math_cpp.h`, a small reusable math library (custom `pow`, `round`, etc.) used from challenge 32 onward.
- No course-curriculum folder yet — all C++ work so far is self-directed.

### Python

- **`100-day-bootcamp`** — Dr. Angela Yu's course: lesson code in `day_lessions`, and 21 stand-alone projects in `day_projects` (Hangman, Caesar Cipher, Blackjack, Snake, Pong, and others), spanning bootcamp days 1–22.
- **`personal-forge/challenges`** — early self-directed exercises (string sorting, digit sums, a century identifier). No `projects` subfolder yet.
- **`testing_bench`** — a scratch file for quick experiments, outside the archive proper.

### C

- **`amit_embedded_system_course`** — coursework from AMIT (Association of Management and Information Technology, Egypt)'s Embedded Systems course, organized by session (12 so far), each split into `classwork` and `assignment`, several with their own small helper library.
- **`testing_bench`** — same purpose as Python's: a sandbox, not part of the graded/reviewed archive.

### Arduino IDE (C/C++)

Arduino IDE gets its own layering, since it mixes hardware and software in a way plain C/C++ doesn't:

```
Board Brand → MCU Family → { Debuggers, Projects → Difficulty → Code }
```

- **Arduino (`arduino-mcu/arduino-uno`)** — 2 debugging toolkits (microphone, passive buzzer) and 12 projects at the `learning-level` difficulty (LCD displays, servos, a joystick-driven angle monitor, a laser trip-wire with object counting, and a water dispenser).
- **Espressif (`espressif-mcu/esp32-wroom-38pins`)** — 2 debugging toolkits so far (an op-amp debugger, and a rotary encoder debugger with two logged enhancement passes). No projects folder yet.

Only Arduino UNO and ESP32 WROOM (38-pin) are populated today; each board-brand README documents its own MCU family tree for what comes next.

## Shared documentation

The [`documents/`](documents) folder holds the rules and naming strategy for folder patterns that repeat across languages — currently `personal-forge` and its `challenges`/`projects` children — so the explanation is written once instead of duplicated in every language folder that uses the pattern.

## Personal libraries

Reusable, well-tested functions live in dedicated library folders (mostly C/C++, where the payoff for avoiding repetition is highest):

- `mastering-c-plus-plus/utility_functions/yassin_math_cpp.h`
- Several `helper_library/utility_functions_c.h` files under individual AMIT course sessions.

## Development environment

C/C++ work is developed in VS Code — see [`.vscode/`](.vscode) for the IntelliSense (`c_cpp_properties.json`), build/debug (`tasks.json`, `launch.json`), and editor settings used across the archive.


## License

Released under the [MIT License](LICENSE).

## Author

**Yassin Diaa** — ECE student with a deep curiosity for tinkering in engineering fields.
GitHub: [@OrangeCoder01](https://github.com/OrangeCoder01)
