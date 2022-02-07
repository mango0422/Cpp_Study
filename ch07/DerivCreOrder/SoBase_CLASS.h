#ifndef __SoBase_H_
#define __SoBase_H_

#include <iostream>
#include <cstring>
using namespace std;

class SoBase{
    private:
        int baseNum;
    public:
        SoBase() : baseNum(20){
            cout<<"SoBase()"<<endl;
        }
        SoBase(int n) : baseNum(n){
            cout<<"SoBase(int n)"<<endl;
        }
        void ShowBaseData() const{
            cout<<baseNum<<endl;
        }
};

#endif