#include <stdio.h>
#include "sale_system.h"

int main(void)
{
    char answer[10];

    if(appInit() == False)
    {
        printf("The bank server could not start.\n");
        return 1;
    }

    do
    {
        appStart();

        printf("\nAnother transaction? (y/n): ");
        if(fgets(answer, sizeof(answer), stdin) == NULL) { break; }
    } while(answer[0] == 'y' || answer[0] == 'Y');

    appClose();
    return 0;
}
