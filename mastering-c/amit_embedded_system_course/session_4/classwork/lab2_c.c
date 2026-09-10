#include <stdio.h>
int main(void)
{
    int password = 12345, count_trial = 3, user_password = 0;

    do
    {
        printf("please, enter the password: "); scanf("%d", &user_password);
        if(user_password != password) 
        {
            count_trial -= 1;
            
            if(count_trial == 0)
            {
                 printf("There are no more trials left! exiting!");
                 break; 
            }
            
            printf("Input {%d} is an invalid password! You have {%d} trials left\n\n", user_password, count_trial);
        }

    }while(user_password != password);

    if(user_password == password) {printf("Correct the password is: %d", password);}
    return 0;
}