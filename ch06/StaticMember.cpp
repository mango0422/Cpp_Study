#include <iostream>
using namespace std;

class SoSimple{
    private:
        static int simObjCnt;
    public:
        SoSimple(){
            simObjCnt++;
            cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
        }
};
int SoSimple::simObjCnt=0;  // static 멤버 변수를 생성자에서 초기화하지 않는 이유 : 생성자에서 초기화 할 경우, 객체 생성시 마다 초기화 되기 때문.

class SoComplex{
    private:
        static int ComObjCnt;
    public:
        SoComplex(){
            ComObjCnt++;
            cout<<ComObjCnt<<"번째 ComObjCnt 객체"<<endl;
        }
        SoComplex(SoComplex &copy){
            ComObjCnt++;
            cout<<ComObjCnt<<"번째 ComObjCnt 객체"<<endl;
        }
};
int SoComplex::ComObjCnt=0;  // static 멤버 변수를 생성자에서 초기화하지 않는 이유 : 생성자에서 초기화 할 경우, 객체 생성시 마다 초기화 되기 때문.

int main(void){
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2;
    SoComplex();
    return (0);
}