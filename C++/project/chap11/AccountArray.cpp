//
// Created by kafuuchin0 on 11.06.17.
//

#include "BankingCommonDecl.h"
#include "AccountArray.h"

AccountArray::AccountArray(int len)
        : len(len)
{
    arr = new ACC_PTR[len];
}

ACC_PTR& AccountArray::operator[](int idx)
{
    if(idx<0 || idx >= len)
    {
        cout<<"out of range"<<endl;
        exit(1);
    }
    return arr[len];
}
ACC_PTR AccountArray::operator[](int idx) const
{
    if(idx<0 || idx >= len)
    {
        cout<<"out of range"<<endl;
        exit(1);
    }
    return arr[len];
}
int AccountArray::GetArrlen() const{ return len; }

AccountArray::~AccountArray()
{
    delete []arr;
}