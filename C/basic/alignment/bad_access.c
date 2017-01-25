#include <stdio.h>

int i;
int j;

int main(void)
{
    printf("%lx\n",&i);
    long *bad = (long*)&j;
    i = 0xdead;
    j = 0xffff;
    printf("%lx\n",*bad);
}
