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
    Point& operator+=(const Point &p)
    {
        xpos += p.xpos;
        ypos += p.ypos;
        return *this;
    }
        
    friend ostream& operator<<(ostream& os,const Point &p);
};

ostream& operator<<(ostream& os, const Point &p)
{
     cout<<'['<<p.xpos<<", "<<p.ypos<<']'<<endl;
     return os;
}

template <class T1>

T1 SumArray(T1 arr[], int len)
{
    T1 sum;
    for(int i=0; i<len; i++)
        sum+=arr[i];
    return sum;
}
int main(void)
{
    double p[5];
    for(int i = 0; i < 5; i++)
        p[i] = i * 3.14;
    cout << SumArray(p,5) << endl;

}
