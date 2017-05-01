#ifndef _NAMECARD_H_
#define _NAMECARD_H_
#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
    enum {CLERK,SENIOR,ASSIST,MANAGER};
}

class NameCard
{
    char* name;
    char* company_name;
    char* phone_num;
    int comp_pos;
    
public:
    NameCard(char* n=NULL,char* c_name=NULL,char* phone_num=NULL,int comp_pos=0);
    NameCard(const NameCard &copy);
    void ShowNameCardInfo() const;
    ~NameCard();
};
#endif   
