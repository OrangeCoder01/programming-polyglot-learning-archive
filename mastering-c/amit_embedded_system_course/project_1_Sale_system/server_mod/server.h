#ifndef SERVER_H
#define SERVER_H

#include "../toolkit/data/data_suite.h"
#include "../card_mod/card.h"
#include "../terminal_mod/terminal.h"

typedef enum
{
    APPROVED,
    DECLINED_INSUFFICIENT_FUND,
    DECLINED_INVALID_ACCOUNT,
    INTERNAL_SERVER_ERROR
} EN_transState_t;

typedef struct
{
    ST_cardData_t     cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t   transState;
    u32               transactionSequenceNumber;
} ST_transaction_t;

u8 serverInit(void);   /* creates the accounts database */
void serverClose(void);

EN_transState_t receiveTransactionData(ST_transaction_t *transData);
u8 isValidAccount(ST_cardData_t *cardData);                                   /* True = account exists */
u8 isAmountAvailable(ST_terminalData_t *termData, ST_cardData_t *cardData);   /* True = balance is enough */
u8 saveTransaction(ST_transaction_t *transData);
u8 getAccountBalance(ST_cardData_t *cardData, f64 *balance);

#endif
