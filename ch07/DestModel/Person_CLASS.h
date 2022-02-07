#ifndef _Person_H_
#define _Person_H_

#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        char * name;
    public:
        Person(const char * myname){
            name = new char[strlen(myname) + 1];
            strcpy(name, myname);
        }
        ~Person(){
            delete []name;
        }
        void WhatYourName() const{
            cout<<"My name is "<<name<<endl;
        }
};

#endif