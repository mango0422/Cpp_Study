// 함수 호출관계의 모호함은 다른 상황에서도 발생할 수 있다.
// 이 상황을 다음 에제를 통해 소개하겠으니 (더불어 해결방법도), 무엇이 모호함의 원인인지 관찰해보자.

#include <iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Base Constructor"<<endl;
        }
        void SimpleFunc(){
            cout<<"BaseOne"<<endl;
        }
};

class MiddleDerivedOne : virtual public Base{
    public:
        MiddleDerivedOne() : Base(){
            cout<<"MiddleDerivedOne Constructor"<<endl;
        }
        void MiddleFuncOne(){
            SimpleFunc();
            cout<<"MiddleDerivedOne"<<endl;
        }
};

class MiddleDerivedTwo : virtual public Base{
    public:
        MiddleDerivedTwo() : Base(){
            cout<<"MiddleDerivedTwo Constructor"<<endl;
        }
        void MiddleFuncTwo(){
            SimpleFunc();
            cout<<"MiddleDerivedTwo"<<endl;
        }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo{
    public:
        LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo(){
            cout<<"LastDerived Constructor"<<endl;
        }
        void ComplexFunc(){
            MiddleFuncOne();
            MiddleFuncTwo();
            SimpleFunc();
        }
};

int main(void){
    cout<<"객체생성 전 ..... "<<endl;
    LastDerived ldr;
    cout<<"객체생성 전 ..... "<<endl;
    ldr.ComplexFunc();
    return (0);
}