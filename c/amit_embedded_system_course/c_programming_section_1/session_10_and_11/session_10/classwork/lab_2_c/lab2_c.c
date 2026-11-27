#include <stdio.h>

int find_lowest_grade(int arr[][4], int row, int column)
{
    int lowest_grade = arr[0][0]; 
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] < lowest_grade)
            {
                lowest_grade = arr[i][j];
            }
        }
    }
    return lowest_grade;
}

int main(void)
{
    int arr[3][4] = {0};

    for (int std_ord = 0; std_ord < 3; std_ord++)
    {
        for (int exam_ord = 0; exam_ord < 4; exam_ord++)
        {
            printf("Please, enter the grade of student {%d} in exam {%d}: ", std_ord + 1, exam_ord + 1);
            scanf("%d", &arr[std_ord][exam_ord]);
        }
    }

    int lowest_grade = find_lowest_grade(arr, 3, 4);
    printf("\n\nThe lowest grade is: %d\n", lowest_grade);
    
    return 0;
}
