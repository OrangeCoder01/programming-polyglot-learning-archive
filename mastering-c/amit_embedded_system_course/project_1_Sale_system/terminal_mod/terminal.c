#include <stdio.h>
#include <string.h>
#include "terminal.h"

u8 getTransactionDate(TerminalDataTempStoring *termData)
{
    strcpy(termData->transaction_date, "15/10/2026"); /* The date I started building this project */
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
    f64 amount;

    printf("Enter transaction amount: ");
    if(scanf("%lf", &amount) != 1) { return False; }
    if(!(amount > 0.0)) { return False; }

    term_data->trans_amount = amount;
    return True;
}

u8 isBelowMaxAmount(TerminalDataTempStoring *term_data)
{
    return (term_data->trans_amount <= term_data->max_trans_amount) ? True : False;
}

u8 setMaxAmount(TerminalDataTempStoring *term_data, f64 maxAmount)
{
    if(maxAmount <= 0.0) { return False; }
    term_data->max_trans_amount = maxAmount;
    return True;
}