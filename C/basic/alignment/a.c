#include <stdio.h>

struct a{
    int a;
    long b;
};

int main(void)
{
    printf("%lu %lu\n",sizeof(long),sizeof(int));
    printf("%lu\n",sizeof(struct a));
}
