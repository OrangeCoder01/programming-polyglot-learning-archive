# Question 1:
Question:
```
    Why the output of a char array as string cut off the space?
```

Code:
```
    #include <stdio.h>
    int main(void)
    {
        char name[100];

        printf("Please, enter your name: "); scanf(" %s", name); /* Let it be "Tchiencko Zumachi "*/
        printf("Your input name: %s", name);
        return 0;
    }
```

Input:
```
    "Tchiencko Zumachi"
```

Output
```
    Please, enter your name: Tchiencko Zumachi
    Your input name: Tchiencko
```


Answer:
```
    The issue is located at how "scanf()" function functions, "scanf()" proceeds storing the characters
    until reaching the space ' ', on where the "scanf()" stop at and sets the null terminator '\0'
    at its corresonding buffer index.

    "scanf()" function is designed to deal with spaces as word seperator, and its purpose to retrieve words not sentences.
```
Why is this question important:
```
    It reflects a flaw with function "scanf()" from <stdio.h> library, as it 
    is not optimized for long strings.
```
