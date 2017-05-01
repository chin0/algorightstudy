#include <iostream>

using namespace std;

class Point
{
private:
    int xpos,ypos;
public:
    Point(int x,int y) : xpos(x),ypos(y) { /*empty constructor*/ }
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
    Circle(int r,int x, int y) : radius(r), center(x,y) { /*empty constuctor*/ }
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
    void Init(const int x1,const int y1,const int r1,const int x2,const int y2,const int r2) :
        c1(x1,y1,r1), c2(x2,y2,r2)
    { /*empty constructor*/}
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


