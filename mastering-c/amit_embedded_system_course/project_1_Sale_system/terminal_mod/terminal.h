#ifndef TERMINAL_H
#define TERMINAL_H

#include "../toolkit/data/data_suite.h"
#include "../card_mod/card.h"

typedef struct
{
    f64  transAmount;
    f64  maxTransAmount;
    char transactionDate[11]; /* DD/MM/YYYY + '\0' */
} ST_terminalData_t;

u8 getTransactionDate(ST_terminalData_t *termData);                              /* takes the date from the PC clock */
u8 isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);          /* True = the card IS expired */
u8 getTransactionAmount(ST_terminalData_t *termData);                            /* True = valid amount typed */
u8 isBelowMaxAmount(ST_terminalData_t *termData);                                /* True = amount is within the limit */
u8 setMaxAmount(ST_terminalData_t *termData, f64 maxAmount);                     /* True = limit was set */

#endif
