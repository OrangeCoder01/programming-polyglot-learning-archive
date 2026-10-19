#ifndef CARD_H
#define CARD_H

#include "../toolkit/data/data_suite.h"

typedef struct
{
    char cardHolderName[51];
    char cardExpirationDate[6];    /* MM/YY + '\0' */
    char primaryAccountNumber[17]; /* 16 digits + '\0' */
} ST_cardData_t;


u8 getCardHolderName(ST_cardData_t *cardData);
u8 getCardExpiryDate(ST_cardData_t *cardData);
u8 getCardPAN(ST_cardData_t *cardData);

#endif
