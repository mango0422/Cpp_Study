// 가상함수 말고도 virtual 키워드를 붙여줘야 할 대상이 하나 더 있다.
// 그건 바로 소멸자이다. 즉, virtual 선언은 소멸자에도 올 수 있다.
#include <iostream>
#include <cstring>
using namespace std;

class First{
    private:
        char * strOne;
    public:
        First(char * str){
            strOne = new char[strlen(str) + 1];  // First 클래스의 생성자에서 동적 할당이 있었기 때문에 소멸자가 적절히 정의되었다.
        }
        ~First(){
            cout<<"~First()"<<endl;
            delete []strOne;  // First 클래스의 생성자에서 동적 할당이 있었기 때문에 소멸자가 적절히 정의되었다.
        }
};

class Second : public First{
    private:
        char * strTwo;
    public:
        Second(char * str1, char * str2) : First(str1){
            strTwo = new char[strlen(str2) + 1];
        }
        ~Second(){
            cout<<"~Second()"<<endl;
            delete []strTwo;
        }
};

int main(void){
    First * ptr=new Second("simple", "complex");
    delete ptr;
    return (0);
}