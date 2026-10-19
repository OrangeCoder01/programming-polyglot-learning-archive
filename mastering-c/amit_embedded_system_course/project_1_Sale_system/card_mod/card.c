#include <stdio.h>
#include <string.h>
#include "card.h"

u8 getCardHolderName(CardDataTempStoring *cardData)
{
    char input[100];
    u32 i = 0, length = 0;
    u8 is_valid_char;

    printf("Enter card holder name: ");
    if (scanf(" %[^\n]", input) != 1) { return False; }

    while(input[length] != '\0') { length += 1; }

    if(length < 3 || length > 50) { return False; }

    is_valid_char = ((input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= 'a' && input[0] <= 'z')) ? True : False;
    if(is_valid_char == False) { return False; } 

    for(i = 0; i < length; i += 1)
    {
        is_valid_char = ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) ? True : False;
        if(is_valid_char == False && input[i] != ' ' && input[i] != '-') { return False; }
    }

    strcpy(cardData->card_holder_name, input);
    return True;
}

u8 getCardExpiryDate(CardDataTempStoring *cardData)
{
    char input[100];
    u32 month, length = 0;
    u8 d1, d2, d3, d4;

    printf("Enter card expiry date (MM/YY): ");
    if (scanf(" %[^\n]", input) != 1) { return False; }

    while(input[length] != '\0') { length += 1; }
    if(length != 5) { return False; }

    d1 = (input[0] >= '0' && input[0] <= '9') ? True : False;
    d2 = (input[1] >= '0' && input[1] <= '9') ? True : False;
    if(d1 == False || d2 == False) { return False; }

    if(input[2] != '/') { return False; }

    d3 = (input[3] >= '0' && input[3] <= '9') ? True : False;
    d4 = (input[4] >= '0' && input[4] <= '9') ? True : False;
    if(d3 == False || d4 == False) { return False; }

    month = (input[0] - '0') * 10 + (input[1] - '0');
    if(month < 1 || month > 12) { return False; }

    strcpy(cardData->card_expiratory_date, input);
    return True;


}

u8 getCardPAN(CardDataTempStoring *cardData)
{
    char input[100];
    u32 i = 0, length = 0;
    u8 is_dig;

    printf("Enter card PAN (16 digits): ");
    if (scanf(" %[^\n]", input) != 1) { return False; }

    while(input[length] != '\0') { length += 1; }
    if(length != 16) { return False; }

    for(i = 0; i < 16; i += 1)
    {
        is_dig = (input[i] >= '0' && input[i] <= '9') ? True : False;
        if(is_dig == False) { return False; }
    }

    strcpy(cardData->primary_account_number, input);
    return True;
}