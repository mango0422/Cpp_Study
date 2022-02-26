// 다중상속에 대한 프로그래머들의 첫 번째 의견은 다음과 같다.
// "다중상속은 득보다 실이 더 많은 문법이다. 그러니 절대로 사용하지 말아야 하며, 가능하다면 C++의 기본문법에서 제외시켜야 한다!"
// 실제로 다중상속으로만 해결이 가능한 문제는 존재하지 않으니, 굳이 다중상속을 하기 위해 노력할 필요는 없다.
// 하지만 우리가 접하는 라이브러리에는 다중상속을 적용한 예가 있기 때문에, 그리고 누군가는 다중상속을 예외적으로, 매우 제한적으로 적용할 수도 있는 일이므로, 이에 대한 이해를 위해서라도 다중상속을 공부할 필요는 있다.

// <다중상속의 기본 방법>
// 다중상속과 관련해서는 그럴듯한, 다중상속이 유용하게 보일만한 예제를 제시하기 보다는(사실 그런 예제를 만든다는 것 자체가 모순이다.) 단순히 문법의 설명을 목적으로 하는 예제를 제시하면서 설명을 진행하겠다.

#include <iostream>
using namespace std;

class BaseOne{
    public:
        void SimpleFuncOne(){
            cout<<"BaseOne"<<endl;
        }
};

class BaseTwo{
    public:
        void SimpleFuncTwo(){
            cout<<"BaseTwo"<<endl;
        } 
};

class MultiDerived : public BaseOne, protected BaseTwo{
    // 이렇듯 콤마(쉼표)를 이용해서 상속의 대상이 되는 클래스를 구분해서 명시할 수 있다.
    // 그리고 이 구문에서 보이듯이 기초 클래스를 상속하는 형태는 각각 별도로 지정이 가능하다.
    public:
        void ComplexFunc(){
            SimpleFuncOne(); // BaseOne 클래스의 멤버함수와 BaseTwo 클래스의 멤버함수를 각각 호출하고 있다.
            SimpleFuncTwo(); // 다중상속을 했기 때문에 가능한 일이다.
        }
};

int main(void){
    MultiDerived mdr;
    mdr.ComplexFunc();
    return (0);
}

// 위의 예제에서 보이듯이, 여러분이 이미 알고 있는 상속의 문법을 바탕으로, 다중상속을 쉽게 이해할 수 있다.