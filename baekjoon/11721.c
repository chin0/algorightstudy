#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char a[101];

    scanf("%s",a);
    
    int len = strlen(a);
    int count = len % 10;

    for(i = 0; i<len/10; i++){
        for(int j = 0; j<10; j++){
            printf("%c",a[(10 * i) + j]);
        }
        printf("\n");
    }
    for(int j = 0; j<count;j++)
        printf("%c",a[(10 * i) + j]);
}


    

