# Rock, Paper, Scissor Game
<details>
<summary><b>What is Rock, Paper, Scissor Game:</b></summary>
<br>

The RPS game is a game played by one hand from two opponents:
- `Scissor` gesture beats `Paper` gesture, but beaten by `Rock`'s.
- `Rock` gesture beats `Scissor` gesture, but beaten by `Paper`'s.
- `Paper` gesture beats `Rock` gesture, but beaten by `Scissor`'s.

This is one round game, played by the user and the computer. if the user's gesture beats the computer's: declaring the user as `winner` in the terminal, otherwise: a `loser`.
<br>
</details>


<details>
<summary><b>How is X built:</b></summary>
<br>

- **Declarations**:
    - `3` ASCII art gestures:
        - `ascii_rock`: Rock ASCII art gesture.
        - `ascii_paper`: Paper ASCII art gesture.
        - `ascii_scissor`: Scissor ASCII art gesture.

    - `1` Array:
        - `ascii_art`: it contains the ASCII art of the gestures of RPS.

    - `4` Variables:
        - `random_computer_decision`: randomly generated value from (0 ~ 2(and including)).
        - `computer_virtual_hand`: the literal string representation of the computer's chosen gesture.
        - `user_hand`: it is the literal string representation of the user's chosen gesture.
        - `user_decision`: it is a value from (0 ~ 2).
    
    - `1` Module:
        - `random`: importing `random` module. 

- **Strategy**:<br>
````markdown
    Inserting ["ascii_rock", "ascii_paper", "ascii_scissor"] as elements inside array "ascii_art" ,
    "random_computer_decision" is randomly assigned a value from (0 ~ 2) using "random" module with "randint" feature.
    
    "random_computer_decision" undergoes conditional control flow, if it is equal to (0, 1, 2), the "computer_virtual_hand" is assigned to ("rock", "paper", "scissor")
    respectively. That was the computer part.

    "user_decision" is assigned with integer casted result from user's prompt for choosing ("rock", "paper", "scissor") by prompting ("0", "1", "2"), "user_hand" is
    thus assigned with respect to the value of "user_hand" inside a Conditional control flow. That is the user's part.
    
    There is series of Conditional control flow for check the ("winner", "loser", "draw") by comparing "user_hand" and "computer_virtual_hand.
````
```python
    if (user_hand == "rock" and computer_virtual_hand == "scissor") or (user_hand == "paper" and computer_virtual_hand == "rock") or (user_hand == "scissor" and computer_virtual_hand == "paper"):
        print("\nYou won")
    elif (computer_virtual_hand == "rock" and user_hand == "scissor") or (computer_virtual_hand == "paper" and user_hand == "rock") or (computer_virtual_hand == "scissor" and user_hand == "paper"):
        print("\nYou lose")
    elif computer_virtual_hand == user_hand:
        print("\nDraw")
```

<br>
<details>
<summary><b>Input/Output Table:</b></summary>
<br>

|${\color{blue}\text{Input}}$: | ${\color{red}\text{Output}}$:| 
|:---|:---|
|(1) index input (0, 1, 2) (integer)| (1) user's status in the game ("winner", "loser", "draw") (string)|

<br>
</details>

</details>


<details>
<summary><b>Why build X:</b></summary>
<br>

Implementing:
- Conditional Control Flow:
    - Series of Multiple conditions.
    - Series of conditional control flow (`if`: -> `elif`: -> `else`:)
- Importing modules.
<br>
</details>