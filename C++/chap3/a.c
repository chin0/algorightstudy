#include <stdio.h>

int main(void)
{   
    //arr에 대응하는 포인터형은 int (*)[2] 즉, 2칸짜리 배열을 가리키는 포인터임. 그런데 만약 저기에 *arr을 넣어주면 [0][0]의 주소가 뜨겠지. 그리고 **arr을 하면 그 값이 나올거고.
    int arr[2][2];
    arr[0][0] = 100;
    arr[1][1] = 256;
    printf("%x\n",**arr);
}

