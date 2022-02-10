#include <iostream>
#include <cstring>
using namespace std;

class First{
    public:
        void MyFunc(){
            cout<<"FirstFunc"<<endl;
        }
};

class Second : public First{
    public:
        void MyFunc(){
            cout<<"SecondFunc"<<endl;
        }
};

class Third : public Second{
    public:
        void MyFunc(){
            cout<<"ThirdFunc"<<endl;
        }
};

int main(void){
    Third * tptr=new Third();
    Second * sptr=new Second();
    First * fptr=new First();

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;
    return (0);
}