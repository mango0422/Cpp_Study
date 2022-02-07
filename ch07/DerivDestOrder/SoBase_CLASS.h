#ifndef _SoBase_H_
#define _SoBase_H_

#include <iostream>
#include <cstring>
using namespace std;

class SoBase{
    private:
        int baseNum;
    public:
        SoBase(int n) : baseNum(n){
            cout<<"SoBase(): "<<baseNum<<endl;
        }
        ~SoBase(){
            cout<<"~SoBase() : "<<baseNum<<endl;
        }
};
#endif