#include <stdio.h>

typedef struct {
    float real, imaginary;
} complex;



void add_complex(complex *c_1, complex *c_2, complex *sum_c)
{
    (sum_c -> real) = (c_1 -> real) + (c_2 -> real);
    (sum_c -> imaginary) = (c_1 -> imaginary) + (c_2 -> imaginary);
}


void display_complex(complex *c_1, complex *c_2, complex *sum_c)
{
    printf("(%.2f + j%.2f) + (%.2f + j%.2f) = {%.2f + j%.2f}\n",
           c_1 -> real, c_1 -> imaginary,
           c_2 -> real, c_2 -> imaginary,
           sum_c -> real, sum_c -> imaginary);
}
int main(void)
{
    complex c_1, c_2, sum;

    printf("Please, enter real part of complex_1: "); scanf("%f", &c_1.real);
    printf("Please, enter imaginary part of complex_1: "); scanf("%f", &c_1.imaginary);

    printf("Please, enter real part of complex_2: "); scanf("%f", &c_2.real);
    printf("Please, enter imaginary part of complex_2: "); scanf("%f", &c_2.imaginary);

    add_complex(&c_1, &c_2, &sum);
    display_complex(&c_1, &c_2, &sum);

    return 0;
}