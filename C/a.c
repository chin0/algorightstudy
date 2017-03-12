#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))
#define REMAINDER(x) ((x) % 4)
#define COMPARE(x,y) ((x) * (y) < 100 ? 1 : 0)
int main()
{
    printf("%d\n",COMPARE(10,20));
}
    
