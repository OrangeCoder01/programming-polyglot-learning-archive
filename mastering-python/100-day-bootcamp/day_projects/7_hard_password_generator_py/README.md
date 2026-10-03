# Hard Password Generator:
<details>
<summary><b>What is Hard Password Generator:</b></summary>
<br>

The program prints difficult to crack password.
</details>


<details>
<summary><b>How is Hard Password Generator built:</b></summary>
<br>

- **`Declarations`**:<br>
    - Most of names of data structure are identical and perform the same function as in [Easy Password Generator](https://github.com/OrangeCoder01/programming-polyglot-learning-archive/blob/main/mastering-python/100-day-bootcamp/day_projects/6_easy_password_generator_py/README.md).

    - Exception:
        - Replacing variable `password` with an array `basic_password` and append elements instead of concatenating.

        - `1` Array:
            - `already_chosen_indices`: contains indices of elements already chosen.

        - `3` Variable:
            - `char_element`: the selected character.
            - `rand_choice_index`: randomly chosen index.
            - `enhanced_password`: The enhanced version of the previous basic password.

- **`Plan`**: <br>
Implementing the same solution approach found in `Easy Password Generator`, but adding in the last section algorithm that ensures that the selection of a char from the `basic_password` array is random and not repeated in index (not value), then concatenating the char with string `enhanced_password`. 
    
- **`Strategy`**:<br>

    - (1) Iterating for `(number of times)` equal to `(number of elements)` of the `basic_password`:
        ```python
            for char_element in range(len(basic_password)):
        ```

    - (2) Forever checking if the selected char's index is not previously selected:
        ```python
            while(True):
        ```

    - (3) Randomly selecting index:
        ```python
            rand_choice_index = random.randint(0, len(basic_password)-1)
        ```

    - (4) Checking if index is not repeating:
        ```python
            if rand_choice_index not in already_chosen_indices:
        ```

        - (4.1) if the condition is true; appending `rand_choice_index` in `already_chosen_indices` and concatenating the char with `enhanced_password`, then break the `while` loop:
            ```python
                already_chosen_indices.append(rand_choice_index)
                enhanced_password += basic_password[rand_choice_index]
                break
            ```
        - (4.2) if not; looping once again.
    
    - (5) Printing both basic and enhanced passwords. 
        ```python
            print(f"Your basic generated Password is: {basic_password}")
            print(f"Your enhanced generated Password is: {enhanced_password}\n")
        ```


<details>
<summary><b>Input/Output Table:</b></summary>
<br>

|${\color{blue}\text{Input}}$: | ${\color{red}\text{Output}}$:| 
|:---|:---|
|(1) Number of letters, symbols, numerials inside the password (integer)|(1) Generated password (enhanced and basic) (string)|


<br>
</details>

</details>


<details>
<summary><b>Why build Hard Password Generator:</b></summary>
<br>

- **`Implemented`**:
    - (1) Element retrieval through calling its index in an array.
</details>