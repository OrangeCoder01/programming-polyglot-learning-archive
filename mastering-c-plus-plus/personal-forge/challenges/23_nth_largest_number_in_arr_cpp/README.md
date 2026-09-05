# Nth largest number in array
## ${\color{orange}\text{Concept explanation}}$:
The program receives input:
```
    (1) number of elements.

    (2) each element's numerical integer value.

    (3) The "dense ranking" order.
```
<br>

It outputs:
```
    (1) The printing of Nth largest number.

    (2) If there is a duplicate, it prints the number of duplicates.
```
<br>

Rules: 
```
    (1) Maximum 10 elements and minimum of 1.

    (2) Values must be in range [-65535 ~ 65535].

    (3) Ranking includes duplicates.
```
<br>

For ${\color{pink}\text{example}}$:<br>
```
    Same array but different orders

    Number of elements = 10
    Elements' values = [2, -3, 0, 5, 4, 5, 5, -2, -1, 4]

    order = 1(st):    2(nd):      3(rd):        4(th):      5(th):      6(th):      7(th):
    Output: 5(3)      4(2)        2             0           -1          -2          -3
```



