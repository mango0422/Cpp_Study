#include <iostream>
using namespace std;

int simObjCnt = 0;  // 전역변수
int cmxObjCnt = 0;  // 전역변수

class SoSimple{
    public:
        SoSimple(){
            simObjCnt++;
            cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
        }
};

class SoComplex{
    public:
        SoComplex(){
            cmxObjCnt++;
            cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
        }
        SoComplex(SoComplex &copy){
            cmxObjCnt++;
            cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
        }
};

int main(void){
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2;
    SoComplex();
    return (0);
}