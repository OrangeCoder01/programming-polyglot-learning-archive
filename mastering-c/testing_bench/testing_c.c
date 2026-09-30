#include <stdio.h>
static inline int SetBit(int bitstream, int bit_order) {return (bitstream |( 1 << bit_order));}
static inline int ClrBit(int bitstream, int bit_order) {return (bitstream & (~(1 << bit_order)));}
static inline int GetBit(int bitstream, int bit_order) {return ((bitstream >> bit_order) & 1);}
static inline int Togbit(int bitstream, int bit_order) {return (bitstream ^ (1 << bit_order));}


int main(void)
{
    printf("SetBit(8, 4) = %d\n", SetBit(8, 4));
    printf("ClrBit(16, 4) = %d\n", ClrBit(16, 4));
    printf("GetBit(34, 5) = %d, GetBit(34, 3) = %d\n",GetBit(34,5), GetBit(34, 3));
    printf("TogBit(128, 7) = %d, TogBit(128, 0) = %d\n", Togbit(128, 7), Togbit(128, 0));
    return 0;
}