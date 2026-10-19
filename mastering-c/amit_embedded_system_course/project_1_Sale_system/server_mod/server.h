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
} EnumTransState;

typedef struct
{
CardDataTempStoring         card_holder_data;
TerminalDataTempStoring     terminal_data;
EnumTransState              trans_state;
u32                         transaction_sequence_number;
} BigDataStorage;

u8 serverInit(void);
void serverClose(void);

EnumTransState receiveTransactionData(BigDataStorage *transData);
u8 isValidAccount(CardDataTempStoring *cardData);
u8 isAmountAvailable(TerminalDataTempStoring *termData, CardDataTempStoring *cardData);
u8 saveTransaction(BigDataStorage *transData);
u8 getAccountBalance(CardDataTempStoring *cardData, f64 *balance);

#endif