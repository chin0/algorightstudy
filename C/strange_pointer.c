#include <stdio.h>

int main(void)
{
    int a[4][5][5] = {
        {{1,2,3,4},
        {3,5,6,2},
        {1,2,3,4}},
    };
    int (*b)[5][5];
    b=a;
    printf("%d\n",a[0][2][1]);
}
