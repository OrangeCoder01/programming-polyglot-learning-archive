# Grade System
## ${\color{orange}\text{Concept explanations}}$:
Explanation:
```
    The program manages input score of students by the user, process the data, and finally
    outputs the table of numbered students with their score, assigned grade, and finallt additional
    details from the analysis.
```

Input:
```
    (1) The number of students.

    (2) The score of each students.
```

Rules:
```
    (1) The Number of students can not exceed 100 or less than 0

    (2) The student's score can not exceed 100 or less than 0
```

Output:
```
    (1) Student data table:
        (1) Student number order.
        (2) Corresponding student's score.
        (3) Corrseponding assigned student's grade.
        (4) Student's academic status.
    
    (2) Critical statistics:
        (2.1) Highest and lowest Score students.
        (2.2) Average score from all students.
        (2.3) Number of passed/failed students.
        (2.4) Pass rate of students = ( ( Number of passed students ) / ( Total number of students ) * 100 ).
```

for ${\color{pink}\text{example}}$:
```
    Welcome to 'Grade System'
    You enter the number of students
    Then enter the score of each student

    The program will process each student's score
    Then it outputs the student's score, corresponding grade

    Rules:
    (1) The Number of students can not exceed 100
    (2) The student's score can not exceed 100


    Enter number of students: 20
    Enter the score for student {1}: 0.00
    Enter the score for student {2}: 84.45
    Enter the score for student {3}: 92.10
    Enter the score for student {4}: 71.30
    Enter the score for student {5}: 88.65
    Enter the score for student {6}: 95.40
    Enter the score for student {7}: 63.80
    Enter the score for student {8}: 79.15
    Enter the score for student {9}: 81.50
    Enter the score for student {10}: 100.00
    Enter the score for student {11}: 87.25
    Enter the score for student {12}: 55.40
    Enter the score for student {13}: 91.90
    Enter the score for student {14}: 76.80
    Enter the score for student {15}: 83.20
    Enter the score for student {16}: 68.75
    Enter the score for student {17}: 94.10
    Enter the score for student {18}: 77.35
    Enter the score for student {19}: 89.90
    Enter the score for student {20}: 80.20


    Student data table: 
    Name:		Score:	Grade:	Status:
    Student {1}:	0.00	F	Fail 
    Student {2}:	84.45	B	Pass
    Student {3}:	92.10	A	Pass
    Student {4}:	71.30	C	Pass
    Student {5}:	88.65	B	Pass
    Student {6}:	95.40	A	Pass
    Student {7}:	63.80	C	Pass
    Student {8}:	79.15	B	Pass
    Student {9}:	81.50	B	Pass
    Student {10}:	100.00	A	Pass
    Student {11}:	87.25	B	Pass
    Student {12}:	55.40	D	Pass
    Student {13}:	91.90	A	Pass
    Student {14}:	76.80	B	Pass
    Student {15}:	83.20	B	Pass
    Student {16}:	68.75	C	Pass
    Student {17}:	94.10	A	Pass
    Student {18}:	77.35	B	Pass
    Student {19}:	89.90	B	Pass
    Student {20}:	80.20	B	Pass


    Critical Statistics: 

    student {10} has the highest score: (100.00)
    student {1} has the lowest score: (0.00)
    Average Score: (77.06)
    Passed students: (19)
    Failed students: (1)
    Pass rate: (95.000%)
```


