#ifndef DATA_SUITE_H
#define DATA_SUITE_H

#define True  1
#define False 0

typedef unsigned char       u8;
typedef signed char         s8;
typedef signed short int    s16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
typedef double              f64;

typedef struct BankAccount
{
    u64 pan_number;
    f64 balance;
    u32 index;
    u8 card_name_holder[100];
    u8 expiry_date[6];

    struct BankAccount *link;
} Client;

#endif