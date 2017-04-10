#include <iostream>

using namespace std;

class Point
{
private:
    int xpos,ypos;
public:
    void Init(int x,int y)
    {
        xpos=x;
        ypos=y;
    }
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<" , "<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    int radius;
    Point center;
public:
    void Init(const int r,const int x, const int y)
    {
        Point c;
        c.Init(x,y);
        center = c;
        radius=r;
    }
    void ShowCircleInfo() const
    {
        cout<<"radius: " << radius<<endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle c1;
    Circle c2;
public:
    void Init(const int x1,const int y1,const int r1,const int x2,const int y2,const int r2)
    {
        c1.Init(r1,x1,y1);
        c2.Init(r2,x2,y2);
    }
    void PrintRingInfo() const
    {
        cout << "Inner Circle Info" << endl;
        c1.ShowCircleInfo();
        cout << "Outter Circle Info" << endl;
        c2.ShowCircleInfo();
    }
};
        

int main(void)
{
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.PrintRingInfo();
    return 0;
}


