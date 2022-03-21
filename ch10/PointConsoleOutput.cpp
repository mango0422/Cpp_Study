/*
 * Point 클래스를 대상으로 << 연산자와 >> 연산자를 오버로딩 해 보고자 한다.
 * 다음과 같은 유형의 연산이(출력이) 가능하게 하고자 한다.
 * int main(void){
 *     Point pos(3,4);
 *     cout<<pos<<endl;     // [3, 4] 출력!
 *     ....
 * }
 * 1. cout은 ostream 클래스의 객체이다.
 * 2. ostream은 이름공간 std 안에 선언되어 있으며, 이의 사용을 위해서는 헤더파일 <iostream>을 포함해야 한다.
 * 
 */

#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){}
        void ShowPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
        friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& os, const Point& pos){ // os를 통해 cout를 받고, pos는 pos1이 된다.
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

int main(void){
    Point pos1(1, 3);
    cout<<pos1;
    Point pos2(101, 303);
    cout<<pos2;
    return (0);
}


/*
 * ostream 객체는 point 객체를 출력할 수 없다.
 * 누가 먼저 만들어졌는가? ostrema 객체이다.
 * cout<<pos1; -> operator<<(cout, pos1);
 * 
 */