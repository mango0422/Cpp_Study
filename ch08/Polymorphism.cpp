/*
 * 다형성(Polymorphism)
 * 지금까지 설명한 가상함수의 호출관계에서 보인 특성을 가리켜 '다형성'이라고 한다.
 * 그리고 이는 C++, 아니 객체지향을 설명하는데 있어서 매우 중요한 요소이기도 하다.
 * '다형성'이란 '동질이상(同質異像)'을 의미한다.
 * "모습은 같은데 형태는 다르다." == "문장은 같은데 결과는 다르다."
 */
#include <iostream>
using namespace std;

class First{
    public:
        virtual void SimpleFunc(){
            cout<<"First"<<endl;
            }
};

class Second : public First{
    public:
        virtual void SimpleFunc(){
            cout<<"Second"<<endl;
        }
};

int main(void){
    First * ptr = new First();
    ptr->SimpleFunc();  // 아래에 동일한 문장이 존재한다.
    delete ptr;

    ptr=new Second();
    ptr->SimpleFunc();  // 아래에 동일한 문장이 존재한다.
    delete ptr;
    return (0);
}

// 위의 main 함수에는 다음의 문장이 두 번 등장한다.
// ptr->SimpleFunc();
// 그런데 ptr은 동일한 포인터 변수이다. 그럼에도 불구하고 실행결과는 다르다.
// 포인터 변수 ptr이 참조하는 객체의 자료형이 다르기 때문이다.
// 이것이 C++에서의 '다형성'이다.