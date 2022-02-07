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

#endif