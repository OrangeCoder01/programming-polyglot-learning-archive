#include <stdio.h>
#include <string.h>

typedef union { char first_name[30], last_name[30]; } family_name; 


int main(void)
{
    family_name fn;
    
    family_name *ptr = &fn;
    
    printf("Please, enter your first name: "); scanf(" %29s", ptr->first_name);
    printf("Your last name is: %s", ptr->last_name);printf(", the size of the union: %zu", sizeof(family_name));
    return 0;
}