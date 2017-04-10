#include <iostream>

using namespace std;

void add_withref(int &a)
{
    a++;
}

void swap_sign(int &a)
{
    a = -a;
}
    
int main(void)
{
    int t1 = 4;
    int t2 = 5;

    cout<<"original t1: " <<t1 << endl;
    cout<<"original t2: " << t2 << endl;

    add_withref(t1);
    swap_sign(t2);
    cout<<"after add_withref(t1): " <<t1 << endl;
    cout<<"after swap_sign(t2): " << t2 << endl;

}
