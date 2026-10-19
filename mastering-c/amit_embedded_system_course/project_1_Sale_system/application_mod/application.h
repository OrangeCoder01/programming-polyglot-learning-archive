#ifndef APPLICATION_H
#define APPLICATION_H

#include "../toolkit/data/data_suite.h"

#define MAX_AMOUNT 20000.0 /* the most the terminal accepts in one transaction */

u8 appInit(void);
void appStart(void);   /* ONE complete SALE transaction */
void appClose(void);

#endif
