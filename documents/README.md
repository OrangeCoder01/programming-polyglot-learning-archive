# Documents:

This document serves as a centralized reference for recurring folder structures found across various programming language modules (e.g., `Cpp`, `Python`) within this repository. To follow the **DRY (Don't Repeat Yourself)** principle, shared folder definitions, functionalities, and features are documented here rather than duplicated across language subdirectories.

---

## 1. Structure Overview

Language-specific subdirectories share a standard directory layout:

```text
mastering-<language>/
└── personal-forge/
    ├── challenges/
    └── projects/
```

- **`personal-forge`**: Top-level directory for custom learning goals, exercises, and AI-prompted tasks outside formal curriculum constraints.
- **`challenges`**: Focused mini-programs and individual algorithmic tasks.
- **`projects`**: Multi-file, feature-rich applications demonstrating system design and software patterns.

---

## 2. Common Folder Documentation Standard

Every recurring folder uses a unified structure covering two core questions:
1. **What is X?** (Functionality & Features)
2. **Why is X?** (Purpose & Objectives)

---

### Folder Focus: `challenges`

<details>
<summary><strong>(1) What is <code>challenges</code>?</strong></summary>

#### (1.1) Functionality
The `challenges` folder contains standalone code files targeted at solving isolated programming problems. 

**Expected Outputs & Scope:**
- Single-purpose algorithms and mathematical logic (e.g., *Least Common Multiple (LCM)*, *Prime Number Checker*, *Bubble Sort*).
- Small-scale problem solving focusing on time complexity, space optimization, and core language primitives.
- Input validation and deterministic test cases executed via standard output or unit tests.

#### (1.2) Features
Characteristics that distinguish `challenges` from other repository folders:
- **Atomicity:** Each program operates independently with minimal or no external dependencies.
- **Algorithmic Focus:** Prioritizes efficiency and data structure handling over architectural design.
- **Standardized Execution:** Standalone scripts or single-file compilations designed for quick testing and review.

</details>

<details>
<summary><strong>(2) Why is <code>challenges</code>? </strong></summary>

- **Algorithmic Mastery:** Build muscle memory for foundational algorithms and data structures across multiple programming languages.
- **Rapid Iteration:** Practice writing concise, clean code without the setup overhead of larger project architectures.

</details>

---