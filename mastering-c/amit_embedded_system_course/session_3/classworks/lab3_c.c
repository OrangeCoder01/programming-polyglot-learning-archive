#include <stdio.h>

int main(void)
{
    int student_score = 0;
    char grade = 'A';

    printf("Please, enter your academic score between 0 and 100: "); scanf("%d", &student_score);

    if(90 <= student_score && student_score <= 100) {grade = 'A';}
    else if(80 <= student_score && student_score <= 90) {grade = 'B';}        
    else if(70 <= student_score && student_score <= 80) {grade = 'C';}
    else if(60 <= student_score && student_score <= 70) {grade = 'D';}
    else if(0 <= student_score && student_score < 60) {grade = 'F';}
    else {printf("score is out of boundary");}
    
    if(0 <= student_score && student_score <= 100) {printf("Your score: {%d} and its corresponding grade {%c}", student_score, grade);}

    return 0;
}
