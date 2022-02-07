#ifndef _UnivStudent_H_
#define _UnivStudent_H_

#include "Person_CLASS.h"

class UnivStudent : public Person{
    private:
        char * major;
    public:
        UnivStudent(const char * myname, const char * mymajor) : Person(myname){
            major = new char[strlen(mymajor) + 1];
            strcpy(major, mymajor);
        }
        ~UnivStudent(){
            delete []major;
        }
        void WhoAreYou() const{
            WhatYourName();
            cout<<"My major is "<<major<<endl<<endl;
        }
};

#endif