/*
 * 스마트 포인터란 말 그대로 똑똑한 포인터이다.
 * 우리가 알고 있는 포인터는 자기 스스로 하는 일이 아무것도 없지만 스마트 포인터는 자기 스스로 하는 일이 존재하는 포인터이다.
 * 사실 스마트 포인터는 객체이다. (포인터의 역할을 하는 객체)
 * 따라서 구해야 할 대상이 아닌, 구현해야 할 대상인 것이다.
 * 여기서는 스마트 포인터에 대한 개념을 설명한다.
 * 따라서 라이브러리에서 제공하는 스마트 포인터의 사용방법을 설명하지 않고, 간단한 그리고 좀 더 덜 똑똑한 스마트 포인터를 직접 구현해 본다.
 * 이는 이후에 프로그램의 개발을 목적으로 라이브러리에서 제공하는 스마트 포인터를 사용할 때 큰 도움이 될 것이다.
 * 예제를 통해 스마트 포인터를 정의해보자.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){
            cout<<"Point 객체 생성"<<endl;
        }
        ~Point(){
            cout<<"Point 객체 소멸"<<endl;
        }
        void SetPos(int x, int y){
            xpos=x;
            ypos=y;
        }
        friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

class SmartPtr{
    private:
        Point * posptr;
    public:
        SmartPtr(Point * ptr) : posptr(ptr){}      
        Point& operator*()const{
            return *posptr;
        }
        Point* operator->()const{
            return posptr;
        }
        ~SmartPtr(){
            delete posptr;
        }
};

int main(void){
    SmartPtr sptr1(new Point(1, 2));
    SmartPtr sptr2(new Point(2, 3));
    SmartPtr sptr3(new Point(4, 5));    
    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;

    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr3->SetPos(50, 60);
    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;

    return (0);
}

/* 
 * 
 *
 */