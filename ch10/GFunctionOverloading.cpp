/* 
 * 연산자를 오버로딩 하는 방법에는 다음 두 가지가 있다.
 * 
 * 멤버함수에 의한 연산자 오버로딩
 * 전역함수에 의한 연산자 오버로딩
 * 
 * 앞서 보인 예제에서는 + 연산자를 멤버함수를 이용해서 오버로딩 하였다. 때문에 pos1+pos2는 다음과 같이 해석이 되었다.
 * 
 * pos1.operator+(pos2);
 * 
 * 그런데 + 연산자는 전역함수를 이용해서도 오버로딩이 가능하다.
 * 그리고 이렇게 전역함수를 이용해서 오버로딩을 하면 pos1+pos2는 다음과 같이 해석이 된다.
 * 
 * operator+(pos1, pos2)
 * 
 * 즉, 어떻게 오버로딩을 했느냐에 따라서 해석하는 방법이 다음과 같이 두 가지로 나뉘게 된다.
 * pos1+pos2; -> pos1.operator+(pos2); // 멤버함수로 오버로딩 된 경우
 *            -> operator+(pos1, pos2); // 전역함수로 오버로딩 된 경우
 * 
 * 동일한 자료형을 대상으로 + 연산자를 전역함수 기반으로, 그리고 멤버함수 기반으로 동시에 오버로딩 할 경우, 멤버함수 기반으로 오버로딩 된 함수가 전역함수 기반으로 오버로딩 된 함수보다 우선시 되어 호출된다.
 * 단, 일부 오래된 컴파일러는 이러한 상황에서 컴파일 에러를 발생시키기도 하니, 이러한 상황은 가급적 만들지 않는 게  좋다.
 * 자! 그럼 예제를 통해서 + 연산자를 전역함수 기반으로 오버로딩 해보겠다.
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
        friend Point operator+(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2){
    Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3=pos1+pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    return (0);
}