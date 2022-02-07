#ifndef __PermanentWorker_H_
#define __PermanentWorker_H_

#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker{
    private:
        char name[100];
        int salary;
    public:
        PermanentWorker(char* name, int money): salary(money){
            strcpy(this->name, name);
        }
        int Getpay() const{
            return salary;
        }
        void ShowSalaryInfo() const{
            cout<<"name: "<<name<<endl;
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
            for(int i=0; i<empNum; i++){
                empList[i]->ShowSalaryInfo();
            }
        }
        void ShowTotalSalary() const{
            int sum=0;
            for(int i=0; i<empNum; i++){
                sum+=empList[i]->Getpay();
            }
            cout<<"salary sum: "<<sum<<endl;
        }
        ~EmployeeHandler(){
            for(int i=0; i<empNum; i++){
                delete empList[i];
            }
        }   
};

class Employee{
    private:
        char name[100];
    public:
        Employee(char * name){
            strcpy(this->name, name);
        }
        void ShowYourName() const{
            cout<<"name: "<<name<<endl;
        }
};

#endif