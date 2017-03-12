#include <stdio.h>

int main(void)
{
    char a;
    do{
        a = getchar();
        if(a == '\n' || a == ' ')
            continue;
        printf("%c\n",a);
    } while(a != 'q');
}
