# Blackjack Game

<details>
<summary><b> What is Blackjack Game:</b></summary>
<br>

Blackjack Game is an interactive command-line implementation of the classic casino card game, where a player competes against an automated computer dealer to score closest to 21 without busting (exceeding 21).

````markdown
    Your card set: [10, 8] ---> Score: 18
    Computer's card set: [7, 9] ---> Score: 16
    Would like to pick a new card: (y/n): n

    Your card set: [10, 8] ---> Score: 18
    Computer's card set: [7, 9, 10] ---> Score: 26
    You won! ;}
````
</details>


<details>
<summary><b>How is Blackjack Game built:</b></summary>
<br>

- **`Declaration`**:<br>
    - **`Global Scope`**:
        - `1` Variable:
            - `ascii_art`: Raw multiline string containing the ASCII art logo displayed at the start of each turn.

    - **`Function: user_input_validation(choice)`**:
        - `Variables`:
            - `choice`: String parameter validated in a continuous loop to enforce `'y'` or `'n'` user responses.

    - **`Function: generating_random_cards(card_set)`**:
        - `Variables`:
            - `card_set`: Array passed as input containing integer values of currently drawn cards.
            - `cards`: Array of available card values `[11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]` representing face and number cards.
            - `sum_card_set`: Integer storing sum of values in `card_set`.

    - **`Function: black_jack_game()`**:
        - `Variables`:
            - `do_player_want_to_continue_playing`: Boolean flag controlling outer game reset loop.
            - `player_cards`: Array storing player's current hand.
            - `player_score`: Integer storing sum of player's hand values.
            - `computer_cards`: Array storing computer's current hand.
            - `computer_score`: Integer storing sum of computer's hand values.
            - `do_player_want_to_pick_new_card`: Boolean flag controlling hit/stand loop during active turns.
            - `i`: Loop counter for initial two-card deal sequence.

- **`Plan`**:<br>

Define modular helper functions to validate binary inputs (`'y'`/`'n'`) and handle card generation with Ace soft/hard adjustment logic (`11` vs `1`). Initialize hands for both player and computer with two random cards at game start. Prompt the player to hit or stand while verifying score bounds ($\le 21$). If the player stands without busting, draw an additional card for the computer dealer, compare final scores, and announce game outcomes (Win/Loss/Draw). Prompt the user to restart or terminate execution.

- **`Strategy`**:<br>

The project uses functional helper structures and state control logic:
- **Dynamic Ace Adjuster (`generating_random_cards`)**: Evaluates hand total when an Ace (`11`) causes a bust ($sum > 21$), dynamically mutating the value of `11` to `1` using list mutation (`remove(11)` and `append(1)`).
- **Input Sanitization (`user_input_validation`)**: Enforces explicit validation via an internal `while True` loop to ensure inputs strictly match expected choices (`'y'` or `'n'`).
- **Nested Gameplay Loops**: Manages session continuity with an outer `do_player_want_to_continue_playing` loop and turn mechanics via an inner `do_player_want_to_pick_new_card` loop.
- **Terminal Display Reset**: Uses `os.system('cls')` to keep screen output tidy across sequential turn states.

<details>
<summary><b>Input/Output Table:</b></summary>
<br>

|${\color{blue}\text{Input}}$: | ${\color{red}\text{Output}}$:| 
|:---|:---|
|(1) Hit or Stand choice (`'y'`/`'n'`)|(1) Printed card hands and total score count|
|(2) New game choice (`'y'`/`'n'`)|(2) Win, Loss, or Draw game verdict banner|
<br>
</details>
</details>


<details>
<summary><b>Why build Blackjack Game:</b></summary>
<br>

- Implement custom card-drawing logic using probability-weighted lists and `random.choice()`.
- Develop soft/hard Ace handling algorithms to mutate array values under arithmetic threshold conditions ($> 21$).
- Master defensive input handling by abstracting validation workflows into reusable functions.
- Structure sequential turn mechanics using boolean state flags and multi-stage branch evaluation (`if`/`elif`/`else`).
</details>