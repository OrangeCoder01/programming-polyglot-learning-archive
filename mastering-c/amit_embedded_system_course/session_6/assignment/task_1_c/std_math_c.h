
int SetBit(int integer, int bit_position)
{
    return integer | ( 1 << bit_position );
}

int ClrBit(int integer, int bit_position)
{
    return integer & ( ~(1 << bit_position) );
}

int GetBit(int integer, int bit_position)
{
    return ( integer & ( 1 << bit_position) ) && 1;
}

int TogBit(int integer, int bit_position)
{
    return integer ^ (1 << bit_position);
}
