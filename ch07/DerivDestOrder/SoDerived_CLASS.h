#ifndef _SoDerived_H_
#define _SoDerived_H_

#include "SoBase_CLASS.h"

class SoDerived : public SoBase{
    private:
        int derivNum;
    public:
        SoDerived(int n) : SoBase(n), derivNum(n){
            cout<<"SoDerived(): "<<derivNum<<endl;
        }
        ~SoDerived(){
            cout<<"~SoDerived() : "<<derivNum<<endl;
        }
};

#endif