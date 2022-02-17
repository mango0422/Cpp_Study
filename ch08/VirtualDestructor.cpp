// 가상함수 말고도 virtual 키워드를 붙여줘야 할 대상이 하나 더 있다.
// 그건 바로 소멸자이다. 즉, virtual 선언은 소멸자에도 올 수 있다.
#include <iostream>
#include <cstring>
using namespace std;

class First{
    private:
        char * strOne;
    public:
        First(const char * str){
            strOne = new char[strlen(str) + 1];  // First 클래스의 생성자에서 동적 할당이 있었기 때문에 소멸자가 적절히 정의되었다.
        }
        virtual ~First(){
            cout<<"~First()"<<endl;
            delete []strOne;  // First 클래스의 생성자에서 동적 할당이 있었기 때문에 소멸자가 적절히 정의되었다.
        }   
};

class Second : public First{
    private:
        char * strTwo;
    public:
        Second(const char * str1, const char * str2) : First(str1){
            strTwo = new char[strlen(str2) + 1];
        }
        virtual ~Second(){
            cout<<"~Second()"<<endl;
            delete []strTwo;
        }
};

int main(void){
    First * ptr=new Second("simple", "complex");
    delete ptr;
    return (0);
}

// 객체의 소멸을 FIrst형 포인터로 명령하니, First 클래스의 소멸자만 호출됨.
// 따라서 이러한 경우에는 메모리의 누수(leak)가 발생하게 됨.
// 그러니 객체의 소멸과정에서는 delete 연산자에 사용된 포인터 변수의 자료형에 상관없이 모든 소멸자가 호출되어야 한다.
// 그리고 이를 위해서는 다음과 같이 소멸자에 virtual 선언을 추가하면 된다.
// 가상함수와 마찬가지로 소멸자도 상속의 계층구조상 맨 위에 존재하는 기초 클래스의 소멸자만 virtual로 선언하면, 이를 상속하는 유도 클래스의 소멸자들도 모두 '가상 소멸자'로 선언디된다.
// 그리고 가상 소멸자가 호출되면, 상속의 계층구조상 맨 아래에 존재하는 유도 클래스의 소멸자가 대신 호출되면서, 기초 클래스의 소멸자가 순차적으로 호출된다.
// class First{
//     ...
//     public:
//         virtual ~First(){...}
// };

// class Second : public First{
//     ...
//     public:
//         virtual ~Second(){...}
// };

// class Third : public Second{
//     ...
//     public:
//         virtual ~Third(){...}
// };

// int main(void){
//     First * ptr = new Third();
//     delete ptr;
// }

// 위와 같이 실행하면, 다음 과정을 거치면서 모든 소멸자가 호출됨.
// 1. 객체 소멸과정에서 호출 : virtual ~First()
// 2. virtual 소멸자이므로 대신 호출 : virtual ~Third()
// 3. ~Third() 실행 후 이어서 실행 : virtual ~Second()
// 4. ~Second() 실행 후 이어서 실행 : virtual ~First() 