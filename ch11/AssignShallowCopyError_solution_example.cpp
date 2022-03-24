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
        Person& operator=(const Person &ref){
            delete []name;
            int len=strlen(ref.name)+1;
            name = new char[len];
            strcpy(name, ref.name);
            age = ref.age;
            return *this;
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
 * 대입 연산자의 오버로딩 결과를 제시하자면 위 Person& operator=(const Person &ref)와 같다.
 * 정상적인 실행의 결과를 얻을 수 있다.
 */