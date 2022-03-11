/* 
 * 증가, 감소 연산자의 오버로딩
 * 대표적인 단항 연산자 2가지 :
 * 1 증가 연산자 ++
 * 1 감소 연산자 --
 * 
 * ++pos;       // pos는 Point 객체! Point 클래스에 ++ 연산자가 오버로딩 되어있다고 가정.
 * "호출되는 함수의 이름은 ++연산자와 키워드 operator를 연결해서 완성되므로, operator++입니다."
 * 
 * pos.operator++(); // 멤버함수이 형태라면, pos의 멤버함수가 호출되는 형태이니, 이와 같이 해석되어야 한다.
 * 
 * operator++(pos); // 전역함수의 경우는 피연산자가 모두 인자로 전달되므로, 이와 같은 형태로 해석이 된다.
 * 
 * 다음 에제에서는 증가 연산자와 감소 연산자를 오버로딩 한다.
 * 이 중 하나는 멤버함수를 기반으로, 다른 하나는 전역함수를 기반으로 연산자를 오버로딩 하였다.
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
        Point& operator++(){    // ++ 연산자가 멤버함수 형태로 오버로딩 되었다.
            xpos+=1;
            ypos+=1;
            return *this;
        }
        friend Point& operator--(Point &ref);   // 37행에 정의된 전역함수에 대해 friend 선언하고 있다.
};

Point& operator--(Point &ref){  // -- 연산자가 멤버함수 형태로 오버로딩 되었다.
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

int main(void){
    Point pos(1, 2);
    ++pos;  // pos.operator++();로 해석됨.
    pos.ShowPosition();
    --pos;  // operator--(pos); 로 해석됨.
    pos.ShowPosition();

    ++(++pos);  // ++(pos.operator++()); -> (pos의 참조 값).operator++();
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();
    return (0);
}