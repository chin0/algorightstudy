#include <stdio.h>

int main(void)
{
    int phone1,phone2,phone3;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");

    scanf("(%d) %d-%d",&phone1,&phone2,&phone3);

    printf("You entered %3d-%3d-%4d\n",phone1,phone2,phone3);

    return 0;
}
