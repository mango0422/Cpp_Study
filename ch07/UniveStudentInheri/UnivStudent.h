#ifndef _UnivStudent_H_
#define _UnivStudent_H_

#include "Person_CLASS.h"

class UnivStudent : public Person{
    private:
        char major[50]; // 전공과목
    public:
        UnivStudent(const char * myname, int myage, const char * mymajor) : Person(myage, myname){
            strcpy(major, mymajor);
        }
        void WhoAreYou() const{
            WhatYouName();
            HowOldAreYou();
            cout<<"My major is "<<major<<endl<<endl;
        }
};

#endif