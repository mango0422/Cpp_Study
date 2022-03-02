/*
 * 함수가 오버로딩 되면, 오버로딩 된 수만큼 다양한 기능을 제공하게 된다.
 * 이름은 하나이지만 기능은 여러 가지가 되는 셈이다.
 * 마찬가지로 연산자의 오버로딩을 통해서, 기존에 존재하던 연산자의 기본 기능 이외에 다른 기능을 추가할 수 있다.
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
        Point operator+(const Point &ref){   // operator+라는 이름의 함수
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
};

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3=pos1.operator+(pos2); // pos1+pos2가 pos1.operator+(pos2)의 다른 표현일거야
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return (0);
}

/*
 * c++은 객체도 기본 자료형 변수처럼 덧셈,뺄셈, 혹은 곱셈과 같은 연산들을 가능하게 하려 함.
 * 'operator' 키워드와 '연산자' 를 묶어서 함수의 이름을 정의하면, 함수의 이름을 이용한 함수의 호출뿐만 아니라, 연산자를 이용한 함수의 호출도 허용.
 * pos1 + pos2라는 연산이 있지만, pos1이 객체인경우, pos1.operator+(pos2)라는 문장으로 해석.
 * 즉, 객체를 피연산자로 상요한 연산자의 이름 앞에  operator라는 이름을 붙여서 완성되는 이름의 함수를 호출함.
 * 만약, operator-라는 함수가 있는경우, pos1-pos2 라는 연산은 pos1.operator-(pos2)라는 문장으로 해석이 된다.
 * 
 * 연산자의 오버로딩 방법에는 멤버함수에 의한 방법과 전역함수에 의한 방법이 있다.
 */