#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "../../data/generic_datatype.h"

/* Returns True  if lower_limit <= *input_num_ptr <= upper_limit (limits are inclusive).
   Returns False if it is out of range, if the three values are not of the same prime datatype,
   or if lower_limit > upper_limit. */
u8 RangeValidator(const _Generic_ *input_num_ptr, _Generic_ lower_limit, _Generic_ upper_limit);

#endif
