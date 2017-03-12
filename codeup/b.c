#include <stdio.h>

void switchstage(int x,int y,int (*stage)[19]){
    for(int i = 0; i<19; i++)
    {
        stage[y][i] = (stage[y][i] == 0 ? 1 : 0);
        stage[i][x] = (stage[i][x] == 0 ? 1 : 0);
    }
}

int main(void)
{
    int i,j,n,x,y;
    int stage[19][19];

    for(i=0;i<19;i++)
        for(j=0;j<19;j++)
            scanf("%d",&stage[i][j]);
    
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d %d", &x, &y);
        switchstage(x-1,y-1,stage);
    }
    for(i=0;i<19;i++){
        for(j=0;j<19;j++)
            printf("%d ",stage[i][j]);
        printf("\n");
    }
}

