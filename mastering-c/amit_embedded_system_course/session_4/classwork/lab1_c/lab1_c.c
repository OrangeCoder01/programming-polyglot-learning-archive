#include <stdio.h>

int main(void)
{
    int salary = 0, work_time = 0; // hour per week

    printf("Please, enter your work hours per week: "); scanf("%d", &work_time);
    if(work_time >= 40)
    {
        salary = work_time * 50;
        printf("Your work hour is more than or equal to 40, salary is: {%d}", salary);
    }
    if(work_time < 40)
    {
        salary = (work_time * 50);
        int salary_after_deduction = 0.9 * salary;
        printf("Your work hour is less than 40, Your salary should be: {%d} but after deduction it is: {%d}", salary, salary_after_deduction);
    }

    return 0;
}