#include <stdio.h>

typedef struct
{
    int roll_level;
    float mark;
    char name[40];
}Student;


void insert_std_data(int*std_roll, float*std_mark, char std_name[])
{
    Student student_t;

    printf("Please, insert student's name (max 40 characters): ");scanf("%39s", student_t.name );
    printf("Please, insert the roll level: "); scanf(" %d", &student_t.roll_level);
    printf("Please, insert the mark: ");scanf(" %f", &student_t.mark);

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

void print_std_data(int*std_roll_ptr, float*srd_mark_ptr, char std_name[])
{
    printf("Student's Information: \n\n");
    printf("Name: %s\n", std_name);
    printf("Roll level: %d\n", *std_roll_ptr);
    printf("Mark: %.2f\n", *srd_mark_ptr);
}

int main(void)
{
    char std_name[40];
    int roll = 0;
    float mark = 0.0f;

    insert_std_data(&roll, &mark, std_name);
    print_std_data(&roll, &mark, std_name);


    return 0;
}