#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        char * name;
        int age;
    public:
        Person(const char * myname, int myage){
            int len=strlen(myname)+1;
            name=new char[len];
            strcpy(name, myname);
            age=myage;
        }
        void ShowPersonInfo() const{
            cout<<"이름: "<<name<<endl;
            cout<<"나이: "<<age<<endl;
        }
        ~Person(){
            delete []name;
            cout<<"called destructor!"<<endl;
        }
};

int main(void){
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yui", 22);
    man2=man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return (0);
}

/*
 * 디폭트 복사 생성자의 문제점과 많이 유사하다.
 * 문제점은 위 예제 29행에 의해서 진행되는 얕은 복사에 있다.
 * 디폴트 대입 연산자는 멤버 대 멤버를 단순히 복사만 한다.
 * 생성자 내에서 동적 할당을 하는 경우, 디폴트 대입 연산자는 두 가지 문제를 일으키므로 다음의 형태로 직접 대입 연산자를 정의해야 한다.
 * "깊은 복사를 진행하도록 정의한다"
 * "메모리 누수가 발생하지 않도록, 깊은 복사에 앞서 메모리 해제의 과정을 거친다."
 */