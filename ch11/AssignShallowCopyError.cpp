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
            cout<<"�̸�: "<<name<<endl;
            cout<<"����: "<<age<<endl;
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
 * ����Ʈ ���� �������� �������� ���� �����ϴ�.
 * �������� �� ���� 29�࿡ ���ؼ� ����Ǵ� ���� ���翡 �ִ�.
 * ����Ʈ ���� �����ڴ� ��� �� ����� �ܼ��� ���縸 �Ѵ�.
 * ������ ������ ���� �Ҵ��� �ϴ� ���, ����Ʈ ���� �����ڴ� �� ���� ������ ����Ű�Ƿ� ������ ���·� ���� ���� �����ڸ� �����ؾ� �Ѵ�.
 * "���� ���縦 �����ϵ��� �����Ѵ�"
 * "�޸� ������ �߻����� �ʵ���, ���� ���翡 �ռ� �޸� ������ ������ ��ģ��."
 */