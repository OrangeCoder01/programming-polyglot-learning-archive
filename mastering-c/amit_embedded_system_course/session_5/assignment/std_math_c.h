
int SetBit(int integer, int bit_number)
{
    return integer | ( 1 << bit_number );
}

int ClrBit(int integer, int bit_number)
{
    return integer & ( ~(1 << bit_number) );
}

int GetBit(int integer, int bit_number)
{
    return ( integer & ( 1 << bit_number) ) && 1;
}

int TogBit(int integer, int bit_number)
{
    return integer ^ (1 << bit_number);
}
