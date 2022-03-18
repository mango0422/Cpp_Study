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
        friend Point& operator--(Point &ref);   // 20행에 정의된 전역함수에 대해 friend 선언하고 있다.
        Point& operator-(){
            xpos = -xpos;
            ypos = -ypos;
            return *this;
        }
        Point& operator~(){
            int a = xpos;
            xpos = ypos;
            ypos = a;
            return *this;
        }
};

Point& operator--(Point &ref){  // -- 연산자가 멤버함수 형태로 오버로딩 되었다.
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

int main(void){
    Point pos1(1, 2);
    Point pos2 = -pos1;
    pos2.ShowPosition();
    pos1.ShowPosition();
    pos1 = -pos1;
    Point pos3 = ~pos1;
    pos3.ShowPosition();
    return (0);
}