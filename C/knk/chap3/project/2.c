#include <stdio.h>

int main(void)
{
    int item_number,date_year
        ,date_day,date_month;
    float price;

    printf("Enter item number: ");
    scanf("%d",&item_number);

    
    printf("Enter unit price: ");
    scanf("%f",&price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&date_month,&date_day,&date_year);

    printf("Item\tUnit\t\tPurchase\n");
    printf("\tPrice\t\tDate\n");
    printf("%d\t$%7.2f\t%.2d/%.2d/%.4d\n",item_number,price,date_month,date_day,date_year);

    return 0;
}
    
    
