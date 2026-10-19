#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
 
#include "../../data/generic_datatype.h"
#include "../../data/data_suite.h"

u8 CalculateNumberOfCharacters(const _Generic_ *char_array, u32 *length);

u8 SwapCharArray(_Generic_ *char_arr_1, _Generic_ *char_arr_2);

u8 CopyCharArray(_Generic_ *destination, const _Generic_ *source, u32 destination_capacity);
 
#endif