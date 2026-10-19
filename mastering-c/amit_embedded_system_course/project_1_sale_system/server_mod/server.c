#include <stdlib.h>
#include "server.h"
#include "../toolkit/data/database.h"
#include "../toolkit/lib/linked_list/linkedlist_c.h"

#define MAX_TRANSACTIONS 255

static Client *accounts = NULL;
static BigDataStorage transactions[MAX_TRANSACTIONS];
static u32 transactions_count = 0;

static Client *FindAccount(CardDataTempStoring *cardData)
{
    Client *account;
    u64 pan_val = 0;
    u32 i = 0;
    u8 match_name = True;
    u8 match_date = True;

    while(cardData->primary_account_number[i] != '\0')
    {
        pan_val = pan_val * 10 + (cardData->primary_account_number[i] - '0');
        i++;
    }

    account = FindAccountByPAN(accounts, pan_val);
    if(account == NULL) { return NULL; }

    i = 0;
    while(cardData->card_holder_name[i] != '\0' || account->card_name_holder[i] != '\0')
    {
        if(cardData->card_holder_name[i] != account->card_name_holder[i])
        {
            match_name = False;
            break;
        }
        i++;
    }
    if(match_name == False) { return NULL; }

    i = 0;
    while(cardData->card_expiratory_date[i] != '\0' || account->expiry_date[i] != '\0')
    {
        if(cardData->card_expiratory_date[i] != account->expiry_date[i])
        {
            match_date = False;
            break;
        }
        i++;
    }
    if(match_date == False) { return NULL; }

    return account;
}

u8 serverInit(void)
{
    accounts = CreateInitialDatabase();
    return (accounts == NULL) ? False : True;
}

void serverClose(void) { accounts = NULL; }

u8 isValidAccount(CardDataTempStoring *cardData) { return (FindAccount(cardData) == NULL) ? False : True; }

u8 isAmountAvailable(TerminalDataTempStoring *termData, CardDataTempStoring *cardData)
{
    Client *account = FindAccount(cardData);
    if(account == NULL) { return False; }
    return (account->balance >= termData->trans_amount) ? True : False;
}

u8 saveTransaction(BigDataStorage *trans_data)
{
    if(transactions_count >= MAX_TRANSACTIONS) { return False; }
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