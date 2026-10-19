#include <stdio.h>
#include "application.h"
#include "../card_mod/card.h"
#include "../terminal_mod/terminal.h"
#include "../server_mod/server.h"

u8 appInit(void) { return serverInit(); }

void appClose(void) { serverClose(); }

void appStart(void)
{
    /* Zero-initializing the structs directly replaces the need for memset */
    CardDataTempStoring     card = {0};
    TerminalDataTempStoring terminal = {0};
    BigDataStorage          transaction = {0};
    f64                     balance = 0.0;

    printf("\n========== NEW SALE TRANSACTION ==========\n");

    /* Card module */
    if(getCardHolderName(&card) == False) { printf("\nDECLINED: wrong card holder name\n"); return; }
    if(getCardExpiryDate(&card) == False) { printf("\nDECLINED: wrong expiry date\n"); return; }
    if(getCardPAN(&card) == False)        { printf("\nDECLINED: wrong PAN\n"); return; }

    /* Terminal module */
    setMaxAmount(&terminal, MAX_AMOUNT);

    if(getTransactionDate(&terminal) == False) { printf("\nDECLINED: could not read transaction date\n"); return; }
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
            printf("    Card   : ************%s\n", card.primary_account_number + 12);
            printf("    Amount : %.2f\n", terminal.trans_amount);
            printf("    Balance: %.2f\n", balance);
            break;
        }
        case DECLINED_INSUFFICIENT_FUND: { printf("\nDECLINED: insufficient funds\n"); break; }
        case DECLINED_INVALID_ACCOUNT:   { printf("\nDECLINED: invalid account\n"); break; }
        default:                         { printf("\nDECLINED: server error\n"); break; }
    }
}