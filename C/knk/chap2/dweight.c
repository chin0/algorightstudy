#include <stdio.h>

int main(void)
{
    int volume;

    int height = 8;
    int length = 12;
    int width = 10;

    volume = height * length * width;

    printf("Dimensions: %dx%dx%d\n",length,width,height);
    printf("Volume (cubin inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n",(volume + 165) / 166);

    return 0;
}
    
