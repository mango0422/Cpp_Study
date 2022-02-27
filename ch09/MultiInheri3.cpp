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

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo{ // Base 클래스를 간접적으로 두번 상속함.
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

/*
 * MiddleDerivedOne 클래스와 MiddleDerivedTwo 클래스가 virtual 선언이 되지 않은 채로 Base 클래스를 상속하고 객체가 생성된다면,
 * 어느 클래스를 통해 간접 상속한 Base 클래스의 멤버함수를 호출할 것인지를 명시해야 한다.
 * 
 * MiddleDerivedOne::SimpleFunc(); // MiddleDerivedOne 클래스가 상속한 Base 클래스의 SimpleFunc 함수호출을 명령!
 * MiddleDerivedTwo::SimpleFunc(); // MiddleDerivedTwo 클래스가 상속한 Base 클래스의 SimpleFunc 함수호출을 명령!
 * 
 * 그런데 이러한 상황에서, Base 클래스의 멤버가 LastDerived 객체에 하나씩만 존재하는 것이 타당한 경우가 대부분이다.
 * 즉, Base 클래스를 딱 한번만 상속하게끔 하는 것이 더 현실적인 해결책이 될 수 있다.
 * 그리고 이를 위한 문법이 바로 '가상 상속'이다.
 * 가상으로 상속을 하는 방법은 위 예제에서 보이고
 */