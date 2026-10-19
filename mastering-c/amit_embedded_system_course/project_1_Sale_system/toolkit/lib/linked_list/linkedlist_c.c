#include <stdio.h>
#include "linkedlist_c.h"

/*
    (1) Display specific Account.
    (2) Retrieve Account data in database.
    (3) Insert (create) an Account in database.
    (4) Delete an Account in database.
    (5) Find an Account by its PAN.
*/

/*
Note:
    Returning '0' (False) means that there is an error otherwise '1' (True) means there are no errors anticipated during processing.
    Very indicative especially in the Bank Account project.
*/

u8 DisplayAccount(Client (*first_client_ptr), u32 target_index)
{
    Client (*ptr_client_x) = first_client_ptr; /* NULL means an empty list, the loop is simply skipped */

    while(ptr_client_x != NULL)
    {
        if(ptr_client_x->index == target_index)
        {
            printf("-------------------------------------------------------------------------\n");
            printf("    Client: {%u}\n", (unsigned) (ptr_client_x->index + 1));
            printf("        Card Name Holder: %s\n", (const char *) ptr_client_x->card_name_holder);
            printf("        PAN Number: ************%04llu\n", (unsigned long long) (ptr_client_x->pan_number % 10000ULL)); /* masked, last 4 only */
            printf("        Expiry Date: %s\n", (const char *) ptr_client_x->expiry_date);
            printf("        Balance: %.2f\n", ptr_client_x->balance);
            return True;
        }
        ptr_client_x = ptr_client_x->link;
    }
    return False;
}


u8 RetrieveAccountData(Client (*first_client_ptr), Client *(receiving_client) , u32 target_index)
{
    if(receiving_client == NULL) { return False; }

    Client *ptr_client_x = first_client_ptr;

    while(ptr_client_x != NULL)
    {
        if(ptr_client_x->index == target_index)
        {
            *receiving_client = *ptr_client_x; /* copy EVERYTHING (name, expiry, pan, balance, index) from the account that matched */
            receiving_client->link = NULL;     /* a copy must not point into the real list */
            return True;
        }
        ptr_client_x = ptr_client_x->link;
    }
    return False;
}


Client *FindAccountByPAN(Client *first_client_ptr, u64 pan_number)
{
    Client *ptr_client_x = first_client_ptr;

    while(ptr_client_x != NULL)
    {
        if(ptr_client_x->pan_number == pan_number) { return ptr_client_x; }
        ptr_client_x = ptr_client_x->link;
    }
    return NULL;
}


u8 InsertAccount(Client **first_client_ptr, const Client *new_account_data) /* Double Pointer! */
{
    Client *new_client;
    Client *last_client;
    u32 next_index = 0;

    if(first_client_ptr == NULL || new_account_data == NULL) { return False; }

    /* Two bank accounts can never share a PAN */
    if(FindAccountByPAN(*first_client_ptr, new_account_data->pan_number) != NULL) { return False; }

    new_client = (Client *) calloc(1, sizeof(Client));
    if(new_client == NULL) { return False; } /* no place left in the heap */

    *new_client = *new_account_data;
    new_client->link = NULL;

    if(*first_client_ptr == NULL)
    {
        new_client->index = 0;
        *first_client_ptr = new_client;
        return True;
    }

    last_client = *first_client_ptr;
    while(True)
    {
        if(last_client->index >= next_index) { next_index = last_client->index + 1; }
        if(last_client->link == NULL) { break; }
        last_client = last_client->link;
    }

    new_client->index = next_index;
    last_client->link = new_client;
    return True;
}


u8 DeleteAccount(Client **first_client_ptr, u32 target_index)
{
    Client *ptr_client_x;
    Client *previous_client = NULL;

    if(first_client_ptr == NULL) { return False; }

    ptr_client_x = *first_client_ptr;
    while(ptr_client_x != NULL)
    {
        if(ptr_client_x->index == target_index)
        {
            if(previous_client == NULL) { *first_client_ptr = ptr_client_x->link; }
            else { previous_client->link = ptr_client_x->link; }

            free(ptr_client_x);
            return True;
        }
        previous_client = ptr_client_x;
        ptr_client_x = ptr_client_x->link;
    }
    return False;
}
