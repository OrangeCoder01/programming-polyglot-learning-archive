# Code (3):
Explanation:
```
    Applying the bubble sort algorithm that sorts an array.
    Let an array = [ -1, -3, 3, -2, 1, 2, 0 ]
    Visualization:
        i = 0:

            j = 0: [ -3, -1, 3, -2, 1, 2, 0 ]
            j = 1: [ -3, -1, 3, -2, 1, 2, 0 ]
            j = 2: [ -3, -1, -2, 3, 1, 2, 0 ]
            j = 3: [ -3, -1, -2, 1, 3, 2, 0 ]
            j = 4: [ -3, -1, -2, 1, 2, 3, 0 ]
            j = 5: [ -3, -1, -2, 1, 2, 0, 3 ]

        i = 1:

            j = 0: [ -3, -2, -1, 1, 2, 0, 3 ]
            j = 1: [ -3, -2, -1, 1, 2, 0, 3 ]
            j = 2: [ -3, -2, -1, 1, 2, 0, 3 ]
            j = 3: [ -3, -2, -1, 1, 0, 2, 3 ]
            j = 4: [ -3, -2, -1, 1, 0, 2, 3 ]

        
        i = 2:
            j = 0: [ -3, -2, -1, 1, 0, 2, 3 ]
            j = 1: [ -3, -2, -1, 0, 1, 2, 3 ]
            j = 2: [ -3, -2, -1, 0, 1, 2, 3 ]
            j = 3: [ -3, -2, -1, 0, 1, 2, 3 ]


        i = 3:
            j = 0: [ -3, -2, -1, 0, 1, 2, 3 ]
            j = 1: [ -3, -2, -1, 0, 1, 2, 3 ]
            j = 2: [ -3, -2, -1, 0, 1, 2, 3 ]


        i = 4:
            j = 0: [ -3, -2, -1, 0, 1, 2, 3 ]
            j = 1: [ -3, -2, -1, 0, 1, 2, 3 ]


        i = 5:
            j = 0: [ -3, -2, -1, 0, 1, 2, 3 ]

```
<br>

|Input:         |Output:        |
|---------------|---------------|
| None.         | None.         |

<br>
<br>

Why building this program:
```
    Understanding the first sorting algorithm method in sorting and 
    comprhending how the bubble sort is not an efficient sorting algorithm 
    in with respect to "Time complexity".
```