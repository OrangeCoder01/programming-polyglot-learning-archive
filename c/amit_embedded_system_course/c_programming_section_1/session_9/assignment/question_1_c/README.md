# Question (1):
Question:
````
    (1) What is "Flip-linking"?
````
Explanation:
````
    In C programming, flip-linking (flipping linkage) refers to changing a global variable or function's linkage between
    Internal and External linkage:

   Internal Linkage (Flipped using static):

        Restricts the global symbol's visibility strictly to its current source file, 
        preventing other files from accessing it via extern.

    External Linkage (Default / accessed via extern):

        Exposes the global symbol so it can be referenced and shared across multiple source (.c) files. 
    For example:  
````
```c
        /* fileA.c */
        int public_counter = 100; /* External Linkage by default: accessible across translation units */
        static int private_sensor_state = 0; /* Flipped to Internal Linkage using 'static': restricted ONLY to fileA.c */
        static void reset_sensor(void) /* Flipped to Internal Linkage: cannot be called outside fileA.c */
        {
            private_sensor_state = 0;
        }

        void update_system(void) 
        {
            private_sensor_state++;
            if (private_sensor_state > 10) 
            {
                reset_sensor();
            }
        }
```
```c
        #include <stdio.h>

        /* Accessing symbol with External Linkage from fileA.c */
        extern int public_counter;

        /* THIS CAUSES A LINKER ERROR: 'private_sensor_state' has internal linkage in fileA.c and is hidden here. */
        /*    
        extern int private_sensor_state;
        */ 

        int main(void) 
        {
            public_counter += 50; /* Valid: Modifies public_counter in fileA.c */
            printf("Public Counter: %d\n", public_counter);
            return 0;
        }
```
Why is it important to know the answer to this question:
````
    Prevents the possible error of name collision in a modular project, where many source files and header might share the
    same variable's name.
````