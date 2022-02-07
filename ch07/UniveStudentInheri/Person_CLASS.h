#ifndef __Person_H_
#define __Person_H_

#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        int age;
        char name[50];
    public:
        Person(int myage, const char * myname) : age(myage){
            strcpy(name, myname);
        }
        void WhatYouName() const{
            cout<<"My name is "<<name<<endl;
        }
        void HowOldAreYou() const{
            cout<<"I'm "<<age<<" years old."<<endl;
        }
};
#endif