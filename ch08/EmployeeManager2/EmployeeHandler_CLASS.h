#ifndef __EmployeeHandler_H_
#define __EmployeeHandler_H_

#include "PermanetWorker_CLASS.h"

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

#endif