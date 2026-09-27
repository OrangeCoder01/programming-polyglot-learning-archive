# define SetBit(bitstream, bit_order) (bitstream |( 1 << bit_order))
# define ClrBit(bitstream, bit_order) (bitstream & (~(1 << bit_order)))
# define GetBit(bitstream, bit_order) ((bitstream >> bit_order) & 1)
# define Togbit(bitstream, bit_order) (bitstream ^ (1 << bit_order))
