#include <cstring>
#include <iostream>
#include "STDString.h"

string::string() 
    : len(0), str(NULL)
{ }
string::string(char *s)
{
    len = strlen(s)+1;
    str = new char[len];
    strcpy(str,s);
}

string::string(char string &ref)
    : len(ref.len)
{
    str = new char[len];
    strcpy(str,ref.str);
}

string& string::operator=(const string &ref)
{
    if(str != NULL)
        delete []str;

    len = ref.len;
    str = new char[len+1];
    strcpy(str,ref.str);
    
    return *this;
}

string& string::operator+(const string &s) const
{
    char *tempstr = new char[len + s.len - 1];
    strcpy(tempstr,str);
    strcat(tempstr,s.str);

    string temp(tempstr);
    delete []tempstr;

    return temp;
}

string& string::operator+=(const string &s)
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

bool string::operator==(const string &s)
{
    return strcmp(s.str,str) ? false : true;
}

istream& operator>>(istream &is, string &s)
{
    char str[100];
    is>>str;
    s=String(str);
    return is;
}

ostream& operator<<(ostream &os, string &s)
{
    cout << s.str;
    return os;
}




