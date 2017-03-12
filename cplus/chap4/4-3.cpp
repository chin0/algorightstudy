#include <iostream>

using namespace std;

class Point
{
private:
    int xpos,ypos;
public:
    Point(const int x=0,const int y=0)
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
    Circle(const int r=0,const int x=0, const int y=0)
        :radius(r),center(x,y) 
    {
        //empty
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
    Ring(const int x1=0,const int y1=0,const int r1=0,const int x2=0,const int y2=0,const int r2=0)
        :c1(r1,x1,y1),c2(r2,x2,y2)
    {
        //empty
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
    Ring ring(1,1,4,2,2,9);
    ring.PrintRingInfo();
    return 0;
}


