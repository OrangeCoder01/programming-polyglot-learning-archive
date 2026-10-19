#ifndef TERMINAL_H
#define TERMINAL_H

#include "../toolkit/data/data_suite.h"
#include "../card_mod/card.h"

typedef struct
{
    f64  trans_amount;
    f64  max_trans_amount;
    char transaction_date[11]; /* DD/MM/YYYY + '\0' */
} TerminalDataTempStoring;


u8 getTransactionDate(TerminalDataTempStoring *term_data);                                     /* takes the date from the PC clock */
u8 isCardExpired(CardDataTempStoring *card_data, TerminalDataTempStoring *term_data);          /* True = the card IS expired */
u8 getTransactionAmount(TerminalDataTempStoring *term_data);                                   /* True = valid amount typed */
u8 isBelowMaxAmount(TerminalDataTempStoring *term_data);                                       /* True = amount is within the limit */
u8 setMaxAmount(TerminalDataTempStoring *term_data, f64 max_amount);                           /* True = limit was set */

#endif
