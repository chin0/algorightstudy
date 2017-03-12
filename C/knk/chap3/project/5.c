#include <stdio.h>

int main(void)
{
    int a1,a2,a3,a4;
    int b1,b2,b3,b4;
    int c1,c2,c3,c4;
    int d1,d2,d3,d4;

    int row1,row2,row3,row4;
    int col1,col2,col3,col4;
    int dia1,dia2;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            &a1,&a2,&a3,&a4,
            &b1,&b2,&b3,&b4
            ,&c1,&c2,&c3,&c4
            ,&d1,&d2,&d3,&d4);

    row1 = a1 + a2 + a3 + a4;
    row2 = b1 + b2 + b3 + b4;
    row3 = c1 + c2 + c3 + c4;
    row4 = d1 + d2 + d3 + d4;

    col1 = a1 + b1 + c1 + d1;
    col2 = a2 + b2 + c2 + d2;
    col3 = a3 + b3 + c3 + d3;
    col4 = a4 + b4 + c4 + d4;

    dia1 = a1 + b2 + c3 + d4;
    dia2 = a4 + b3 + c2 + d1;

    printf("%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n",
            a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4,d1,d2,d3,d4);
    
    printf("Row sums: %d %d %d %d\n",row1,row2,row3,row4);
    printf("Column sums: %d %d %d %d\n",col1,col2,col3,col4);
    printf("Diagonal sums: %d %d\n",dia1,dia2);

    return 0;
}

    
