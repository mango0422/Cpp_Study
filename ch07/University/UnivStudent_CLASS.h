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
 * 1. UnivStudent Ŭ������ �����ڴ� Person Ŭ������ ������� �ʱ�ȭ�ؾ� �� �ǹ��� �ִ�.
 * 2. UnivStudent Ŭ������ �����ڴ�, Person Ŭ������ �����ڸ� ȣ���ؼ� Person Ŭ������ ����� �ʱ�ȭ�ϴ� ���� ����.
*/