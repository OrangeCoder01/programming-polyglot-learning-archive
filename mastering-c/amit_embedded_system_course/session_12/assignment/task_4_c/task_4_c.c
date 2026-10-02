#include <stdio.h>

typedef char int8;

typedef struct
{
    int8 name[40];
    int8 grade;
    unsigned int id;
} Student;



void input_std_data(Student *std);
void process_std_data(Student arr[], int8 size);
void print_total_std_data(Student arr[], int8 size);



int main(void)
{
    int8 size = 0;

    printf("Please, enter the number of students: ");
    if (scanf(" %hhd", &size) != 1 || size <= 0) 
    {
        printf("Invalid input size.\n");
        return 1;
    }

    Student arr[size];

    process_std_data(arr, size);
    print_total_std_data(arr, size);

    return 0;
}




void input_std_data(Student *std)
{
    printf("Enter name (max 39 chars): "); scanf(" %39s", std->name);
    printf("Enter ID: "); scanf(" %u", &std->id);
    printf("Enter Grade: "); scanf(" %c", &std->grade);
}


void process_std_data(Student arr[], int8 size)
{
    for (int8 i = 0; i < size; i++)
    {
        printf("\n--- Data for Student {%d} ---\n", i + 1);
        input_std_data(arr + i);
    }
}



void print_total_std_data(Student arr[], int8 size)
{
    printf("\n=============================\n");
    printf("     TOTAL STUDENT DATA      \n");
    printf("=============================\n");

    for (int8 i = 0; i < size; i++)
    {
        printf("Student (%d):\n", i + 1);
        printf("\tName:  %s\n", (arr + i) -> name);
        printf("\tID:    %u\n", (arr + i) -> id);
        printf("\tGrade: %c\n\n", (arr + i) -> grade);
    }
}