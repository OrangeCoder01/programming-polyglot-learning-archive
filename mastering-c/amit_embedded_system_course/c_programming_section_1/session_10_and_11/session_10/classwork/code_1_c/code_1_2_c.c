#include <stdio.h>
int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    *arr = 10;
    printf("arr[0] = *arr = %d", arr[0]);
    return 0;
}  