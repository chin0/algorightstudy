#include <iostream>
#include <cstring>

using namespace std;

class PermanentWorker
{
private:
    char name[100];
    int salary;
public:
    PermanentWorker(char* name, int money)
        : salary(money)
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        cout<<"name: "<<name<<endl;
        cout<<"salart: "<<GetPay()<<endl<<endl;
    }
};
//이와같이 기능의 처리를 실제로 담당하는 클래스를 가리켜 컨트롤 클래스 또는 핸들러 클래스라 한다.
class EmployeeHandler
{
private:
    PermanentWorker* empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    { }
    void AddEmployee(PermanentWorker* emp)
    {
        empList[empNum++]=emp;
    }
    void ShowAllSalaryInfo() const
    {
        for(int i=0; i<empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum=0;
        for(int i=0; i<empNum; i++)
            sum+=empList[i]->GetPay();
        cout<<"salary num: "<<sum<<endl;
    }
    ~EmployeeHandler()
    {
        for(int i=0; i<empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM",1000));
    handler.AddEmployee(new PermanentWorker("LEE",1500));
    handler.AddEmployee(new PermanentWorker("JUN",2000));

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();
    return 0;
}
