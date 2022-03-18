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
        Point& operator++(){
            xpos+=1;
            ypos+=1;
            return *this;
        }
        const Point operator++(int){ // 후위 증가
            const Point retobj(xpos, ypos); // const Point retobj(*this);
            xpos+=1;
            ypos+=1;
            return retobj;
        }
        friend Point &operator--(Point &ref);
        friend const Point operator--(Point &ref, int);
};

Point &operator--(Point &ref){  // 전위 감소
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

const Point operator--(Point &ref, int){    // 후위 감소
    const Point retobj(ref); // const 객체라 한다.
    ref.xpos-=1;
    ref.ypos-=1;
    return retobj;  // 멤버의 값이 증가하기 이전에 만들어둔 복사본을 반환하고 있다. 이것이 후위증가의 효과를 내는 방법이다.
}

int main(void){
    Point pos1(3,5);
    Point cpy;
    cpy=pos1--;
    cpy.ShowPosition();
    pos1.ShowPosition();

    cpy=pos1++;
    cpy.ShowPosition();
    pos1.ShowPosition();
    return (0);
}

/*
 * 반환형에서 const 선언과 const 객체
 * const Point operator++(int){
 *     const Point retobj(xpos, ypos);  // 함수 내에서 retobj의 변경을 막겠다!
 *     xpos+=1;
 *     ypos+=1;
 *     return retobj;
 * }
 * 
 * 
 * const Point operator--(Point &ref, int){
 *     const Point retobj(ref);  // 함수 내에서 retobj의 변경을 막겠다!
 *     ref.xpos-=1;
 *     ref.ypos-=1;
 *     return retobj;
 * }
 * 
 * 
 */