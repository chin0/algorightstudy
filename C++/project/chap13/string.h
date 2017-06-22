//
// Created by kafuuchin0 on 11.06.17.
//

#ifndef CHAP9_STRING_H
#define CHAP9_STRING_H

#include "BankingCommonDecl.h"

class String
{
private:
    char *str;
    int len;
public:
    String();
    String(char *s);
    String(const String &ref);
    String& operator=(const String &ref);
    String& operator+(const String &s) const;
    String& operator+=(const String &s);
    bool operator==(const String &s) const;
    ~String();

    friend istream& operator>>(istream& is, String& s);
    friend ostream& operator<<(ostream& os, const String& s);
};

#endif //CHAP9_STRING_H
