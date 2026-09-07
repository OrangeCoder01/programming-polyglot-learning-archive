#include <stdio.h>

int main(void)
{
    int sum = 0, value = 0, i = 0, average = 0;
    printf("Please, enter 10 numbers:\n");

    for(i; i < 10; i++)
    {
        printf("Element (%d): ", i + 1); scanf("%d", &value); printf("\n");
        sum += value;
    }
    
    average = (sum / 10);
    printf("Their sum is %d\n", sum);
    printf("Their average is %d\n", average);

    

    return 0;
}