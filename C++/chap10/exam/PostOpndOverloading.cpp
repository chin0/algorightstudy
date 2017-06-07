#include <iostream>

using namespace std;

class Point
{
private:
    int xpos,ypos;
public:
    Point(int x=0, int y=0) : xpos(x),ypos(y)
    { }
    void ShowPosition() const
    {
        cout<<'['<<xpos<<" ,"<<ypos<<']'<<endl;
    }
    Point& operator++()
    {
        xpos+=1;
        ypos+=1;
        return *this;
    }
    const Point operator++(int) //복사본은 값이 변경되면 안되기때문에
    {
        const Point retobj(xpos,ypos); //원본을 미리 빼놓고 리턴
        xpos+=1;
        ypos+=1;
        return retobj;
    }

    friend Point& operator--(Point &ref);
    friend const Point operator--(Point &ref, int); //복사본은 값이 변경되면 안되기때문에.
};

Point& operator--(Point &ref)
{
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

const Point operator--(Point &ref, int)
{
    const Point retobj(ref.xpos,ref.ypos);
    ref.xpos-=1;
    ref.ypos-=1;
    return retobj;
}

int main(void)
{
    Point pos(3,5);
    Point cpy;
    cpy=pos--;
    cpy.ShowPosition();
    pos.ShowPosition();

    cpy=pos++;
    cpy.ShowPosition();
    pos.ShowPosition();
    return 0;
}
