#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "../toolkit/data/database.h"
#include "../toolkit/lib/linked_list/linkedlist_c.h"

#define MAX_TRANSACTIONS 255

static Client *accounts = NULL;                          /* the bank's accounts (linked list from the toolkit) */
static BigDataStorage transactions[MAX_TRANSACTIONS];  /* the bank's transactions (array) */
static u32 transactions_count = 0;


static Client *FindAccount(CardDataTempStoring *cardData)
{
    Client *account = FindAccountByPAN(accounts, strtoull(cardData->primary_account_number, NULL, 10));

    if(account == NULL) { return NULL; }
    if(strcmp(cardData->card_holder_name, (char *) account->card_name_holder) != 0) { return NULL; }
    if(strcmp(cardData->card_expiratory_date, (char *) account->expiry_date) != 0) { return NULL; }
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


u8 isValidAccount(CardDataTempStoring *cardData)
{
    if(FindAccount(cardData) == NULL) { return False; }
    return True;
}


u8 isAmountAvailable(TerminalDataTempStoring *termData, CardDataTempStoring *cardData)
{
    Client *account = FindAccount(cardData);

    if(account == NULL) { return False; }
    if(account->balance >= termData->trans_amount) { return True; }
    return False;
}


u8 saveTransaction(BigDataStorage *trans_data)
{
    if(transactions_count >= MAX_TRANSACTIONS) { return False; } /* the array is full */

    transactions_count += 1;
    trans_data->transaction_sequence_number = transactions_count;
    transactions[transactions_count - 1] = *trans_data;
    return True;
}


u8 getAccountBalance(CardDataTempStoring *cardData, f64 *balance)
{
    Client *account = FindAccount(cardData);

    if(account == NULL) { return False; }
    *balance = account->balance;
    return True;
}


EnumTransState receiveTransactionData(BigDataStorage *trans_data)
{
    Client *account;

    if(isValidAccount(&trans_data->card_holder_data) == False)
    {
        trans_data->trans_state = DECLINED_INVALID_ACCOUNT;
        return DECLINED_INVALID_ACCOUNT;
    }

    if(isAmountAvailable(&trans_data->terminal_data, &trans_data->card_holder_data) == False)
    {
        trans_data->trans_state = DECLINED_INSUFFICIENT_FUND;
        return DECLINED_INSUFFICIENT_FUND;
    }

    account = FindAccount(&trans_data->card_holder_data);
    account->balance -= trans_data->terminal_data.trans_amount;

    trans_data->trans_state = APPROVED;
    if(saveTransaction(trans_data) == False)
    {
        account->balance += trans_data->terminal_data.trans_amount;
        trans_data->trans_state = INTERNAL_SERVER_ERROR;
        return INTERNAL_SERVER_ERROR;
    }

    return APPROVED;
}
