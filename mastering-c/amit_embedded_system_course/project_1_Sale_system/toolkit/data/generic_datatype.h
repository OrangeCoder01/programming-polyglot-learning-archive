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

/* 'static inline' because this function lives in a header: every .c file that includes it gets its own copy,
   a plain definition here would give "multiple definition of TypeChecker" at link time. */
static inline s16 TypeChecker(const _Generic_ *Input)
{
    switch(Input->prime_datatype_order)
    {
        case ty_u8:  { return (s16) (8); }
        case ty_s8:  { return (s16) (-8); }
        case ty_u32: { return (s16) (320); }  /* 32 bits and concatenated 0 for indicating it is integer */
        case ty_u64: { return (s16) (640); }  /* 64 bits and concatenated 0 for indicating it is integer */
        case ty_f64: { return (s16) (641); }  /* 64 bits and concatenated 1 for indicating it is a floating point datatype */
        default: { return False; }            /* Unrecognized Datatype */
    }
}

#endif
