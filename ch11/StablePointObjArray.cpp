/*
 * 이번에 설명할 내용은 "객체의 저장을 위한 배열 클래스의 정의" 이며, 다양한 예제를 제시한다는 측면에서 의미를 갖는다.
 * 앞서 보인 예제가 기본 자료형 대상의 배열 클래스였기 때문에, 객체 대상의 클래스를 제시하고자 한다.
 * 클래스 객체를 저장할 수 있는 배열 클래스를 정의하되, 다음의 두 가지 형태로 각각 정의해보고자 한다.
 * 1. Point 객체의 주소 값을저장하는 배열 기반의 클래스
 * 2. Point 객체를 저장하는 배열 기반의 클래스
 * 저장 대상이 객체냐, 아니면 객체 주소 값이냐에 차이가 있는 것이다.
 * 먼저, Point 객체를 저장하는 베열 기반의 클래스를 보이겠다.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){}
        friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

class BoundCheckPointArray{
    private:
        Point * arr;
        int arrlen;

        BoundCheckPointArray(const BoundCheckPointArray& arr){ }
        BoundCheckPointArray& operator=(const BoundCheckPointArray& arr){ }

    public:
        BoundCheckPointArray(int len) : arrlen(len){
            arr=new Point[len]; // Point 객체로 이뤄진 배열을 생성하고 있다. 인자를 받지 않는 void 생성자의 호출을 통해서 배열요소를 이루는 객체가 생성되므로, 10행에 정의된 생성자에 설정된 디폴트 값에 의해 객체의 모든 멤버가 0으로 초기화된다.
        }
        Point& operator[] (int idx){
            if(idx<0 || idx>=arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        Point operator[] (int idx) const{
            if(idx<0 || idx>=arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int GetArrLen() const{
            return arrlen;
        }
        ~BoundCheckPointArray(){
            delete []arr;
        }
};

int main(void){
    BoundCheckPointArray arr(3);
    arr[0]=Point(3, 4); // 임시객체를 생성해서 배열요소를 초기화하고 있다.
    arr[1]=Point(5, 6); // 물론 초기화의 과정에서 디폴트 대입 연산자가 호출되어 멤버 대 멤버의 복사자 진행된다.
    arr[2]=Point(7, 8); // 저장의 대상이 객체라면, 여기서 보이는 것과 같이 대입 연산자를 통해서 객체에 저장된 값을 복사해야 한다.

    for(int i=0; i<arr.GetArrLen(); i++){
        cout<<arr[i];
    }
    
    return (0);
}