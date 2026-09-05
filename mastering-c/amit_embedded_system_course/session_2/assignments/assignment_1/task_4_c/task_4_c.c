#include <stdio.h>

#define pi 3.14
int main(void)
{
    float radius = 0;
    printf("please, enter the radius of the circle in Meter: ");
    scanf("%f", &radius);
    float area = pi*radius*radius;
    printf("the area of a %.2f-radius circle is: %.2f", radius, area);
    
}