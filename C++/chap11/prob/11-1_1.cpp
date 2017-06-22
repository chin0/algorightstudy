#include <iostream>

using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum)
    { }
    void Shot()
    {
        cout<<"BBANG!"<<endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun *pistol;
public:
    Police(int bnum, int bcuff)
    {
        if(bnum>0)
            pistol=new Gun(bnum);
        else
            pistol=NULL;
    }
    Police& operator=(const Police& ref)
    {
        delete pistol;
        pistol = new Gun(*ref.pistol);
        return *this;
    }
    void PutHandcuff()
    {
        cout<<"SNAP!"<<endl;
        handcuffs--;
    }
    void Shot()
    {
        if(pistol==NULL)
            cout<<"Hut BBANG!"<<endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        if(pistol!=NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman1(5,3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0,3);
    pman2=pman1;
    pman2.Shot();
    pman2.PutHandcuff();
    return 0;
}
