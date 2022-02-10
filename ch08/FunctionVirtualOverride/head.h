#ifndef __Header_H_
#define __Header_H_
#include <iostream>
#include <cstring>
using namespace std;

class First{
    public:
        virtual void MyFunc(){
            cout<<"FirstFunc"<<endl;
        }
};

class Second: public First{
    public:
        virtual void MyFunc(){
            cout<<"SecondFunc"<<endl;
        }
};

class Third: public Second{
    public:
        virtual void MyFunc(){
            cout<<"ThirdFunc"<<endl;
        }
};

#endif