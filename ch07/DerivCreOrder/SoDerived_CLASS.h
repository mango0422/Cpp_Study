#ifndef _SoDerived_H_
#define _SoDerived_H_

#include "SoBase_CLASS.h"

class SoDerived : public SoBase{
    private:
        int derivNum;
    public:
        SoDerived() : derivNum(30){
            cout<<"SoDerived()"<<endl;
        }
        SoDerived(int n) : derivNum(n){
            cout<<"SoDerived(int n)"<<endl;
        }
        SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2){
            cout<<"SoDerived(int n1, int n2)"<<endl;
        }
        void ShowDerivData() const{
            ShowBaseData();
            cout<<derivNum<<endl;
        }
};

#endif