# Palindrome array
## ${\color{orange}\text{Concept explanation}}$:
Explanation:
```
    The program reads elements' values inserted by the user and process if the choronological placement of the
    elements in the array place in congruence with its reversed form: in case it is true; the array is palindrome, otherwise
    it is not a palindrome.
```
The program receives input:
```
    (1) number of elements.

    (2) each element's numerical integer value.
```
<br>

It outputs:
```
    (1) printing whether the array is a palindrome or not.
```
<br>

Rules: 
```
    (1) Maximum 10 elements and minimum of 1.

    (2) Values must be in range [-65535 ~ 65535].

```
<br>

For ${\color{pink}\text{example}}$:<br>
```
    Number of elements = 5
    Values = [-3, 2, 10, 0, 3]
    reversed array = [3, 0, 10, 2, -3]
    Output: This is not a palindrome array.
```
<br>

Another ${\color{pink}\text{example}}$:<br>
```
    Number of elements = 7
    Values = [1, -2, 3, -4, 3, -2, 1]
    reversed array = [1, -2, 3, -4, 3, -2, 1]
    Output: This is a palindrome array.
```