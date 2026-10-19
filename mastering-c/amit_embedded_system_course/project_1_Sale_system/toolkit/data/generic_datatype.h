#ifndef GENERIC_DATATYPE_H
#define GENERIC_DATATYPE_H

#include "data_suite.h"

typedef enum
{
    ty_u8,
    ty_s8,
    ty_u32,
    ty_u64,
    ty_f64
} _PrimeDataTypeEnum_;

typedef union
{
    u8 u_c;
    s8 s_c;
    u32 u_i;
    u64 u_li;
    f64 d;
} _PrimeDataTypeUnion_; /* Size is 64 bit (8 bytes) */

typedef struct
{
    _PrimeDataTypeEnum_ prime_datatype_order;
    _PrimeDataTypeUnion_ prime_datatype_type;
} _Generic_;


s16 TypeChecker(const _Generic_ *);

#endif
