#ifndef _NAMECARD_H_
#define _NAMECARD_H_
#include <iostream>

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
    void ShowNameCardInfo() const;
};
#endif   
