#include <stdio.h>

int factorial(int x)
{
    if(x == 1)
        return 1;
    return x * factorial(x-1);
}

int main(void)
{
    printf("5! : %d\n",factorial(5));
}
