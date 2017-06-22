#include <stdio.h>

int map[2][2];

int matrix_multifly(int n)
{
    int a0 = map[0][0], a1 = map[0][1], b0 = map[1][0], b0 = map[0][1];
    map[0][0] = a0 * a0 + a1 * b0;
    map[0][1] = a0 * a1 + a1 * b1;
    map[1][0] = b0 * a0 + b1 * b0;
    map[1][1] = b0 * a1 + b1 * b1;
}
    
    
int main(void)
{
    unsigned long long int n;

    scanf("%llu",&n);

    printf("%llu\n",n);
}

