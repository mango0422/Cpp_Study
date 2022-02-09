#ifndef __PermanentWorker_H_
#define __PermanentWorker_H_

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
        PermanentWorker *empList[50];
        int empNum;
    public:
        EmployeeHandler(): empNum(0){}
        void AddEmployee(PermanentWorker* emp){
            empList[empNum++]=emp;
        }
        void ShowAllSalaryInfo() const{
            // for(int i=0; i<empNum; i++){
            //     empList[i]->ShowSalaryInfo();
            // }
        }
        void ShowTotalSalary() const{
            int sum=0;
            // for(int i=0; i<empNum; i++){
            //     sum+=empList[i]->Getpay();
            // }
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
            
        }
};

#endif