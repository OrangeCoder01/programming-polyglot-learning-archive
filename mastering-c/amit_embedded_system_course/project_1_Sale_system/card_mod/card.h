#ifndef CARD_H
#define CARD_H

#include "../toolkit/data/data_suite.h"

typedef struct
{
    char card_holder_name[51];
    char card_expiratory_date[6];
    char primary_account_number[17];
} CardDataTempStoring;

u8 getCardHolderName(CardDataTempStoring *cardData);
u8 getCardExpiryDate(CardDataTempStoring *cardData);
u8 getCardPAN(CardDataTempStoring *cardData);

#endif