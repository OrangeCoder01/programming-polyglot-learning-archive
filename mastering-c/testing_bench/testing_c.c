#include <stdio.h>
static int a; /* This variable is {global} (file scope) {static} (can not be accessed outside the source code file) */
int b; /* This variable is {global} (file scope) {auto} */
int func(int c, float d, char e) /* (Block scope) Function Prototype scope */
{
    static int f = 0;
    f += c + (int)(d) + (int)(e);
    return f;
} 
int main(void)
{
    register int  g; /* This variable is local scope  */
    int h1; /* An {auto} variable by default*/
    int h2; /* An {auto} variable */

    h2 = func(1, 1.0, 'a'); /* f = 0 + 1 + 1 + 97 = 99*/
    h1 = func(0, 11.0, 'A'); /* f = 99 + 0 + 11 + 65 = 175*/ /* h2 is 99 and h1 = 175*/
    printf("h2 = %d, h1 = %d", h2, h1);
    return 0;
}