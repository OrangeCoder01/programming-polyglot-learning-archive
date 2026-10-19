#include "general_functions.h"
#include <stdio.h>

u8 CalculateNumberOfCharacters(const _Generic_ *char_array, u32 *length)
{
    if(char_array == NULL || length == NULL) { return False; }
 
    s16 type_indicator = TypeChecker(char_array);
    if(type_indicator != 8 && type_indicator != -8) { return False; } 
 
    u32 count = 0;
    while(char_array[count].prime_datatype_type.u_c != '\0') { count += 1; }
 
    *length = count;
    return True;
}

u8 SwapCharArray(_Generic_ *char_arr_1, _Generic_ *char_arr_2)
{
    u32 size_1 = 0, size_2 = 0, i;
 
    if(CalculateNumberOfCharacters(char_arr_1, &size_1) == False) { return False; }
    if(CalculateNumberOfCharacters(char_arr_2, &size_2) == False) { return False; }
    if(size_1 != size_2) { return False; }
 
    for(i = 0; i < size_1; i += 1)
    {
        _Generic_ temp = char_arr_1[i];
        char_arr_1[i]  = char_arr_2[i];
        char_arr_2[i]  = temp;
    }
    return True;
}

u8 CopyCharArray(_Generic_ *destination, const _Generic_ *source, u32 destination_capacity)
{
    u32 length = 0, i;
 
    if(destination == NULL) { return False; }
    if(CalculateNumberOfCharacters(source, &length) == False) { return False; }
    if(length + 1 > destination_capacity) { return False; }
 
    for(i = 0; i <= length; i += 1) { destination[i] = source[i]; } 
    return True;
}