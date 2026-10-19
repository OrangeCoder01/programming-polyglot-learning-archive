#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "../toolkit/data/database.h"
#include "../toolkit/lib/linked_list/linkedlist_c.h"

#define MAX_TRANSACTIONS 255

static Client *accounts = NULL;                          /* the bank's accounts (linked list from the toolkit) */
static ST_transaction_t transactions[MAX_TRANSACTIONS];  /* the bank's transactions (array) */
static u32 transactions_count = 0;


static Client *FindAccount(ST_cardData_t *cardData)
{
    Client *account = FindAccountByPAN(accounts, strtoull(cardData->primaryAccountNumber, NULL, 10));

    if(account == NULL) { return NULL; }
    if(strcmp(cardData->cardHolderName, (char *) account->card_name_holder) != 0) { return NULL; }
    if(strcmp(cardData->cardExpirationDate, (char *) account->expiry_date) != 0) { return NULL; }
    return account;
}


u8 serverInit(void)
{
    accounts = CreateInitialDatabase();
    if(accounts == NULL) { return False; }
    return True;
}


void serverClose(void)
{
    FreeDatabase(accounts);
    accounts = NULL;
}


u8 isValidAccount(ST_cardData_t *cardData)
{
    if(FindAccount(cardData) == NULL) { return False; }
    return True;
}


u8 isAmountAvailable(ST_terminalData_t *termData, ST_cardData_t *cardData)
{
    Client *account = FindAccount(cardData);

    if(account == NULL) { return False; }
    if(account->balance >= termData->transAmount) { return True; }
    return False;
}


u8 saveTransaction(ST_transaction_t *transData)
{
    if(transactions_count >= MAX_TRANSACTIONS) { return False; } /* the array is full */

    transactions_count += 1;
    transData->transactionSequenceNumber = transactions_count;
    transactions[transactions_count - 1] = *transData;
    return True;
}


u8 getAccountBalance(ST_cardData_t *cardData, f64 *balance)
{
    Client *account = FindAccount(cardData);

    if(account == NULL) { return False; }
    *balance = account->balance;
    return True;
}


EN_transState_t receiveTransactionData(ST_transaction_t *transData)
{
    Client *account;

    if(isValidAccount(&transData->cardHolderData) == False)
    {
        transData->transState = DECLINED_INVALID_ACCOUNT;
        return DECLINED_INVALID_ACCOUNT;
    }

    if(isAmountAvailable(&transData->terminalData, &transData->cardHolderData) == False)
    {
        transData->transState = DECLINED_INSUFFICIENT_FUND;
        return DECLINED_INSUFFICIENT_FUND;
    }

    account = FindAccount(&transData->cardHolderData);
    account->balance -= transData->terminalData.transAmount;

    transData->transState = APPROVED;
    if(saveTransaction(transData) == False)
    {
        account->balance += transData->terminalData.transAmount;
        transData->transState = INTERNAL_SERVER_ERROR;
        return INTERNAL_SERVER_ERROR;
    }

    return APPROVED;
}
