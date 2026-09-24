# Lab (2):
For ${\color{green}\text{Windows}}$ only!<br>
```
In order to run properly, must open "integrated termminal environments" of the target code file, in this case: "main_c.c"
run in the command:

    gcc main_c.c calc_c.c           (in main_c.c terminal)

        or
    
    gcc main_2_c.c                  (in main_2_c.c terminal)

Then:

    .\a.exe

    (Or the exectutable file inside the folder where the code files are in (in here it is "lab1"))
```
Explanation:
```
    There are two programs:
        First (named as: " main_c.c "):

            It is a simple calculator that does operation: addition, subtraction, multiplication, division, and modulus.

        Second (named as" " main_2_c.c "):     

            A program that implements the mathematical operation: "factorical", using the function recursion method.
     
```
Input:
```
    For "main_c.c":
        (1) 2 operands (integers).
        (2) 1 mathematical character operator (char).
    
    For "main_2_c.c":
        None.
```
Output:
```
    For "main_c.c":
        (1) The printing of the operation and its result if there are no division, modulus with zero or inserting an invalid
            operator (integers + char).

        (2) The printing of warnings if the user inserted an illegal input (text).
    
    For "main_2_c.c":
        (1) The result from factorial.
```
Why building these programs:
```
    For implementing the function recursion and using modular coding style in the calculator
    code file.
```