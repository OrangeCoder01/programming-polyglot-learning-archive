# Pizza bill
<details>
<summary><b>What is Pizza bill:</b></summary>
<br>

Pizza bill is about calculating the bill of custom pizza add-ons
the user selects.

</details>


<details>
<summary><b>How is Pizza bill built:</b></summary>
<br>

`7` variable:
- `3` **input** variables:
    - `pizza_size`: The size of pizza: [Small: "S", Medium: "M", Large: "L"] (`string`).
    - `pepperoni_choice`: Choice for adding pepperoni (`boolean`).
    - `extra_cheese_choice`: Choice for extra cheese (`boolean`).

- `3` **processing** variables:
    - `pizza_size_cost`:  The cost of the pizza is dependent on the size of the pizza ["S": 15, "M": 20, "L": 25] (`float`).
    - `pepperoni_cost`: if the user asks for extra pepperoni, it costs 3 dollars by default, but 2 dollars for small size (`float`).
    - `extra_cheese_cost`: if the user asks for extra cheese, it is equated to 1 (`float`).
- `1` **Output** variable:
    - `final_bill`: The final bill.

```python:
        final_bill = pizza_size_cost + pepperoni_cost + extra_cheese_cost
        print(f"Your final bill is: ${final_bill}")
```

<details>
<summary><b> Input/Output Table: </b></summary>
<br>

|${\color{blue}\text{Input}}$: | ${\color{red}\text{Output}}$:| 
|:---|:---|
|(1) Choices for pizza size and add-ons (`boolean`)| (1) The final bill (`float`)|

<br>
</details>
</details>


<details>
<summary><b>Why build Pizza bill:</b></summary>
<br>

Implemented:
- **Conditional control flow**.
    - Keywords:
        - `if`, `elif`, `else`

</details>