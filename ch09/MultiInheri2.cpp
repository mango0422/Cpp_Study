// 그럼 이어서 다중상속으로 인해 발생하는 문제와 그에 대한 해결책을 살펴보겠다.

// 다중상속의 모호성(Ambiguous)

// 다중상속의 대상이 되는 두 기초 클래스에 동일한 이름의 멤버가 존재하는 경우에는 문제가 발생할 수 있다.
// 이러한 경우에는 유도 클래스 내에서 멤버의 이름만으로 접근이 불가능하기 때문이다.
// 만약에 이름만으로 접근하려 든다면 컴파일러는 다음과 같이 불만을 토로할 것이다.
// "도대체 어느 클래스에 선언된 멤버에 접근을 하라는 거야?" - 컴파일 에러

#include <iostream>
using namespace std;

class BaseOne{
    public:
        void SimpleFunc(){
            cout<<"BaseOne"<<endl;
        }
};

class BaseTwo{
    public:
        void SimpleFunc(){
            cout<<"BaseTwo"<<endl;
        }
};

class MultiDerived : public BaseOne, BaseTwo{
    public:
        void ComplexFunc(){
            BaseOne::SimpleFunc(); // BaseOne 클래스에도, BaseTwo 클래스에도 SimpleFunc라는 이름의 멤버함수가 존재하기 때문에, 이 둘을 상속하는 유도 클래스에서 SimpleFunc 함수를 호출할 때에는, 이렇듯 어느 클래스에 정의된 함수의 호출을 원하는지 명시해야 한다.
            BaseTwo::SimpleFunc();
        }
};

int main(void){
    MultiDerived mdr;
    mdr.ComplexFunc();
    return (0);
}