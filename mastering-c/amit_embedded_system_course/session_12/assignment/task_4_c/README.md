# Task 4:
**Question**:
````
    (4) C Function to store information (name, id and grade) for 10
        students in array of structures using pointers and another
        function to print all the structures using pointers.
````
**Explanation**:
````
    Using array of struct can be perplexing but its implementation is simple, instead of naming
    each object "Student std_1", one can declare an array with struct "Student" datatype
    and the index can act the student number:

    arr[]
            +---------------+---------------+---------------+---------------+-------------    ---  -- ---  -  ------+---------------+
            |               |               |               |               |                                       |               |
            |    arr + 0    |   arr + 1     |   arr + 2     |   arr + 3     |      ...          ...         ....    |  arr + N      |
            |               |               |               |               |                                       |               |
            +---------------+---------------+---------------+---------------+-------------     --- ---    ----     -+---------------+
            |               |               |               |               |                                       |               |
            |   Student 0   |   Student 1   |  Student 2    |   Student 3   |  ....         ....            ....    |  Student N    |
            |name,grade,id  | name,grade,id | name,grade,id |name,grade,id  |name,grade,id                          | name,grade,id |
            +---------------+---------------+---------------+---------------+-------------  --    -- -d ---   - -- --+---------------+ 

    To process od of the student N in a function
        (arr + N) -> id  = 404
````
<br>

|${\color{blue}\text{Input}}$:|${\color{red}\text{Output}}$:|${\color{orange}\text{Rule}}$:|
|:---|:---|:----|
|(1) **Name** (string in char array)|(1) Printing the **collected data of students** (integer, string, text)|(1) The **max** name's **characters** is **39**|
(2) **ID** (integer)||||
(3) **Grade** (char)||||

<br>

**Why** building this program:
````
    Implementing data storage using a struct-declared array holding struct object called as a parameter in
    a void-return type function(pass by reference).
````