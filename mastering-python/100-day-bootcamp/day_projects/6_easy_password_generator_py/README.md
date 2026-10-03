# Easy Password Generator
<details>
<summary><b>What is Easy Password Generator:</b></summary>
<br>

A program that prints a random unsophisiticated password for security measures.

<br>
</details>


<details>
<summary><b>How is Easy Password Generator built:</b></summary>
<br>

- **`Declarations`**:<br>
    - `3` Arrays:
        - `letter_list`: List of English characters (letters/alphabets) from ((65 ~ 90) & (98 ~ 121)) -> ((A ~ Z) & (a ~ z)). 
        - `symbols_list`: List of non-English characters (33 ~ 43 except(34 and 39)).
        - `number_list`: List of digits (0 ~ 9).
    
    - `7` Variables:
        - `ascii_letter`: An instance ASCII of an English character in a loop.
        - `ascii_symbol`: An instance ASCII of a non-English character in a loop. 
        - `i`: An instance integer in a loop.

        - `num_of_letter`: The number of letter requested by the user.
        - `num_of_symbols`: The number of symbols requested by the user.
        - `num_of_numbers`: The number of numerials requested by thr user.

        - `password`: 

    - `3` Unused variables:
        - `rand_letter`: An unused instance.
        - `rand_symbol`: An unused instance.
        - `rand_number`: An unused instance.

- **`Plan`**: <br>

To concatenate randomly selected set (defined number by user) of English (letters), Symbol characters, and numerials.
````markdown
    How many letters would you like in your passwords?
    5
    How many symbols would you like?
    6
    How many numbers would you like?
    7
    Your Password is: wRpaW*&))+*2356811
````

- **`Strategy`**:<br>

    - (1) Appending character form of the ASCII decimal representation set using `for ascii_X in range(ASCII_start, ASCII_end + 1, 1)`
        ```python
            for ascii_letter in range(65, 122, 1):
                if ascii_letter not in range(91, 97, 1):
                    letter_list.append(chr(ascii_letter))
            print(letter_list)
        ```

    - (2) Repeating the same implementation in (1) but with different range for convering non-English characters:
        ```python
            print("Symbols: ")
            for ascii_symbol in range(33, 44, 1):
                if ascii_symbol != 34 and ascii_symbol != 39:
                    symbols_list.append(chr(ascii_symbol))
            print(symbols_list)
        ```

    - (3) Appending numerials:
        ```python
            print("Numbers: ")
            for i in range(0, 10, 1):
                number_list.append(str(i))
            print(number_list)
        ```
    
    - (4) Receiving input prompt from the user:
        ```python
            print("Numbers: ")
            for i in range(0, 10, 1):
                number_list.append(str(i))
            print(number_list)
        ```
    - (5) Randomly selecting elements inside defined lists:
        ```python
            for rand_letter in range(0, num_of_letter, 1):
                password += random.choice(letter_list)
                
            for rand_symbol in range(0, num_of_symbols, 1):
                password += random.choice(symbols_list)
                
            for rand_number in range(0, num_of_numbers, 1):
                password += random.choice(number_list)
        ```
    - (6) Printing the password:
        ```python
            print(f"Your Password is: {password}")
        ```
    
<br>
<details>
<summary><b>Input/Output Table:</b></summary>
<br>

|${\color{blue}\text{Input}}$: | ${\color{red}\text{Output}}$:| 
|:---|:---|
|(1) Number of letters, symbols, numerials inside the password (integer)|(1) Generated password (string)|

<br>
</details>

</details>


<details>
<summary><b>Why build Easy Password Generator:</b></summary>
<br>

- **`Implemented`**:
    - Iterative control flow `for: loop`:
        - `range` iteration.

    - Conditional control flow:
        - Using `is in` for checking exclusivity of an element in an array.
        
</details>