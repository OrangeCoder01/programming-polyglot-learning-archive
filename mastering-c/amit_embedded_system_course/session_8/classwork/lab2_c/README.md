Explanation:
```
    The program removed an element selected by the user through refering to its index,
    deletes the index and the moves the elements ahead to occupy displaced index positions.
    For example:

        Array = [1, 2 ,3, 4, 5, 6]
        Indices: 0  1  2  3  4  5
        Remove index: 3:
        Algorithm:

            [1, 2, 3, 0, 5, 6]
            [1, 2, 3, 5, 0, 6]
            [1, 2, 3, 5, 6, 0] ---> Final result

```
<br>

|Input:         |Output:        |Rules:|
|---------------|---------------|-----------|
|(1) Array's size (integer).|(1) Printing the array with the removed index.|(1) The index must be between (0 ~ size of array -1).|
|(2) Elements' value (integer).||(2) Size of array must be between (0 ~ 100).|
|(3) Removed index (integer).||(3) The array's element value must be between (-60, 000 ~ 60, 000).|

<br>
<br>

Why building this program:
```
    Practising algorithmic thinking by solving a method for managing arrays 
    and its elements throught index manipulations.
```