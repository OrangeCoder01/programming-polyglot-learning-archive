# Code (1):
Explanation:
```
    The program prints an integer number from  1 to 10 using 
    function:
```
```c
        int static_counter(void);
```
````
    that contains a static variable "x"
    that gets iterated each time the function is called.
    and function:
````
```c
        int counter(void);
```
````
    Which does not contain a static variable, but an auto variable "x".
    Thus returning 1 whenever getting called in the for(){} loop. 
````
<br>

|Input:         |Output:        |
|---------------|---------------|
|None.          |(1) Counters (integer + text)|

<br>
<br>

Why building this program:
```
    Showcasing the practical difference between static and auto variable's in block scope.
```