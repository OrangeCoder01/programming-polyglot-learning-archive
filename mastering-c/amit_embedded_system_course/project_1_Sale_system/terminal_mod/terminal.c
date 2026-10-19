#include <stdio.h>
#include <time.h>
#include "terminal.h"

u8 getTransactionDate(TerminalDataTempStoring *termData)
{
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    if(local == NULL) { return False; }
    strftime(termData->transaction_date, sizeof(termData->transaction_date), "%d/%m/%Y", local);
    return True;
}


u8 isCardExpired(CardDataTempStoring *cardData, TerminalDataTempStoring *termData)
{
    u32 card_month  = (cardData->card_expiratory_date[0] - '0') * 10 + (cardData->card_expiratory_date[1] - '0');
    u32 card_year   = (cardData->card_expiratory_date[3] - '0') * 10 + (cardData->card_expiratory_date[4] - '0');
    u32 trans_month = (termData->transaction_date[3] - '0') * 10 + (termData->transaction_date[4] - '0');
    u32 trans_year  = (termData->transaction_date[8] - '0') * 10 + (termData->transaction_date[9] - '0');

    if(trans_year > card_year) { return True; }
    if(trans_year == card_year && trans_month > card_month) { return True; }
    return False;
}


u8 getTransactionAmount(TerminalDataTempStoring *term_data)
{
    char input[100];
    f64 amount;

    printf("Enter transaction amount: ");
    if(fgets(input, sizeof(input), stdin) == NULL) { return False; }
    if(sscanf(input, "%lf", &amount) != 1) { return False; } /* it was not a number */
    if(!(amount > 0.0)) { return False; }  /* zero, negative (or nan [Not A Number]) */

    term_data->trans_amount = amount;
    return True;
}


u8 isBelowMaxAmount(TerminalDataTempStoring *term_data)
{
    if(term_data->trans_amount <= term_data->max_trans_amount) { return True; }
    return False;
}


u8 setMaxAmount(TerminalDataTempStoring *term_data, f64 maxAmount)
{
    if(maxAmount <= 0.0) { return False; }

    term_data->max_trans_amount = maxAmount;
    return True;
}
