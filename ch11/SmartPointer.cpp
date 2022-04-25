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
 * 43, 46행 : 스마트 포인터의 가장 기본은 이 두 함수의 정의에 있다.
 * 스마트 포인터는 포인터처럼 동작하는 객체이다.
 * 따라서 이 두 함수의 정의는 필수이다.
 * 그리고 정의의 형태도 여기서 크게 벗어나지 않는다.
 * 물론 스마트 포인터가 똑똑해 질수록 이 두 함수도 하는 일이 더 많아지겠지만, 기본적으로는 여기 정의된 형태의 일을 포함해서 정의하게 되어있다.
 * 
 * 42, 49행 : 생성자에서 동적 할당을 하지 않음에도 불구하고, 소멸자에서 delete 연산을 하는 것이 다소 생소하게 느껴질 수 있다.
 * 그런데 여기에는 생성자의 인자로 전달되는 주소 값은, new연산에 의해서 동적 할당된 객체의 주소 값이라는 가정이 포함되어 있다.
 * 
 * 55~57행 : Point 객체를 생성하면서, 동시에 스마트 포인터 SmartPtr 객체가 이를 가리키게끔 하고 있다.
 * 이로써 sptr1, sptr2, sptr3는 Point 객체를 가리키는 포인터처럼 동작한다.
 * 
 * 58~60행 : sptr1, sptr2, sptr3는 포인터처럼 *연산을 진행한다.
 * 
 * 62~64행 : 마찬가지로 sptr1, sptr2, sptr3는 포인터처럼 -> 연산을 진행한다.
 */

/*
 * 위의 예제에서 가장 중요한 사실은, Point 객체의 소멸을 위한 delete 연산이 자동으로 이뤄졌다는 사실이다.
 * 그리고 바로 이것이 스마트 포인터의 똑똑함이다.
 * 앞서 말했듯이 위 예제는 스마트 포인터에 대한 개념적인 이해를 돕기 위해 작성하였다.
 * 스마트 포인터는 전문 개발자들이 개발한 이후에도 오랜 시간 실무에 사용하면서 다듬어 가는 클래스이다.
 * 그래서 보통은 스마트 포인터를 개인적으로 구현해서 사용하는 경우는 드물며, 오랜 시간 다듬어진, 그래서 라이브러리의 일부로 포함되어 있는 스마트 포인터를 활용하는 경우가 대부분이다.
 * 또한 스마트 포인터도 그 성격에 따라서 종류가 여러 가지가 있으니, 라이브러리에 포함된 스마트 포인터를 사용하기 위해서도 공부가 필요하다.
 * 바로 그 공부를 돕기 위해서 필자는 이 책을 통해서 여러분에게 스마트 포인터를 소개하였다.
 */