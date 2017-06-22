//
// Created by kafuuchin0 on 11.06.17.
//

#ifndef CHAP9_ACCOUNTARRAY_H
#define CHAP9_ACCOUNTARRAY_H

#include "Account.h"

template <class T>

class AccountArray
{
private:
    T* arr;
    int len;
    AccountArray(const T& ref) { }
    void operator=(const T& ref) { }

public:
    AccountArray(int len);
    T& operator[](int idx);
    T operator[](int idx) const;
    int GetArrlen() const;
    ~AccountArray();
};

template <class T>
AccountArray<T>::AccountArray(int len)
        : len(len)
{
    arr = new T[len];
}

template <class T>
T& AccountArray<T>::operator[](int idx)
{
    if(idx<0 || idx >= len)
    {
        cout<<"out of range"<<endl;
        exit(1);
    }
    return arr[len];
}
template <class T>
T AccountArray<T>::operator[](int idx) const
{
    if(idx<0 || idx >= len)
    {
        cout<<"out of range"<<endl;
        exit(1);
    }
    return arr[len];
}
template <class T>
int AccountArray<T>::GetArrlen() const{ return len; }

template <class T>
AccountArray<T>::~AccountArray()
{
    delete []arr;
}

#endif //CHAP9_ACCOUNTARRAY_H
