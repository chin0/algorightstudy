#include <iostream>
#include "3-2_1.h"

using namespace std;

void Calc::Init()
{
    plus_count = 0;
    sub_count = 0;
    div_count = 0;
    mul_count = 0;
}

float Calc::Add(float a,float b)
{
    ++plus_count;
    return a + b;
}

float Calc::Sub(float a,float b)
{
    ++sub_count;
    return a - b;
}

float Calc::Div(float a,float b)
{
    ++div_count;
    return a / b;
}

float Calc::Mul(float a,float b)
{
    ++mul_count;
    return a * b;
}

void Calc::ShowOpCount()
{
    cout << "덧셈: " << plus_count << "뺄셈: " << sub_count << "곱셈: " << mul_count << "나눗셈: " << div_count << endl;
}
