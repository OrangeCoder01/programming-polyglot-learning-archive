# Task 5:
**Question**:
````
    (5) Create Union type called family_name it shall have two
        members first_name and last_name. 
        
        The two members are array of characters with same size 30. 
        
        Try to write string in the
        first member first_name then print the second member
        last_name plus print the size of the union.
````
**Explanation**:
````
    Demonstating that the union user-defined datatype applies the highest size field variable
    as the standard plus all the field variables share the same memory, meaning overwritting
    a member field by assigning it nowhere in code, inherently overwritting the other member fields.
````
<br>


|${\color{blue}\text{Input}}$: |${\color{red}\text{Output}}$: |
|:---|:---|
|(1) **First name** (string in char array)| (1) **Last name** (string in char array + text)|
|                                         |(2) **Size** of the "family_name" **union**|


<br>

**Why** building this program:
````
    Implementing union and understanding its limitations.
````