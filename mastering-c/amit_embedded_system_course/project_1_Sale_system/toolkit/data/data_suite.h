#ifndef DATA_SUITE_H
#define DATA_SUITE_H

#include <stddef.h>
#include <stdlib.h>

#define True  1
#define False 0

typedef unsigned char       u8;
typedef signed char         s8;
typedef signed short int    s16;
typedef unsigned int        u32;
typedef unsigned long long  u64; /* 'unsigned long' is only 32 bits on 64-bit Windows, a 16-digit PAN needs 64 */
typedef double              f64;

typedef struct BankAccount
{
    u64 pan_number;           /* 64 bits (8 bytes) */
    f64 balance;              /* 64 bits (8 bytes) */
    u32 index;                /* 32 bits (4 bytes) */
    u8 card_name_holder[100]; /* 100 bytes */
    u8 expiry_date[6];        /* MM/YY + '\0' */

    struct BankAccount *link; /* pointer to the next account (8 bytes on a 64-bit OS) */
} Client;                     /* "Client" is an alias to "struct BankAccount" */

#endif
