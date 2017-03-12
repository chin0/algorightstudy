#include <stdio.h>

int main(void)
{
    int bill_20,bill_10,bill_5,bill_1,dollar;

    bill_20 = bill_10 = bill_5 = bill_1 = dollar = 0;

    scanf("%d",&dollar);

    bill_20 = dollar / 20;
    dollar = dollar - (20 * bill_20);

    bill_10 = dollar / 10;
    dollar = dollar - (10 * bill_10);

    bill_5 = dollar / 5;
    dollar = dollar - (5 * bill_5);

    bill_1 = dollar;

    printf("$20 : %d\n",bill_20);
    printf("$10 : %d\n",bill_10);
    printf("$5 : %d\n",bill_5);
    printf("$1 : %d\n",bill_1);

    return 0;
}
