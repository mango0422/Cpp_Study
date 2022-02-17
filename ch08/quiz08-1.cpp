/* 
 * From : EmployeeManaget4
 * Since : 2022-02-16
 * Writer : SYJ
 */

#include <iostream>
#include <cstring>
using namespace std;

class Employee{
    private:
        char name[100];
    public:
        Employee(const char * name){
            strcpy(this->name, name);
        }
        void ShowYourName() const{
            cout<<"name: "<<name<<endl;
        }
        virtual int GetPay() const{
            return (0);
        }
        virtual void ShowSalaryInfo() const{}
};

class PermanentWorker : public Employee{
    private:
        int salary;
    public:
        PermanentWorker(const char * name, int money) : Employee(name), salary(money){}
        int Getpay() const{
            return salary;
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout<<"salary: "<<Getpay()<<endl<<endl;
        }
};

class EmployeeHandler{
    private:
        Employee *empList[50];
        int empNum;
    public:
        EmployeeHandler(): empNum(0){}
        void AddEmployee(Employee* emp){
            empList[empNum++]=emp;
        }
        void ShowAllSalaryInfo() const{
            for(int i=0; i<empNum; i++){
            empList[i]->ShowSalaryInfo();
            }
        }
        void ShowTotalSalary() const{
            int sum=0;
            for(int i=0; i<empNum; i++){
            sum+=empList[i]->GetPay();
            }
            cout<<"salary sum: "<<sum<<endl;
        }
        ~EmployeeHandler(){
            for(int i=0; i<empNum; i++){
                delete empList[i];
            }
        }
};

class TemporaryWorker : public Employee{
    private:
        int workTime;
        int payPerHour;
    public:
        TemporaryWorker(const char * name, int pay) : Employee(name), workTime(0), payPerHour(pay){}
        void AddWorkTime(int time){
            workTime += time;
        }
        int GetPay() const{
            return workTime*payPerHour;
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout<<"salary: "<<GetPay()<<endl<<endl;
        }
};

class SalesWorker : public PermanentWorker{
    private:
        int salesResult;
        double bonusRatio;
    public:
        SalesWorker(const char * name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio){}
        void AddSalesResult(int value){
            salesResult+=value;
        }
        int GetPay() const{
            return PermanentWorker::Getpay() + (int)(salesResult*bonusRatio);
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout<<"salary: "<<GetPay()<<endl<<endl;
        }
};

/*
 * 영업직 지원 중 일부는 오지산간으로 시장개척을 진행하고 있다.
 * 일부는 아마존에서, 또 일부는 테러의 위험이 있는 지역에서 영업활동을 진행 중에 있다.
 * 따라서 이러한 직원들을 대상으로 별도의 위험수당을 지급하고자 한다.
 * 
 * Risk A : 영업직의 기본급여와 인센티브 합계 총액의 30% 추가 지급
 * Risk B : 영업직의 기본급여와 인센티브 합계 총액의 20% 추가 지급
 * Risk C : 영업직의 기본급여와 인센티브 합계 총액의 10% 추가 지급
 */
enum RISK_LEVEL {RISK_A=3,RISK_B=2,RISK_C=1};

class ForeignSalesWorker : public Employee{
    private :
        int salary;
        int bonusRatio;
        int RISK_LEVEL;
        int performance;
    public:
        ForeignSalesWorker(char * my_name, int my_salary, int my_bonusRatio, int my_RISK_LEVEL) : Employee(my_name), salary(my_salary), bonusRatio(my_bonusRatio), RISK_LEVEL(my_RISK_LEVEL){
        }
        void AddSalesResult(int my_performance){
            performance = my_performance;
        }
        int GetPay() const{
            return (salary + (int)(performance * bonusRatio)) * (1 + 0.1 * RISK_LEVEL);
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout<<"salary: "<<salary<<endl;
            cout<<"risk pay: "<<(salary + (int)(performance * bonusRatio))*0.1*RISK_LEVEL<<endl;
            cout<<"sum: "<<GetPay()<<endl<<endl;
        }
};

int main(void){
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    // 정규직 등록
    ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1700, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Yoon", 1700, 0.1, RISK_LEVEL::RISK_B);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Lee", 1700, 0.1, RISK_LEVEL::RISK_C);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();
    return (0);
}