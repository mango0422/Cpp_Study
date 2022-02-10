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

    /*
        함수를 오버라이딩 했다는 것은, 해당 객체에서 호출되어야 하는 함수를 바꾼다는 의미
        but, 포인터 변수의 자료형에 따라서 호출되는 함수의 종류가 달라지는 것은 문제가 있어 보임.

        EmployeeManager 에서 앞서 우리가 정의한 SalesWorker 클래스의 경우에도 급여의 계산방식이 다르기 때문에 GetPay 함수를 오버라이딩 하였음.
        but, 포인터의 자료형을 이유로 PermanentWorker 클래스의 GetPay 함수가 대친 호출되어서 급여가 결정된다면, 이에 대해서는
        "판매실적에 따른 상여금"을 지급하지 않는 상황이 됨.
        그래서 C++은 이러한 상황이 발생하지 않도록 '가상함수'라는 것을 제공함. -> 객체지향의 개념. (C++의 개념이 아님.)
        
    */
}