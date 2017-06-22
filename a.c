#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = "abcdaaaaaaaaaaaaa/*";
    char *str2 = "*";

    char a[50];

    sscanf(str,"%10[^*]",a);

    printf("%s\n",a);

}
