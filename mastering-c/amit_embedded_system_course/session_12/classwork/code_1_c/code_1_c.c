#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int age;
    int salary;
    char name[25];
};

int main(void)
{
    struct employee Ahmed;
    Ahmed.age = 23;
    Ahmed.salary = 2000;
    strcpy(Ahmed.name, "Ahmed");

    printf("Ahmed's struct:\nName: %s\nAge: %d\nSalary: %d\n", Ahmed.name, Ahmed.age, Ahmed.salary);

    return 0;
}