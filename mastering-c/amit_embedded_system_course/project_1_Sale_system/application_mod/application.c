#include <stdio.h>
#include <string.h>
#include "application.h"
#include "../card_mod/card.h"
#include "../terminal_mod/terminal.h"
#include "../server_mod/server.h"

u8 appInit(void) { return serverInit(); }

void appClose(void) { serverClose(); }


void appStart(void)
{
    CardDataTempStoring     card;
    TerminalDataTempStoring terminal;
    BigDataStorage  transaction;
    f64               balance = 0.0;

    memset(&card, 0, sizeof(card));
    memset(&terminal, 0, sizeof(terminal));
    memset(&transaction, 0, sizeof(transaction));

    printf("\n========== NEW SALE TRANSACTION ==========\n");

    /* Card module */
    if(getCardHolderName(&card) == False) { printf("\nDECLINED: wrong card holder name\n"); return; }
    if(getCardExpiryDate(&card) == False) { printf("\nDECLINED: wrong expiry date\n"); return; }
    if(getCardPAN(&card) == False)        { printf("\nDECLINED: wrong PAN\n"); return; }

    /* Terminal module */
    setMaxAmount(&terminal, MAX_AMOUNT);

    getTransactionDate(&terminal);
    printf("Transaction date: %s\n", terminal.transaction_date);

    if(isCardExpired(&card, &terminal) == True) { printf("\nDECLINED: expired card\n"); return; }

    if(getTransactionAmount(&terminal) == False) { printf("\nDECLINED: wrong amount\n"); return; }
    if(isBelowMaxAmount(&terminal) == False)     { printf("\nDECLINED: amount exceeds the maximum limit\n"); return; }

    /* Server module */
    transaction.card_holder_data = card;
    transaction.terminal_data   = terminal;

    switch(receiveTransactionData(&transaction))
    {
        case APPROVED:
        {
            getAccountBalance(&card, &balance);
            printf("\nAPPROVED\n");
            printf("    Card   : ************%s\n", card.primary_account_number + 12); /* only the last 4 digits */
            printf("    Amount : %.2f\n", terminal.trans_amount);
            printf("    Balance: %.2f\n", balance);
            break;
        }
        case DECLINED_INSUFFICIENT_FUND: { printf("\nDECLINED: insufficient funds\n"); break; }
        case DECLINED_INVALID_ACCOUNT:   { printf("\nDECLINED: invalid account\n"); break; }
        default:                         { printf("\nDECLINED: server error\n"); break; }
    }
}
