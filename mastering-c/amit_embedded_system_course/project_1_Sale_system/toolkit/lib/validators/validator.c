#include <stddef.h>
#include "validator.h"

u8 RangeValidator(const _Generic_ *input_num_ptr, _Generic_ lower_limit, _Generic_ upper_limit)
{
    if(input_num_ptr == NULL) { return False; }

    /* All three must be the same kind of number, otherwise the comparison is meaningless */
    if(input_num_ptr->prime_datatype_order != lower_limit.prime_datatype_order) { return False; }
    if(input_num_ptr->prime_datatype_order != upper_limit.prime_datatype_order) { return False; }

    switch(TypeChecker(input_num_ptr))
    {
        case (8):   { return (u8) IN_RANGE(input_num_ptr->prime_datatype_type.u_c, lower_limit.prime_datatype_type.u_c, upper_limit.prime_datatype_type.u_c); }
        case (-8):  { return (u8) IN_RANGE(input_num_ptr->prime_datatype_type.s_c, lower_limit.prime_datatype_type.s_c, upper_limit.prime_datatype_type.s_c); }
        case (320): { return (u8) IN_RANGE(input_num_ptr->prime_datatype_type.u_i, lower_limit.prime_datatype_type.u_i, upper_limit.prime_datatype_type.u_i); }
        case (640): { return (u8) IN_RANGE(input_num_ptr->prime_datatype_type.u_li, lower_limit.prime_datatype_type.u_li, upper_limit.prime_datatype_type.u_li); }
        case (641): { return (u8) IN_RANGE(input_num_ptr->prime_datatype_type.d, lower_limit.prime_datatype_type.d, upper_limit.prime_datatype_type.d);}
        default:    { return False; }
    }
}
