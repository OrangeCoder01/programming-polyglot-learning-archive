# Number Guessing Game
<details>
<summary><b> What is Number Guessing Game:</b></summary>
<br>

The Number Guessing Game is a terminal-based game where the player attempts to guess a randomly generated secret number between 1 and 100. The player first selects a difficulty level (easy or hard) which determines their number of attempts. After each guess, the game provides categorical feedback on how close the guess is to the target.

```
███    ██ ██    ██ ███    ███ ██████  ███████ ██████       ██████  ██    ██ ███████ ███████ ███████      ██████   █████  ███    ███ ███████ 
████   ██ ██    ██ ████  ████ ██   ██ ██      ██   ██     ██       ██    ██ ██      ██      ██          ██       ██   ██ ████  ████ ██      
██ ██  ██ ██    ██ ██ ████ ██ ██████  █████   ██████      ██   ███ ██    ██ █████   ███████ ███████     ██   ███ ███████ ██ ████ ██ █████   
██  ██ ██ ██    ██ ██  ██  ██ ██   ██ ██      ██   ██     ██    ██ ██    ██ ██           ██      ██     ██    ██ ██   ██ ██  ██  ██ ██      
██   ████  ██████  ██      ██ ██████  ███████ ██   ██      ██████   ██████  ███████ ███████ ███████      ██████  ██   ██ ██      ██ ███████ 

```
<br>

</details>


<details>
<summary><b> How is Number Guessing Game built:</b></summary>
<br>

- **`Declarations`**:<br>
    - **`Global Scope`**:
        - `2` Modules:
            - `os`: Used for clearing terminal screen (`os.system`).
            - `random`: Used to generate the secret target number (`random.randint`).
        - `2` Variables:
            - `ascii_art`: String variable holding the title banner.
            - `number_of_attempts`: Integer tracking the maximum allowed guesses based on difficulty.

    - **`Function: difficulty_choice(choice)`**:
        - `Variables`:
            - Modifies the global `number_of_attempts` integer based on the user's string `choice` ("hard" = 5, "easy" = 10).

    - **`Function: feedback(user_guess, target)`**:
        - `Variables`:
            - `message`: String storing the proximity feedback.
            - `diff`: Integer storing the absolute difference between guess and target.
            - Boolean flags: `too_close`, `close`, `mild_dis`, `far`, `too_far` representing different proximity ranges.

    - **`Function: user_choice_checker(compare_set)`**:
        - `Variables`:
            - `user_difficulty_choice`: String storing the validated user input, strictly checked against the valid strings in `compare_set`.

    - **`Function: user_input_integer_checker()`**:
        - `Variables`:
            - `user_int`: Integer safely parsed from terminal input within a `try/except` block to ensure valid 1-100 values.

    - **`Function: number_guessing_game()`**:
        - `Variables`:
            - `can_continue`: Boolean flag controlling the main replay loop.
            - `target`: Integer storing the random number to be guessed.
            - `iteration`: Integer tracking the remaining guesses for the current round.
            - `win_flag`: Boolean flag indicating if the user successfully guessed the number.
            - `user_guess`: Integer storing the user's current attempt.


- **`Plan`**: <br>
Create an interactive game loop that starts by prompting the user for a difficulty setting to define their attempt limit. Generate a random target integer between 1 and 100. In a nested loop, repeatedly ask the user for integer guesses, utilizing defensive programming (`try/except`) to handle bad inputs. Compare valid guesses to the target, calculating the absolute difference to give categorical feedback ("Too close", "Far", etc.). Conclude the round when the user guesses correctly or runs out of attempts, then offer a replay prompt that clears the screen for a fresh start.

- **`Strategy`**:<br>
The game logic relies on robust input handling and modern Python features:
1. **Global Variable Mutation**: Utilize the `global` keyword inside `difficulty_choice` to set the starting game state (`number_of_attempts`) based on a validated user selection.
2. **Defensive Validation (`user_input_integer_checker`)**: Implement a `while True` loop paired with a `try/except ValueError` block. This strictly enforces that users can only proceed if they enter a valid integer between 1 and 100.
3. **Advanced Pattern Matching**: Use Python's `match/case` structure in the `feedback` function alongside boolean condition checks (`case int() if too_close:`) to elegantly map numeric distance to specific string hints.
4. **Game State Management**: Manage loops cleanly with a `win_flag` and `can_continue` boolean, and utilize `os.system('cls' if os.name == 'nt' else 'clear')` to reset the terminal visual state upon restarting.

<details>
<summary><b> Input/Output Table:</b></summary>
<br>

| ${\color{blue}\text{(Input)}}$ | ${\color{red}\text{Output}}$ |
|:---|:---|
| (1) Difficulty Choice (string: 'easy' or 'hard') | (1) Feedback on proximity (string: 'Too close', 'Far', etc.) |
| (2) Number Guess (integer: 1 to 100) | (2) Win/Loss declaration with the target number (string) |
| (3) Play Again Choice (string: 'y' or 'n') | (3) Cleared terminal screen upon restart |

<br>
</details>

</details>


<br>
<details>
<summary><b>Why build Number Guessing Game:</b></summary>
<br>

- Practice utilizing modern Python syntax, specifically structural pattern matching (`match/case`) introduced in Python 3.10.

- Gain experience with robust error handling by writing custom validation loops that catch `ValueError` exceptions for user inputs.

- Understand variable scope in Python by manipulating a global variable (`number_of_attempts`) from within a local function scope.

- Enhance standard library utilization by combining the `random` module for game mechanics and the `os` module for terminal UI management.

</details>