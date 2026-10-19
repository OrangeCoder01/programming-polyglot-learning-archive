#include "application_mod/application.h"

int main(void)
{
    if(appInit() == 1)
    {
        appStart();
        appClose();
    }
    return 0;
}