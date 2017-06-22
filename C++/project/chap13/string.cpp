//
// Created by kafuuchin0 on 11.06.17.
//

#include "string.h"


String::String()
        : len(0), str(NULL)
{ }

String::String(char *s)
{
    len = strlen(s)+1;
    str = new char[len];
    strcpy(str,s);
}

String::String(const String &ref)
    : len(ref.len)
{
    str = new char[len];
    strcpy(str,ref.str);
}

String::~String()
{
    if(str!=NULL)
        delete []str;
}
String& String::operator=(const String &ref)
{
    if(str != NULL)
        delete []str;

    len = ref.len;
    str = new char[len+1];
    strcpy(str,ref.str);

    return *this;
}

String& String::operator+(const String &s) const
{
    char *tempstr = new char[len + s.len - 1];
    strcpy(tempstr,str);
    strcat(tempstr,s.str);

    String temp(tempstr);
    delete []tempstr;

    return temp;
}

String& String::operator+=(const String &s)
{
    char *tempstr = new char[len+s.len-1];
    strcpy(tempstr,str);
    strcat(tempstr,s.str);
    len += s.len-1;

    if(str != NULL)
        delete []str;
    str = tempstr;
    return *this;
}

bool String::operator==(const String &s) const
{
    return strcmp(s.str,str) ? false : true;
}

istream& operator>>(istream &is, String &s)
{
    char str[100];
    is>>str;
    s=String(str);
    return is;
}

ostream& operator<<(ostream &os, const String &s)
{
    cout << s.str;
    return os;
}
