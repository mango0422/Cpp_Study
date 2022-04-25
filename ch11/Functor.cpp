/*
 * 함수의 호출에 사용되는, 인자의 전달에 사용되는 ()도 연산자라는 사실을 알고 있는가?
 * 때문에 이 역시도 오버로딩이 가능한 연산자이다.
 * 그리고 이 연산자를 오버로딩 하면, 객체를 함수처럼 사용할 수 있게 된다.
 * 
 * 객체의 이름이 adder이고 이 객체에서 ()연산자가 멤버함수로 오버로딩 되어 있는 상태라면, 다음의 문장은 어떻게 해석이 될까?
 * adder(2, 4);
 * 우선 연산자가 ()이니 멤버함수의 이름은 operator이다
 * 그리고 함수에 전달되는 인자의 정보는 2와 4이니 이는 다음과 같이 해석이 된다.
 * adder.operator()(2, 4);
 * 이 내용만 알면 () 연산자의 오버로딩에 대해서는 더 설명할 게 없다.
 */

#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){}
        Point operator+(const Point& pos) const{
            return Point(xpos+pos.xpos, ypos+pos.ypos);
        }
        friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

class Adder{
    public:
        int operator()(const int& n1, const int& n2){
            return n1 + n2;
        }
        double operator()(const double& e1, const double& e2){
            return e1 + e2;
        }
        Point operator()(const Point& pos1, const Point& pos2){
            return pos1 + pos2;
        }
};

int main(void){
    Adder adder;
    cout<<adder(1, 3)<<endl;
    cout<<adder(1.5, 3.7)<<endl;
    cout<<adder(Point(3, 4), Point(7, 9));
    
    return (0);
}

/*
 * 22행 : Point 객체에 대한 +연산자를 오버로딩 하였다.
 * 23행 : Point형 임시객체를 생성과 동시에 반환하고 있다. 이렇듯 return 문에서도 임시객체를 생성과 동시에 반환하는 것이 가능하다.
 * 33행 : 이 클래스에서는 두 개의 숫자 또는 Point 객체에 대한 덧셈결과를 반환하도록 ()연산자가 총 3회 오버로딩 되었다.
 * 48,49행 : add라는 이름의 함수를 호출하고, 이 때 반환되는 값을 출력하는 모습이다. 즉, adder는 객체임에도 불구하고 함수처럼 동작한다.
 * 50행 : Point형 임시객체를 두 개 생섣ㅇ해서 함수의 인자로 전달하고 있다. 이렇듯, 함수의 호출문에서도 임시객체를 생성하는 것이 가능하다.
 */

/*
 * 위 예제에서 정의한 Adder 클래스와 같이 함수처럼 동작하는 클래스를 가리켜 "펑터(Functor)"라 한다.
 * 그리고 '함수 오브젝트(Function Object)'라고도 불린다.
 * 그런데 펑터라는 전문적인 표현에 비해 () 연산자의 오버로딩이나 펑터 자체를 이해하는 것은 그리 어려운 일이 아니다.
 */