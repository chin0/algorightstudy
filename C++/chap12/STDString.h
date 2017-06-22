#ifndef _STDSTRING_H
#define _STDSTRING_H

class string
{
private:
    char *str;
    int len;
public:
    string();
    string(char *s);
    string(const string &ref);
    string& operator=(const string &ref);
    string& operator+(const string &s) const;
    string& operator+=(const string &s);
    bool operator==(const string &s) const;
    ~string();

    friend istream& operator>>(istream& is, string& s);
    friend ostream& operator<<(ostream& os, string& s);
};

#endif
