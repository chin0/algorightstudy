//
// Created by kafuuchin0 on 11.06.17.
//

#ifndef CHAP9_ACCOUNTARRAY_H
#define CHAP9_ACCOUNTARRAY_H

#include "Account.h"

typedef Account* ACC_PTR;

class AccountArray
{
private:
    ACC_PTR* arr;
    int len;
    AccountArray(const AccountArray& ref) { }
    void operator=(const AccountArray& ref) { }

public:
    AccountArray(int len);
    ACC_PTR& operator[](int idx);
    ACC_PTR operator[](int idx) const;
    int GetArrlen() const;
    ~AccountArray();
};


#endif //CHAP9_ACCOUNTARRAY_H
