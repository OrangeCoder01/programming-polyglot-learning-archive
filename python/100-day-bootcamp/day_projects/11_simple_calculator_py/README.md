# Simple Calculator

<details>
<summary><b> What is Simple Calculator:</b></summary>
<br>

Simple Calculator is a command-line utility that performs standard arithmetic operations (addition, subtraction, multiplication, and division) with support for continuous calculation chaining.

```markdown
    First number: 10
    Pick an operation: +
    Next number: 5
    Result: 10.0 + 5.0 = 15.0
    Type 'y' to continue calculating with 15.0, or 'n' to start new calculation: y
```
</details>


<details>
<summary><b>How is Simple Calculator built:</b></summary>
<br>

- **`Declaration`**:<br>
    - **`Global Scope`**:
        - `1` Variable:
            - `ascii_art`: String containing the multi-line ASCII representation of a handheld calculator displayed upon launch.
        - `2` Variables:
            - `n1`: Integer initial dummy assignment holding global scope value.
            - `n2`: Integer initial dummy assignment holding global scope value.
        - `1` Dictionary:
            - `operations`: Hash map pairing string operator symbols (`"+"`, `"-"`, `*`, `"/"`) to their corresponding python arithmetic functions (`add`, `subtract`, `multiply`, `divide`).
        - `4` Functions:
            - `add(n1, n2)`: Returns sum of two arguments (`n1 + n2`).
            - `subtract(n1, n2)`: Returns difference of two arguments (`n1 - n2`).
            - `multiply(n1, n2)`: Returns product of two arguments (`n1 * n2`).
            - `divide(n1, n2)`: Returns quotient of two arguments (`n1 / n2`).

    - **`Function: simple_calculator()`**:
        - `Variables`:
            - `want_to_calculate`: Boolean state flag controlling continuous evaluation loop.
            - `n1`: Float storing primary operand.
            - `type_of_operation`: String representing selected key operator from dictionary.
            - `n2`: Float storing secondary operand.
            - `result`: Float output generated from dynamic function invocation.
            - `choice`: String user choice (`'y'` or `'n'`) dictating whether to chain previous result or reset.

- **`Plan`**:<br>

Define basic modular functions for addition, subtraction, multiplication, and division, and map them to their string representation inside a dictionary. Clear the system console, display introductory ASCII art, and collect initial numeric input from the user. Render available operational choices, parse selected operator, prompt for secondary numeric input, and dynamically evaluate calculation. Prompt user to either retain output for subsequent chaining or break inner loop to start fresh.

- **`Strategy`**:<br>

The application implements high-level functional execution combined with state persistence:
- **First-Class Function Mapping**: Map mathematical symbols directly to function pointers in the `operations` dictionary for lookup dispatching without redundant `if/elif` conditional branches.
- **Nested Loop Control**: Utilize an outer infinite `while True` loop to handle application reset/restarts alongside an inner `while want_to_calculate` loop to maintain chaining state.
- **State Mutation & Propagation**: Reassign `n1 = result` when user inputs `'y'`, preserving output across continuous calculations.
- **Console Session Reset**: Trigger `os.system('cls')` on top-level loop iteration to clear terminal artifacts during resets.

<details>
<summary><b>Input/Output Table:</b></summary>
<br>

|${\color{blue}\text{Input}}$: | ${\color{red}\text{Output}}$:| 
|:---|:---|
|(1) First number (`n1`)|(1) Formatted string showing full expression and calculated result|
|(2) Operation type (`+`, `-`, `*`, `/`)|(2) Console visual ASCII header printout|
|(3) Next number (`n2`)||
|(4) Continuation choice (`'y'`/`'n'`)||
<br>
</details>
</details>


<details>
<summary><b>Why build Simple Calculator:</b></summary>
<br>

- Master first-class function delegation by storing callable function references inside Python dictionary mapping constructs.
- Practice nested state management loops (`while` loops with dynamic `True`/`False` flag toggling).
- Implement persistent memory storage across iteration loops by mutating function inputs dynamically.
- Understand terminal session manipulation and system calls via `os.system()` integration.
</details>