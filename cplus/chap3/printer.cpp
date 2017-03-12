#include "printer.h"
#include <iostream>
#include <cstring>

using namespace std;

void printer::setString(char* string)
{
    str = new char[strlen(string)];
    strcpy(str,string);   
}

void printer::printString()
{
    cout << str << endl;
}

