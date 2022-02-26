#include <iostream>
using namespace std;

class AAA{ // 하나 이상의 가상 함수를 포함하는 클래스에 대해서는 컴파일러가 '가상함수 테이블' 이란 것을 만든다.
    private:
        int num1;
    public:
        virtual void Func1(){ // 가상함수
            cout<<"Func1"<<endl;
        }
        virtual void Func2(){ // 가상함수
            cout<<"Func2"<<endl;
        }
};

class BBB: public AAA{
    private:
        int num2;
    public:
        virtual void Func1(){
            // AAA 클래스의 오버라이딩 된 가상함수 Fun1에 대한 정보가 존재하지 않는다. 즉, 오버라이딩 된 가상함수의 주소정보는 유도 클래스의 가상함수 테이블에 포함되지 않는다.
            // 때문에 오버라이딩 된 가상함수를 호출하면, 무조건 가장 마지막에 오버라이딩을 한 유도 클래스의 멤버함수가 호출되는 것이다.
            cout<<"BBB::Fucn1"<<endl;
        }
        void Func3(){
            cout<<"Func3"<<endl;
        }
};

int main(void){
    AAA * aptr = new AAA();
    aptr->Func1();

    BBB * bptr = new BBB();
    bptr->Func1();

    return (0);
}

/* 
 * <가상함수 테이블이 참조되는 방식>
 * 가상함수 테이블은 객체의 생성과 상관없이 메모리 공간에 할당된다.
 * 가상함수 테이블이 멤버함수의 호출에 사용되는 일종의 데이터이기 때문이다.
 */

// 가상함수 테이블이 생성되고, 이 테이블을 참조하여 호출될 함수가 결정되기 때문에 실행속도가 감소하기 마련이다.
// 하지만 그 속도 차이가 미미하고, 이러한 단점에도 불구하고 가상함수는 많은 장점을 제공하기 때문에 유용하게 활용되는 것이다.