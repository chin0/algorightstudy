#include <iostream>

using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point *temp = new Point;
    temp->xpos = p1.xpos + p2.xpos;
    temp->ypos = p1.ypos + p2.ypos;

    return *temp;
}

int main(void)
{
    Point *a = new Point;
    Point *b = new Point;
    a->xpos = 10, a->ypos = 20;
    b->xpos = 30, b->ypos = 50;

    Point &c = PntAdder(*a,*b);
    cout << c.xpos << " " <<  c.ypos << endl;
}

    
