#ifndef INPUT_HELPERS_H
#define INPUT_HELPERS_H

#include "../../data/data_suite.h"

/* Reads one line from stdin into buffer (at most size-1 characters), strips the trailing "\r\n".
   Returns True on success.
   Returns False on end-of-input or if the line was longer than the buffer
   (in that case the rest of the line is discarded so the next read starts clean). */
u8 ReadLine(char *buffer, u32 size);

/* Removes leading and trailing white space in place. */
void TrimInPlace(char *text);

#endif
