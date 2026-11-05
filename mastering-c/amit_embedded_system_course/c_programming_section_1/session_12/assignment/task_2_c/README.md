# Task 2:
Question:
````
    (2) C function to add two complex numbers by passing two
        structure to a function and display the results.

````
Explanation:
````
    Using pointers and the arrow operators to point struct objects 
    to access the real and imaginary parts of the "complex" struct:
````
```c
        complex c_1; /* "c_1" is now an object from struct "complex" */
        complex *ptr = &c_1 /* This means that "ptr" is a pointer dedicated only to struct "complex", currently pointing at the "c_1" object */
        float val = ptr -> real /* That means fetch (dereference) "ptr" and bring "real" field variable (which is inside c_1) */
        /* same as: */float val_2 = (*ptr).real;
```
````
    The pointer methodology optimized the processing speed.

    There are two void-type functions: one receives input struct complex's real and imaginary operands and the
    sum is inserted into the "sum_c"'s fields.

    The other one is printing the data operation.

````
<br>

|Input:|Output:|
|:----|:----|
|(1) Real and imaginary number (float)|(1) Printing the operation, operands, and the result (float + text)|


<br>

Why building this program:
````
    Implementing pointer methodology in handling struct objects
    + using arrow operator.
````