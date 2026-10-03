# Caesar Cipher
# Caesar Cipher 
<details>
<summary><b> What is Caesar Cipher:</b></summary>
<br>

Caesar Cipher is an encryption technique where each letter in the plaintext is shifted by a fixed number of positions down or up the alphabet. For example, with a shift of 3:

````markdown
    Type: encode
    Plaintext message: Hello World!
    Shift: 3
    Result: Khoor Zruog!
````
</details>


<details>
<summary><b>How is Caesar Cipher built:</b></summary>
<br>

- **`Declaration`**:<br>
    - **`Global Scope`**:
            - `1` Variable:
                - `ascii_art`: String containing ASCII art banner displayed at program startup.
            - `4` Arrays:
                - `letter_ascii`: List storing ASCII integer values for uppercase (65–90) and lowercase (97–122) letters.
                - `symbol_ascii`: List storing ASCII integer values for printable symbols and space characters (32–187 excluding letters).
                - `letter_char`: List storing character conversions of all ASCII values in `letter_ascii`.
                - `symbol_char`: List storing character conversions of all ASCII values in `symbol_ascii`.

        - **`Function: user_validation()`**:
            - `Variables`:
                - `user_type_input`: String capturing the user's choice (`'encode'` or `'decode'`).
                - `is_message_valid`: Boolean flag checking if all characters in input message exist in valid character sets.
                - `message`: String input provided by the user to process.
                - `char`: Iterative character instance from `message`.
                - `shifting_input`: String raw input for shift magnitude.
                - `shifting`: Integer parsed from `shifting_input` constrained within $[-26, 26]$.

        - **`Function: mapping_the_shifting(message, shifting)`**:
            - `Variables`:
                - `char`: Iterative character instance from `message`.
                - `i`: Loop index tracker for list element mutation.
                - `element`: Integer ASCII value stored at index `i` of `output`.
                - `output_message`: String built by converting mutated ASCII integers back to characters.
                - `value`: Iterative ASCII integer instance evaluated during output string assembly.
            - `1` Array:
                - `output`: List storing individual ASCII ordinal integers corresponding to characters in `message`.

        - **`Function: caesar_cipher()`**:
            - `Variables`:
                - `user_type_input_K`: String mode returned from `user_validation()`.
                - `message_K`: String message returned from `user_validation()`.
                - `shifting_K`: Integer shift value returned from `user_validation()`, negated if mode is `'decode'`.
                - `output_message`: Resulting encrypted or decrypted string returned by `mapping_the_shifting`.

        - **`Function: endless_user_input_looping()`**:
            - `Variables`:
                - `choice`: String loop controller (`'yes'` or `'no'`) dictating whether to continue program execution.
- **`Plan`**:<br>

Generating global ASCII lookup tables for letters and symbols. Defining modular functions to handle input validation, shift calculation, and main cipher logic. Validating mode selection (`'encode'`/`'decode'`), character validity, and ensuring numerical shift values stay within $[-26, 26]$. Converting characters to ASCII integer representations, applying shifting logic with modular wraparound boundary checks for upper and lower case ranges, and reconstructing the transformed character string. Wrapping the overall execution inside an interactive loop allowing repeated operations until explicitly exited.
- **`Strategy`**:<br>

The cipher architecture uses modular functional division to handle input verification, numerical shifting, and game loop execution independently:
- **Precomputed Character Tables**: Build `letter_ascii`, `symbol_ascii`, `letter_char`, and `symbol_char` arrays at launch to establish fast membership lookups for input validation and character range boundary checks.

- **Strict Validation Pipeline (`user_validation`)**: Enforce valid operational modes (`'encode'`/`'decode'`), reject unsupported characters in `message`, and validate `shifting` inputs using `try/except ValueError` parsing with numerical bounds enforcement within $[-26, 26]$.

- **Shift Inversion**: Normalize encryption and decryption routines under a single transformation pipeline by negating the shift value ($shifting = -1 \times shifting$) when mode is set to `'decode'`.

- **Boundary Aware ASCII Shifting (`mapping_the_shifting`)**: Convert input characters into an array of ASCII integers Iterate through the array to modify letter bounds:
   - For uppercase letters ($65 \le x \le 90$): apply shift, wrapping around if $> 90$ (subtract $26$) or $< 65$ (add $26$).
   - For lowercase letters ($97 \le x \le 122$): apply shift, wrapping around if $> 122$ (subtract $26$) or $< 97$ (add $26$).
   - Preserve non-alphabetical symbols and spaces without modification.
   
- **Interactive Lifecycle (`endless_user_input_looping`)**: Display opening ASCII banner art and maintain an continuous execution loop prompt, terminating only when the user explicitly enters `'no'`.
<details>
<summary><b>Input/Output Table:</b></summary>
<br>

|${\color{blue}\text{Input}}$: | ${\color{red}\text{Output}}$:| 
|:---|:---|
|(1) Shifting number|(1) The word after shifting each character|
|(2) Type of shifting {encode/decoding}||
<br>
</details>
</details>


<details>
<summary><b>Why build Caesar Cipher:</b></summary>
<br>

- Master ASCII character encoding and numerical conversions using Python built-ins `ord()` and `chr()`.
- Implement functional decomposition by structuring code into focused, single-responsibility functions (`user_validation`, `mapping_the_shifting`, `caesar_cipher`, and `endless_user_input_looping`).
- Enforce robust input sanitization and defensive exception handling using `try/except` blocks and nested validation loops.
- Develop custom mathematical boundary wraparound logic to handle forward and backward index overflows across case-sensitive alphabet ranges.
- Gain practical experience with variable scope separation, keyword argument passing, and modular loop control patterns.
</details>