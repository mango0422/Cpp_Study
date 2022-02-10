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

    fptr->MyFunc();     // fptr이 First형 포인터이니, 이 포인터가 가리키는 객체를 대상으로 First 클래스에 정의된 MyFunc 함수는 무조건 호출할 수 있음.
    sptr->MyFunc();     // sptr이 Second형 포인터이니, 이 포인터가 가리키는 객체에는 First의 MyFunc 함수와  Second의 MyFunc 함수가 오버라이딩 관계로 존재. 오버라이딩을 한 Second의 MyFunc 함수를 호출.
    tptr->MyFunc();     // 오버라이딩한 Third의 MyFunc 함수가 호출이 됨.
    delete tptr;
    return (0);
}