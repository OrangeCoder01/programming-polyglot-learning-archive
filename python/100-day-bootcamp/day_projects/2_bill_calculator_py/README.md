# Bill Calculator:
<details>
<summary><b> What is Bill Calculator: </b></summary>
The project is used for people in a social space such as a cafe` and they would split the bill of a service or a product.

</details>


<details>
<summary><b> How is Bill Calculator built: </b></summary>

There are three variable:
-  `bill`: cost of service/product.
-  `tip_percentage`: Extra money given to the service provider and is a percentage from the bill.
-   `num_of_individuals`: Number of individuals.

The output is the bill for each person:
```python
    bill_per_individual = (float(bill) + (float(tip_percentage)/100)*float(bill))/(int(num_of_individuals))
    print(f"Each person should pay: ${round(bill_per_individual, 2)}")
```

<details>
<summary><b> Input/Output Table: </b></summary>
<br>

|${\color{blue}\text{Input}}$: | ${\color{red}\text{Output}}$:| 
|:---|:---|
|(1) **Bill**, **tip percentage**, and **number of individuals** (`float`)| (2) The **bill per person** (`float`)|
</details>
</details>


<details>

<summary><b> Why build Bill Calculator: </b></summary>
<br>

Implementing:
- Data type casting.
- `round` built-in function.
</details>