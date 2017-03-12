#include <stdio.h>

#define pi 3.14f
#define fraction (4.0f/3.0f)

int main(void)
{
    float radius,volume;

    printf("radius? ");
    scanf("%f",&radius);

    volume = fraction * (radius * radius * radius) * pi;

    printf("10-meter radius sphere's volume: %f\n",volume);
    
    return 0;
}
    
