#include "SoDerived_CLASS.h"

int main(void){
    cout<<"case1....."<<endl;
    SoDerived dr1;
    dr1.ShowDerivData();
    cout<<"---------------------"<<endl;
    cout<<"case2....."<<endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout<<"---------------------"<<endl;
    cout<<"case3....."<<endl;
    SoDerived dr3(23, 24);
    dr3.ShowDerivData();
    return (0);
}