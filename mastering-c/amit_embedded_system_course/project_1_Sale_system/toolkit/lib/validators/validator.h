#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "../../data/generic_datatype.h"
#define IN_RANGE(value, low, high) ( ((low) <= (high)) && ((value) >= (low)) && ((value) <= (high)) )

/* 
   Returns True  if lower_limit <= *input_num_ptr <= upper_limit (limits are inclusive).
   Returns False if it is out of range, if the three values are not of the same prime datatype, or when
   lower_limit > *input_num_ptr or *input_num_ptr > upper_limit

*/
u8 RangeValidator(const _Generic_ *input_num_ptr, _Generic_ lower_limit, _Generic_ upper_limit);

#endif
