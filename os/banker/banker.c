#include <stdio.h>

int main(void)
{
    int processes=5, resources=3;

    int available[resources];
    int max[processes][resources];
    int allocation[processes][resources];
    int need[processes][resources];
    int complete[processes];


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

        printf("calculating p%d's need\n",i);

        for(int j = 0; j < resources; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }

    printf("Available\n");
    for(int i = 0; i < resources; i++)
        printf("%d ",available[i]);
    printf("\n");
    printf("Allocation\n");
    for(int i = 0; i < processes; i++)
    {
        for(int j = 0; j < resources; j++)
            printf("%d ",allocation[i][j]);
        printf("\n");
    }
    printf("max\n");
    for(int i = 0; i < processes; i++)
    {
        for(int j = 0; j < resources; j++)
            printf("%d ",max[i][j]);
        printf("\n");
    }
    printf("need\n");
    for(int i = 0; i < processes; i++)
    {
        for(int j = 0; j < resources; j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }


}


    

    



    
