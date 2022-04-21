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