#include <stdio.h>

typedef struct Data
{
    int data;
    void (*ShowData)(struct Data*);
    void (*Add)(struct Data*, int);
} Data;

void ShowData(Data* THIS) { printf("Data: %d\n",THIS->data);}
void Add(Data* THIS, int num) { THIS->data += num; }

int main(void)
{
    Data obj1={15,ShowData,Add};
    Data obj2={7,ShowData,Add};

    obj1.Add(&obj1,17);
    obj2.Add(&obj2,9);
    obj1.ShowData(&obj1);
    obj2.ShowData(&obj2);
    return 0;
}
