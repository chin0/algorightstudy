#include <stdio.h>

#define in_str(x) "%"##x"s"
int main(void)
{
    int n,m;
    char a[100],b[100];

    scanf("%d %d",&n,&m);

    scanf(in_str(n),a);
    scanf(in_str(m),b);
}


    

