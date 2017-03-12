#include <stdio.h>

#define tax (1.0f / 20.f)

int main(void)
{
    float amount,tax_added;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    tax_added = (amount * tax) + amount;

    printf("With tax added: $%.2f\n",tax_added);

    return 0;
}
