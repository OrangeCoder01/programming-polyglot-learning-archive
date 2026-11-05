#include <stdlib.h>
#include "linkedlist_c.h"

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