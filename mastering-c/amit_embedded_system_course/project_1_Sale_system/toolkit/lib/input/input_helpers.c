#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "input_helpers.h"

u8 ReadLine(char *buffer, u32 size)
{
    size_t length;

    if(buffer == NULL || size < 2) { return False; }

    if(fgets(buffer, (int) size, stdin) == NULL) { buffer[0] = '\0'; return False; }

    length = strlen(buffer);
    if(length > 0 && buffer[length - 1] == '\n')
    {
        buffer[length - 1] = '\0';
        length -= 1;
        if(length > 0 && buffer[length - 1] == '\r') { buffer[length - 1] = '\0'; }
        return True;
    }

    {
        int c = fgetc(stdin);
        if(c == EOF) { return True; }
        while(c != '\n' && c != EOF) { c = fgetc(stdin); }
        return False;
    }
}

void TrimInPlace(char *text)
{
    size_t start = 0, end;

    if(text == NULL) { return; }

    end = strlen(text);
    while(end > 0 && isspace((unsigned char) text[end - 1])) { end -= 1; }
    text[end] = '\0';

    while(text[start] != '\0' && isspace((unsigned char) text[start])) { start += 1; }
    if(start > 0) { memmove(text, text + start, end - start + 1); }
}
