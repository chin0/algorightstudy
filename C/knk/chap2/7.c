#include <stdio.h>

int main(void)
{
    float loan,interest_rate,monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f",&loan);
    printf("Enter interest rate: ");
    scanf("%f",&interest_rate);
    printf("Enter monthly_payment: ");
    scanf("%f",&monthly_payment);

    interest_rate = loan * ((interest_rate / 100) / 12.0f);

    printf("Blance remaining after first payment: %.2f\n", loan + interest_rate - monthly_payment);
    printf("Blance remaining after second payment: %.2f\n", loan + interest_rate * 2 - (monthly_payment * 2));
    printf("Blance remaining after third payment: %.2f\n", loan + interest_rate * 2 - (monthly_payment * 3));

    return 0;
}

