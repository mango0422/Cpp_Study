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
            strOne = new char[strlen(str) + 1];
        }
};