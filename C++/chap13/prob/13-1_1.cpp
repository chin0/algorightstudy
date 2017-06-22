#include <iostream>
using namespace std;

class Point
{
private:
    int xpos,ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
};

template <class T1>

void Swap(T1 &a, T1 &b)
{
    T1 temp=a;
    a=b;
    b=temp;
}

int main(void)
{
    Point a(3,4);
    Point b(5,6);

    Swap(a,b);

    a.ShowPosition();
    b.ShowPosition();
}
