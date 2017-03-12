#include <stdio.h>


char ret[1000000];
char array[64][64];
void partition(int start_x,int start_y,int n)
{
    char a = array[start_x][start_y];
    for(int i = start_x; i<start_x + n;i++)
        for(int j = start_y; j<start_y + n;j++)
            if(a != array[i][j])
            {
                printf("(");
                partition(start_x,start_y,n/2);
                partition(start_x,start_y + n/2,n/2);
                partition(start_x + n/2,start_y,n/2);
                partition(start_x + n/2,start_y + n/2,n/2);
                printf(")");
                return;
            }
    printf("%c",a);
}

int main(void)
{
    int n;
    
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
        scanf("%s",array[i]);
    
    partition(0,0,n);
    printf("\n");
}
