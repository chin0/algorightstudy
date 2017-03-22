#include <stdio.h>
void _strcpy(char *a,char *b);

int main(void)
{
    char a[100];
    char b[100] = "chino!";

    _strcpy(a,b);
    printf("%s",a);
}

    
