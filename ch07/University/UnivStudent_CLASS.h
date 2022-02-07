#include "Person_CLASS.h"

class UnivStudent : public Person{
    private:
        char major[500];
    public:
        UnivStudent(char * myname, int myage, char * mymajor):Person(myage, myname){
            strcpy(major, mymajor);
        }
        void WhoAreYou() const{
            WhatYourName();
            HowOldAreYou();
            cout<<"My major is "<<major<<endl<<endl;
        }
};

/*
 * 1. UnivStudent 클래스의 생성자는 Person 클래스의 멤버까지 초기화해야 할 의무가 있다.
 * 2. UnivStudent 클래스의 생성자는, Person 클래스의 생성자를 호출해서 Person 클래스의 멤버를 초기화하는 것이 좋다.
*/