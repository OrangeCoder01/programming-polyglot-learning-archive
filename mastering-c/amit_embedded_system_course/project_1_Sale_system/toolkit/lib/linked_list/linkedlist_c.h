#ifndef LINKEDLIST_C_H
#define LINKEDLIST_C_H

#include "../../data/data_suite.h"

u8 DisplayAccount(Client*, u32);
u8 RetrieveAccountData(Client*, Client*, u32);
u8 InsertAccount(Client**, const Client *new_account_data);
u8 DeleteAccount(Client**, u32);

/* Returns a pointer to the account inside the list (NOT a copy, so the caller can update the balance), or NULL. */
Client *FindAccountByPAN(Client *first_client_ptr, u64 pan_number);

#endif
