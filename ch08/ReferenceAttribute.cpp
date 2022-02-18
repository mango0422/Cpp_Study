// "C++에서, AAA형 포인터 변수는, AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다(객체의 주소 값을 저장할 수 있다.)"
// 근데 이러한 특성은 참조자에도 적용이 된다.
// "C++에서, AA형 참조자는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다."
// 뿐만 아니라, 예제 FunctionOverride.cpp 의 실행결과를 놓고 다음과 같이 이야기 하였는데,
// "First형 포인터 변수를 이용하여 First 클래스에 정의된 MyFunc 함수가 호출되고, Second형 포인터 변수를 이용하면 Second 클래스에 정의된 MyFunc 함수가 호출되고, Third형 포인터 변수를 이용하면 Third 클래스에 정의된 MyFunc 함수가 호출되는구나!"
// 이러한 특성도 참조자에 그대로 적용된다. 따라서 다음의 문장도 성립한다.
// "First형 참조자를 이용하여 First 클래스에 정의된 MyFunc 함수가 호출되고, Second형 참조자를 이용하면 Second 클래스에 정의된 MyFunc 함수가 호출되고, Third형 포인터 변수를 이용하면 Third 클래스에 정의된 MyFunc 함수가 호출되는구나!"
// 뿐만 아니라 가상함수의 개념도 포인터와 마찬가지로 참조자에도 그대로 적용된다.

#include <iostream>
#include <cstring>
using namespace std;

class First{
    public:
        void FirstFunc(){
            cout<<"FirstFunc()"<<endl;
        }
        virtual void SimpleFunc(){
            cout<<"First's SimpleFunc()"<<endl;
        }
};

class Second : public First{
    public:
        void SecondFunc(){
            cout<<"SecondFunc()"<<endl;
        }
        virtual void SimpleFunc(){
            cout<<"Second's SimpleFunc()"<<endl;
        }
};

class Third : public Second{
    public:
        void ThirdFunc(){
            cout<<"ThirdFunc()"<<endl;
        }
        virtual void SimpleFunc(){
            cout<<"Third's SimpleFunc()"<<endl;
        }
};

int main(void){
    Third obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.SimpleFunc();

    Second & sref = obj;
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();

    First & fref = obj;
    fref.FirstFunc();
    fref.SimpleFunc();

    return (0);
}