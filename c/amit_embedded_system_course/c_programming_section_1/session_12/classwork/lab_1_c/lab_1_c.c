#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee { 
    int age; 
    char name[25]; 
}; 

struct employee store_func() 
{
    struct employee employee_obj;
    
    printf("Please, enter your name: "); scanf("%24s", employee_obj.name); 
    printf("Please, enter your age: "); scanf("%d", &employee_obj.age); 
    
    return employee_obj;
}

void print_func(struct employee employee_t) 
{
    printf("\nName: %s\n", employee_t.name);
    printf("Age: %d\n", employee_t.age);
}

int main(void) 
{
    struct employee Yassin = store_func();
    print_func(Yassin);
    return 0;
}
