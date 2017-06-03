#include <iostream>
using namespace std;

class Rectangle
{
private:
    int height;
    int width;
public:
    Rectangle(int height, int width)
        : height(height), width(width)
    { }
    void ShowAreaInfo() { cout << "면적: "<< height * width << endl; }
};

class Square : public Rectangle
{
public:
    Square(int len)
        : Rectangle(len,len)
    { }
};

int main(void)
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}

