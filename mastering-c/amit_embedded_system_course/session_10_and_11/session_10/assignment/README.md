# Assignment session (10):
Implemented
````
    (1) Pointers:
        (1.1) Pointer's array arithmetics.

    (2) Null terminator in char array ('\0').

    (3) Why learn:
        (3.1) Pointers:

            It is very helpful in managing large set of data without the
            extra processing of copy-pasting the value of an address of a stored variable
            inside a memory in RAM.

            Whereas there is no need to copy-paste the memory of an array inside the
            function stack frame, as the pointer resolve this extra processing power,
            by pointing towards each of the array's element's address.
        

        (3.2) Null terminator:

            It is the edge limiter in char array, which helps in detecting the end of the
            string input.
            For example:
````
```c
                #include <stdio.h>
                int main(void)
                {
                    char name[18] = {'H','E','L','L','O',' ','W','O','R','L','D','!','\0','e','d','_','>','@'};
                    int i = 0;                                                     /* >< */
                    printf("name: ");
                    while(*(name + i) != '\0')
                    {
                        printf("%c", *(name+ i));
                        i += 1;
                    }
                    /* The final print: HELLO WORLD! */
                    return 0;
                }
```
<br>
Programs & links:
<br>

&emsp;`(1) Assignment:`<br>

&emsp;&emsp; `(1.1) Calculating the sum of elements in an array using pointers`: [task_1_c](https://github.com/OrangeCoder01/programming-polyglot-learning-archive/tree/main/mastering-c/amit_embedded_system_course/session_10_and_11/session_10/assignment/task_1_c) <br> 

&emsp;&emsp; `(1.2) Calculating the number of characters of a char array with input first name using Null terminator ('\0') edge limit`: [task_2_c](https://github.com/OrangeCoder01/programming-polyglot-learning-archive/tree/main/mastering-c/amit_embedded_system_course/session_10_and_11/session_10/assignment/task_2_c) <br> 

&emsp;&emsp; `(1.3) Reversing an array using pointer arithmetics `: [task_3_c](https://github.com/OrangeCoder01/programming-polyglot-learning-archive/tree/main/mastering-c/amit_embedded_system_course/session_10_and_11/session_10/assignment/task_3_c) <br> 

&emsp;&emsp; `(1.4) Searching the smallest value element in an array using pointers`: [task_4_c](https://github.com/OrangeCoder01/programming-polyglot-learning-archive/tree/main/mastering-c/amit_embedded_system_course/session_10_and_11/session_10/assignment/task_4_c) <br> 

&emsp;&emsp; `(1.5) Copying one array's elements and pasting into the other`: [task_5_c](https://github.com/OrangeCoder01/programming-polyglot-learning-archive/tree/main/mastering-c/amit_embedded_system_course/session_10_and_11/session_10/assignment/task_5_c) <br> 

&emsp;&emsp; `(1.6) Swapping the elements of two arrays`: [task_6_c](https://github.com/OrangeCoder01/programming-polyglot-learning-archive/tree/main/mastering-c/amit_embedded_system_course/session_10_and_11/session_10/assignment/task_6_c) <br> 

&emsp;&emsp; `(1.7) Selectively extracting the first and last characters of a char array with input string`: [task_7_c](https://github.com/OrangeCoder01/programming-polyglot-learning-archive/tree/main/mastering-c/amit_embedded_system_course/session_10_and_11/session_10/assignment/task_7_c) <br> 

