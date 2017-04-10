#include <stdio.h>
#include <string.h>

void print_2d_array(int maxY,int maxX,int (*array)[maxX])
{
    for(int i = 0; i < maxY; i++)
    {
        for(int j = 0; j < maxX; j++)
            printf("%d ",array[i][j]);
        printf("\n");
    }
}
    
int main(void)
{
    int processes, resources;

    printf("process count: ");
    scanf("%d",&processes);
    printf("resource count: ");
    scanf("%d", &resources);

    int available[resources];
    int max[processes][resources];
    int allocation[processes][resources];
    int need[processes][resources];
    int complete[processes];
    int seq[processes];

    memset(complete,0,sizeof(int) * processes);
    memset(seq,0,sizeof(int) * processes);


    printf("resources: ");
    for(int i = 0; i < resources; i++)
        scanf("%d", &available[i]);
    for(int i = 0; i < processes; i++)
    {
        printf("p%d's allocation: ",i);
        for(int j = 0; j < resources; j++)
        {
            scanf("%d",&allocation[i][j]);
            available[j] -= allocation[i][j];
            if(allocation[j] < 0)
                printf("error!\n");
        }
        printf("p%d's max: ",i);
        for(int j = 0; j < resources; j++)
            scanf("%d",&max[i][j]);

        printf("calculating p%d's need value\n",i);

        for(int j = 0; j < resources; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }

    printf("Available\n");
    for(int i = 0; i < resources; i++)
        printf("%d ",available[i]);
    printf("\n");
    printf("Allocation\n");
    print_2d_array(processes,resources,&allocation);
    printf("max\n");
    print_2d_array(processes,resources,&max);
    printf("need\n");
    print_2d_array(processes,resources,&need);

    //Find the sequence that will complete all the processes.
    //
    int cnt = 0;
    int k,j;
    printf("available: ");
    for(k = 0; k < resources; k++)
        printf("%d ",available[k]);
    printf("\n");
    for(int i = 0; i < processes; i++)
    {
        for(j = 0; j < processes; j++)
        {
            if(complete[j] == 0)
            {
                for(k = 0; k < resources;k++){
                    if(available[k] < need[j][k])
                        break;
                }

                if(k == resources){
                    for(k = 0; k < resources; k++)
                        available[k] += need[j][k];
                    complete[j] = 1;
                    seq[cnt++] = j;
                    break;
                }
            }
        }
        if(cnt == processes) break;
    }
    printf("%d\n",cnt);

    printf("%s\n",(cnt == processes) ? "safe" : "unsafe");

    printf("seq: ");
    for(int i = 0; i < processes; i++)
        printf("%d ",seq[i]);
    printf("\n");
}
    
