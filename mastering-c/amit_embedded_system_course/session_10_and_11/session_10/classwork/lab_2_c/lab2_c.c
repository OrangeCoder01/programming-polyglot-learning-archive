#include <stdio.h>

#define True 1
#define False 0

int find_lowest_grade(int arr[][4], int row, int column)/*Very important rule, the compiler requires to fill the second dimension array despite no real significance*/
{
    int lowest_grade = 0, i = 0;
    while(i < row)
    {
        static int counter = 0;
        if(counter == column)
        {
            i += 1; 
            counter = 0;
        }
        if(*(*(arr + i) + (int)(counter)) < lowest_grade) { lowest_grade = *(*(arr + i) + counter); }
        counter += 1;
    }
    return lowest_grade;
}

int main(void)
{
    int arr[3][4] = {0}, std_ord = 0;;

    while(True)
    {
        static int exam_ord = 0;
        if(exam_ord == 4) 
        {
            std_ord += 1; 
            exam_ord = 0;
        }
        if(std_ord == 3) { break; }
        printf("Please, enter the grade of student {%d} in exam {%d}: ", std_ord + 1,  exam_ord + 1); scanf(" %d", &arr[std_ord][exam_ord]);
        /*printf("arr[%d][%d] = %d\n", std_ord, exam_ord, arr[std_ord][exam_ord]);*/
        exam_ord += 1;
    }

    int lowest_grade = find_lowest_grade(arr, 3, 4);
    printf("\n\nThe lowest grade is: %d", lowest_grade);
    return 0;
}