# Blind Auction 
<details>
<summary><b> What is Blind Auction:</b></summary>
<br>

A Blind Auction (or silent auction) is a game where multiple bidders submit their secret bids without knowing what others have offered. Once all bidders have entered their names and bids, the screen clears between turns to maintain secrecy. When bidding concludes, the program determines the highest bidder and announces the winner.

```
                         ___________
                         \         /
                          )_______(
                          |"""""""|_.-._,.---------.,_.-._
                          |       | | |               | | ''-.
                          |       |_| |_             _| |_..-'
                          |_______| '-' `'---------'` '-'
                          )"""""""(
                         /_________\
                         `'-------'`
                       .-------------.
                   jgs/_______________\

The winner is Alice with a bid of $150.0
```
<br>

</details>


<details>
<summary><b> How is Blind Auction built:</b></summary>
<br>

- **`Declarations`**:<br>
    - **`Global Scope`**:
        - `1` Module:
            - `os`: Used for clearing terminal screen (`os.system`).
        - `1` Variable:
            - `ascii_art`: String variable holding the trophy banner.
        - `2` Lists:
            - `names`: List storing bidder names.
            - `bidding_bills`: List storing float bid amounts.
        - `1` Dictionary:
            - `bidder_data`: Dictionary binding `names` and `bidding_bills` under keys `"bidder_names"` and `"biddings"`.

    - **`Function: user_validation(expected_type, keyword, question, question_suffix)`**:
        - `Variables`:
            - `raw_input`: String storing raw user response from terminal.
            - `user_input`: Processed variable converted to the target data type (`str`, `float`, or `int`).
        - `1` List:
            - `expected_type_list`: List defining valid target type strings `["int", "float", "str"]`.
        - `1` Dictionary:
            - `string_converter`: Dictionary mapping type strings to conversion functions (`int`, `float`, `str`).

    - **`Function: auction_game()`**:
        - `Variables`:
            - `is_there_another_bidder`: Boolean flag controlling the main bidding loop.
            - `user_choice`: String storing input when asked if more bidders exist (`'yes'` or `'no'`).
            - `alert`: Boolean flag checking for invalid loop prompt responses.
            - `max_bidding`: Float tracking the highest value in `bidder_data["biddings"]`.
            - `max_bidding_index`: Integer storing index of the maximum bid.
            - `name_with_highest_bidding`: String holding the winner's name retrieved using `max_bidding_index`.


- **`Plan`**: <br>
Creating dynamic data structures (lists and a dictionary) to hold bidder information. Defining a reusable input validation function with type conversion and error handling using `try/except`. Prompting for user name and bid amount in a loop, asking if additional bidders exist. Clearing the terminal screen after each turn to keep bids secret. Once bidding finishes, locating the maximum bid value and matching bidder index to display the winner alongside ASCII trophy art.

- **`Strategy`**:<br>
The auction logic enforces secrecy and data integrity through structured execution steps:
1. **Data Binding**: Link global `names` and `bidding_bills` lists inside the `bidder_data` dictionary to synchronize bidder names with bid values via shared indexing.
2. **Defensive Validation (`user_validation`)**: Pass target data types into `user_validation()`, utilizing a `try/except ValueError` block and dictionary function mapping (`string_converter`) to ensure float inputs for bids are valid before appending.
3. **Screen Clearing for Secrecy**: Execute `os.system('cls' if os.name == 'nt' else 'clear')` at the end of each iteration to clear the terminal screen before the next bidder steps up.
4. **Winner Resolution**: Evaluate the maximum bid using `max(bidder_data["biddings"])`, locate its position using `.index()`, and retrieve the corresponding winner's name from `bidder_data["bidder_names"]`.

<details>
<summary><b> Input/Output Table:</b></summary>
<br>

| ${\color{blue}\text{(Input)}}$ | ${\color{red}\text{Output}}$ |
|:---|:---|
| (1) Input Name (string)|(1) The highest bidder (his name and his bidding). (string + text)|
| (2) Input Bid Amount  (integer)||
| (3) Checking if there is another bidder (string) ||

<br>
</details>

</details>


<br>
<details>
<summary><b>Why build Blind Auction:</b></summary>
<br>

- Practice operating system interaction by using the `os` module to manage terminal display states across platforms.

- Gain experience binding parallel data structures together using dictionaries and list index referencing.

- Implement reusable higher-order function patterns through dynamic type conversion and `try/except` exception handling.

- Learn clean code techniques such as Python ternary operators for inline conditional assignments.

</details>