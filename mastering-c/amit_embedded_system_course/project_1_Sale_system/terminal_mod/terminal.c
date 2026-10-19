#include <stdio.h>
#include <string.h>
#include <time.h>
#include "terminal.h"

u8 getTransactionDate(ST_terminalData_t *termData)
{
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    if(local == NULL) { return False; }
    strftime(termData->transactionDate, sizeof(termData->transactionDate), "%d/%m/%Y", local);
    return True;
}


u8 isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
    u32 card_month  = (cardData->cardExpirationDate[0] - '0') * 10 + (cardData->cardExpirationDate[1] - '0');
    u32 card_year   = (cardData->cardExpirationDate[3] - '0') * 10 + (cardData->cardExpirationDate[4] - '0');
    u32 trans_month = (termData->transactionDate[3] - '0') * 10 + (termData->transactionDate[4] - '0');
    u32 trans_year  = (termData->transactionDate[8] - '0') * 10 + (termData->transactionDate[9] - '0');

    if(trans_year > card_year) { return True; }
    if(trans_year == card_year && trans_month > card_month) { return True; }
    return False;
}


u8 getTransactionAmount(ST_terminalData_t *termData)
{
    char input[100];
    f64 amount;

    printf("Enter transaction amount: ");
    if(fgets(input, sizeof(input), stdin) == NULL) { return False; }
    if(sscanf(input, "%lf", &amount) != 1) { return False; } /* it was not a number */
    if(!(amount > 0.0)) { return False; }  /* zero, negative (or nan [Not A Number]) */

    termData->transAmount = amount;
    return True;
}


u8 isBelowMaxAmount(ST_terminalData_t *termData)
{
    if(termData->transAmount <= termData->maxTransAmount) { return True; }
    return False;
}


u8 setMaxAmount(ST_terminalData_t *termData, f64 maxAmount)
{
    if(maxAmount <= 0.0) { return False; }

    termData->maxTransAmount = maxAmount;
    return True;
}
