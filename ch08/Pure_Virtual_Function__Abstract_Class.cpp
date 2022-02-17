#include <iostream>
#include <cstring>
using namespace std;

// class Employee{
//     private:
//         char name[100];
//     public:
//         Employee(const char * name){ strcpy(this->name, name); }
//         void ShowYourName() const{ cout<<"name: "<<name<<endl; }
//         virtual int GetPay() const{ return (0); }
//         virtual void ShowSalaryInfo() const{}
// };


// 위 클래스는 기초 클래스로서만 의미를 가질 뿐, 객체의 생성을 목적으로 정의된 클래스는 아니다.
// 이렇듯 클래스 중에서는 객체생서을 목적으로 정의되지 않는 클래스도 존재한다.

int main(void){
    // Employee * emp = new Employee("Lee Dong Sook");
    // 이러한 문장이 만들어진다면, 이는 프로그래머의 실수가 틀림이 없다.
    // 하지만, 문법적으로 아무런 문제가 없는 문장이기 때문에, 이러한 실수는 컴파일러에 의해서 발견되지 않는다.
    // 이러한 경우에는 다음 코드에서 보이듯이, 가상함수를 '순수 가상함수'로 선언하여 객체의 생성을 문법적으로 막는 것이 좋다.
    return (0);
}

class Employee{
    private:
        char name[100];
    public:
        Employee(const char * name){ strcpy(this->name, name); }
        void ShowYourName() const{ cout<<"name: "<<name<<endl; }
        virtual int GetPay() const = 0; // 순수 가상함수
        virtual void ShowSalaryInfo() const = 0; // 순수 가상함수
};

// '순수 가상함수'란 '함수의 몸체가 정의되지 않은 함수' 를 의미한다
// 그리고 이를 표현하기 위해서, 위에서 보이듯이 '0의 대입'을 표시한다.
// 그런데 이것은 0의 대입을 의미하는 게 아니고, '명시적으로 몸체를 정의하지 않았음'을 컴파일러에게 알리는 것이다.
// 따라서 컴파일러는 이 부분에서 함수의 몸체가 정의되지 않았다고 컴파일 오류를 일으키지 않는다.
// 그러나 Employee 클래스는 순수 가상함수를 지닌, 완전하지 않은 클래스가 되기 때문에 다음과 같이 객체를 생성하려 들면 컴파일 에러가 발생한다. : Employee * emp = new Employee("Lee Dong Sook");
// 첫 번재 이점 - 잘못된 객체의 생성을 막을 수 있다.
// 두 번째 이점 - Employee 클래스의 GetPay 함수와 ShowSalaryInfo 함수는 유도 클래스에 정의된 함수가 호출되게끔 돕는데 의미가 있었을 뿐, 실제로 실행이 되는 함수는 아니었는데, 이를 보다 명확히 명시하는 효과도 얻게 되었다.
// 그리고 이렇듯 하나 이상의 멤버함수를 순수 가상함수로 선언한 클래스를 가리켜 '추상 클래스(abstract class)'라 한다.
// 추상클래스 = 완전하지 않은, 그래서 객체생성이 불가능한 클래스