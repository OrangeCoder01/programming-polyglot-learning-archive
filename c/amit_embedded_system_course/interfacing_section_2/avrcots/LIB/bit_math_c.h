
#ifndef BIT_MATH_C_H_
#define BIT_MATH_C_H_

#define SetBit(bitstream, bit_order)   ((bitstream) |= (1U << (bit_order)))
#define ClrBit(bitstream, bit_order)   ((bitstream) &= ~(1U << (bit_order)))
#define GetBit(bitstream, bit_order)   (((bitstream) >> (bit_order)) & 0x01U)
#define TogBit(bitstream, bit_order)   ((bitstream) ^= (1U << (bit_order)))

#endif
