# Task 1:
Question:
````
    (1) C Program to store information (name, roll and marks) for a
        student using structure and display it.
````
Explanation:
````
    There are two void-return type functions: one that enables the user to input values into the data of "student_t"
    object from Struct "Student", and the second one prints the concurrent data inside student_t.
````
```c
        /* The run-time variables (1) */
        char std_name[40];
        int roll = 0;
        float mark = 0.0f;
```
````
    using the address of each one of these data
    in order to pass the value by reference.
````
```c    
        /* The struct database (2) */
        typedef struct
        {
            int roll_level;
            float mark;
            char name[40];
        }Student;
```
```c
        /* The data insertion function (3) */
        void insert_std_data(int*std_roll, float*std_mark, char std_name[])
        {
            Student student_t;
        
            printf("Please, insert student's name (max 40 characters): ");scanf("%39s", student_t.name );
            printf("Please, insert the roll level: "); scanf(" %d", &student_t.roll_level);
            printf("Please, insert the mark: ");scanf(" %f", &student_t.mark);
```
```c
            /* Copying struct's data into the addressable variable (4) */
            *std_mark = student_t.mark;
            *std_roll = student_t.roll_level;

            int i = 0;
            while(student_t.name[i] != 0)
            {
                std_name[i] = student_t.name[i];
                i += 1;
            }
            std_name[i] = '\0';
        }
```
```c
        /* Printing the data  (5) */
        void print_std_data(int*std_roll_ptr, float*srd_mark_ptr, char std_name[])
        {
            printf("Student's Information: \n\n");
            printf("Name: %s\n", std_name);
            printf("Roll level: %d\n", *std_roll_ptr);
            printf("Mark: %.2f\n", *srd_mark_ptr);
        }
```
<br>

|Input:|Output:|Rule:|
|:---|:---|:----|
|(1) Enrollment level (integer)|(1) The student's data (struct)|(1) name must contain less than 40 characters.|
(2) Mark (float)
(3) Student's name (char array)


<br>

Why building this program:
````
    Implementing struct data and using pointers to retrieve data without 
    excessive processing.
````