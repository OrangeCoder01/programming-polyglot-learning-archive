#include <stdlib.h>
#include <string.h>
#include "database.h"

/* Constant value variable, fixed address pointer */
static const char *const account_holder_names[INITIAL_ACCOUNTS] = { "Youssef Abdelhakim", "Sara Mahmoud", "Omar Alwakil",
                                                                    "Heba Abbass El-Nagar", "Ibrahim Farag", "Engy Yassin",
                                                                    "Mohamed Mandour", "Safaa Gamal" };

static const u64 pan_numbers[INITIAL_ACCOUNTS] = {4000123400000001ULL, 4000123400000002ULL, 4000123400000003ULL,
                                                  4000123400000004ULL, 4000123400000005ULL, 4000123400000006ULL,
                                                  4000123400000007ULL, 4000123400000008ULL};

static const f64 holder_balance [INITIAL_ACCOUNTS] = { 10000.0, 300.0, 5500.5, 0.0, 25000.0, 120.75, 8000.0, 1500.0 };
static const char *const seed_expiry[INITIAL_ACCOUNTS] = { "12/29", "06/28", "03/30", "09/27", "11/31", "01/25", "08/29", "02/28" };


Client *CreateInitialDatabase(void) /* void parameter for code security. */
{
    Client *first_client = NULL;
    Client *last_client  = NULL;
    u32 i;

    for(i = 0; i < INITIAL_ACCOUNTS; i += 1)
    {
        Client *new_client = (Client *) calloc(1, sizeof(Client));
        if(new_client == NULL)
        {
            FreeDatabase(first_client);
            return NULL; /* There is still a possibility that there is no place in heap. */
        }

        new_client->index = i;
        new_client->pan_number = pan_numbers[i];
        new_client->balance = holder_balance [i];

        /* Safely copying the char array (calloc already zeroed it, so the '\0' terminator is guaranteed) */
        strncpy((char *) new_client->card_name_holder, account_holder_names[i], sizeof(new_client->card_name_holder) - 1);
        strncpy((char *) new_client->expiry_date, seed_expiry[i], sizeof(new_client->expiry_date) - 1);

        if(first_client == NULL) { first_client = new_client; }
        else { last_client->link = new_client; }
        last_client = new_client;
    }
    return first_client;
}


void FreeDatabase(Client *first_client)
{
    while(first_client != NULL)
    {
        Client *next_client = first_client->link;
        free(first_client);
        first_client = next_client;
    }
}
