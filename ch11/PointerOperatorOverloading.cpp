/*
 * 포인터를 기반으로 하는 연산자 모두를 포인터 연산자라 한다.
 * 그런데 그 중에서도 대표적인 포인터 연산자 둘은 다음과 같다.
 * ->   포인터가 가리키는 객체의 멤버에 접근
 * *    포인터가 가리키는 객체에 접근
 * 이 두 연산자의 오버로딩은 일반적인 연산자의 오버로딩과 크게 차이가 없으니(달리 말하면 차이가 좀 있다는 뜻이다.),
 * 그 자체만 가지고는 부담을 가질 필요가 없다.
 * 다만, 둘 다 피 연산자가 하나인 단항 연산자의 형태로 오버로딩 된다는 특징만 기억하면 된다.
 * 그럼 간단히 두 연산자를 오버로딩 해 보겠다.
 * 참고로 이어서 소개하는 예제는 포인터 연산자의 오버로딩 방식을 보여줄 뿐, 그 이상의 의미는 갖지는 않는다.
 * 하지만 이를 이해하는 것도 간단하지만은 않다.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

class Number{
    private:
        int num;
    public:
        Number(int n) : num(n){}
        void ShowData(){
            cout<<num<<endl;
        }
        Number * operator->(){
            return this;
        }
        Number& operator*(){
            return *this;
        }
};

int main(void){
    Number num(20);
    num.ShowData();

    (*num)=30;
    num->ShowData();
    (*num).ShowData();
    return (0);
}

/* 
 * 위의 예제에서 다음 두 문장은,
 * (*num)-30;   (*num).ShowData();
 * 각각 다음과 같이 해석이 된다.
 * 그리고 실제로 이렇게 문장을 구성해도 실행이 가능하다.
 * (num.operator*())=30;
 * (num.operator*()).ShowData();
 * 이는 오버로딩 된 다른 연산자들의 해석방법과 차이가 없으니 어려울게 없다.
 * 그런데 위 예제의 다음 문장에, num->ShowData();
 * 일반적인 해석의 방법을 적용하면 다음과 같이 된다.
 * num.opeartor->() ShowData();
 * 그런데 멤버함수 operator->()가 반환하는 것은 주소 값이니, ShowData 함수의 호출은 문법적으로 성립하지 않는다.
 * 때문에 반환되는 주소 값을 대상으로 적절한 연산이 가능하도록 -> 연사자를 하나 더 추가하여, 다음과 같이 해석을 진행한다.
 * num.operator->() -> ShowData();
 * operator-> 함수가 반환하는 것이 주소 값이니, 이를 통한 멤버의 접근을 위해서 -> 연산자를 하나 더 추가시켜서 해석한 것이다.
 * 
 * 이어서, 스마트 포인터에 대한 설명을 통해서 이 두 연산자가 어떻게 활용되는지 간단히 살펴보겠다.
 */