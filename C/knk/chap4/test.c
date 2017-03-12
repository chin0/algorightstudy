#include <stdio.h>

int main(void)
{
    int i,j,k;

    i = 1;
    printf("%d\n", i++ - 1);
    
    i = 10; j = 5;
    printf("%d\n", i++ - ++j);

    i = 7; j = 8;
    printf("%d\n", i++ - --j);

    i = 3, j = 4, k = 5;
    printf("%d\n", i++ - j++ + --k);

}
