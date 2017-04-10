#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
    int x;
    int y;
public:
    Point(const int &xpos,const int &ypos); //복사과정을 거칠 필요가 없기때문에 참조형을 넘기는듯
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};
#endif
