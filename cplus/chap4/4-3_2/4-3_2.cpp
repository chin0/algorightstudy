#ifndef _NAMECARD_H_
#define _NAMECARD_H_

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
    NameCard(char* n=0,char* c_name=0,char* p_num=0,int comp_pos=0);
    void ShowNameCardInfo() const;
};
#endif   
