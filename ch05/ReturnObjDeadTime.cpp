#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int n) : num(n){
            cout<<"New Object: "<<this<<endl;
        }
        SoSimple(const SoSimple& copy):num(copy.num){
            cout<<"New Copy Object: "<<this<<endl;
        }
        ~SoSimple(){
            cout<<"Destroy obj "<<this<<endl;
        }
};

SoSimple SimpleFuncObj(SoSimple ob){        // 클래스 객체 반환하는 함수.
    cout<<"Parm ADR: "<<&ob<<endl;
    return ob;
}

int main(void){
    SoSimple obj(7); // obj 생성
    SimpleFuncObj(obj); // 매개변수 ob 생성, SimpleFuncObj 실행, 임시객체 생성(복사로 인식), 이후 매개변수ob, 임시객체 순으로 소멸

    cout<<endl;
    SoSimple tmepRef = SimpleFuncObj(obj);
    cout<<"Return Obj"<<&tmepRef<<endl;
    return (0);
}