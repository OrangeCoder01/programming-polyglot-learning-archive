#include <stdio.h>

typedef enum 
{ 

    Level1 = 1, /* Esscaping the automatic 0 assignment and staring from 1 */
    Level2, 
    Level3 
} fan_level;


int main(void)
{
    fan_level existing_fan_levels;
    int user_fan_level_choice = 0;
    printf("What fan level do you want (1, 2, 3): ");scanf(" %d", &user_fan_level_choice);
    if(user_fan_level_choice < 1 || user_fan_level_choice > 3) { printf("Sorry, that fan level does not exist:"); }
    else 
    {
        switch(user_fan_level_choice)
        {
            case Level1:
                {
                    printf("The fan is at %d", Level1);
                    break;
                }
            case Level2:
                {
                    printf("The fan is at %d", Level2);
                    break;
                }
            case Level3:
                {
                    printf("The fan is at %d", Level3);
                    break;
                }
            default:
                {
                    printf("Reading this line, indicates a failure in the program.");
                    break;
                }
        }
    }

    return 0;
}