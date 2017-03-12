#include <stdio.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main(void)
{
    float f,c;

    printf("F: ");
    scanf("%f",&f);

    c = (f - FREEZING_PT) * SCALE_FACTOR;
    
    printf("C: %.1f\n",c);
    
    return 0;
}


