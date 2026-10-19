#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "card.h"

u8 getCardHolderName(CardDataTempStoring *cardData)
{
    char input[100];
    u32 i, length;

    printf("Enter card holder name: ");
    if(fgets(input, sizeof(input), stdin) == NULL) { return False; }
    input[strcspn(input, "\r\n")] = '\0';

    length = strlen(input);
    if(length < 3 || length > 50) { return False; }
    if(isalpha((unsigned char) input[0]) == 0) { return False; } 

    for(i = 0; i < length; i += 1)
    {
        if(isalpha((unsigned char) input[i]) == 0 && input[i] != ' ' && input[i] != '-') { return False; }
    }

    strcpy(cardData->card_holder_name, input);
    return True;
}


u8 getCardExpiryDate(CardDataTempStoring *cardData)
{
    char input[100];
    u32 month;

    printf("Enter card expiry date (MM/YY): ");
    if(fgets(input, sizeof(input), stdin) == NULL) { return False; }
    input[strcspn(input, "\r\n")] = '\0';

    if(strlen(input) != 5) { return False; }
    if(isdigit((unsigned char) input[0]) == 0 || isdigit((unsigned char) input[1]) == 0) { return False; }
    if(input[2] != '/') { return False; }
    if(isdigit((unsigned char) input[3]) == 0 || isdigit((unsigned char) input[4]) == 0) { return False; }

    month = (input[0] - '0') * 10 + (input[1] - '0');
    if(month < 1 || month > 12) { return False; }

    strcpy(cardData->card_expiratory_date, input);
    return True;
}


u8 getCardPAN(CardDataTempStoring *cardData)
{
    char input[100];
    u32 i;

    printf("Enter card PAN (16 digits): ");
    if(fgets(input, sizeof(input), stdin) == NULL) { return False; }
    input[strcspn(input, "\r\n")] = '\0';

    if(strlen(input) != 16) { return False; }
    for(i = 0; i < 16; i += 1)
    {
        if(isdigit((unsigned char) input[i]) == 0) { return False; }
    }

    strcpy(cardData->primary_account_number, input);
    return True;
}
