#include <iostream>
#include <cstdlib>

using namespace std;

class BoundCheckIntArray
{
private:
    int *arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray &arr) { }
    BoundCheckIntArray& operator=(const BoundCheckIntArray &arr) { }

public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr=new int[len];
    }
    int& operator[] (int idx)
    {
        if(idx<0 || idx>=arrlen)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }
    int operator[] (int idx) const
    {
        if(idx<0 || idx>=arrlen)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }

    int GetArrLen() const { return arrlen; }
    ~BoundCheckIntArray() { delete []arr; }
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2dIntArray
{
private:
    BoundCheckIntArray **arr;
    int arrlen;
    BoundCheck2dIntArray(const BoundCheck2dIntArray& arr) {}
    BoundCheck2dIntArray& operator=(const BoundCheck2dIntArray& arr) {}
public:
    BoundCheck2dIntArray(int col, int row) : arrlen(col)
    {
        arr=new BoundCheckIntArrayPtr[col];
        for(int i=0; i<col; i++)
            arr[i]=new BoundCheckIntArray(row);
    }
    BoundCheckIntArray& operator[](int idx)
    {
        if(idx<0 || idx>=arrlen){
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return *(arr[idx]);
    }
    ~BoundCheck2dIntArray()
    {
        for(int i=0; i<arrlen; i++)
            delete arr[i];
        delete []arr;
    }
};

