#ifndef _MY_CLASS
#define _MY_CLASS

class Calc
{
private:
    int plus_count;
    int sub_count;
    int div_count;
    int mul_count;
public:
    void Init();
    float Add(float a,float b);
    float Sub(float a,float b);
    float Div(float a,float b);
    float Mul(float a,float b);
    void ShowOpCount();
};

#endif
