/*
 * new 연산자는 다음 두 가지의 형태로 오버로딩이 가능하다.
 * 
 * void * operator new (size_t size) { .... }
 * void * operator new[] (size_t size) { .... }
 * 
 * 첫 번째 함수는 앞서 설명한 것이고, 두 번째 함수는 new 연산자를 이용한 배열할당 시 호출되는 함수이다.
 * 즉, 다음의 문장을 만나면,
 * 
 * Point * arr = new Point[3];
 * 
 * 컴파일러는 세 개의 Point 객체에 필요한 메모리 공간을 바이트 단위로 계산해서, 이를 인자로 전달하면서 다음 함수를 호출한다.
 * 
 * void * opeator new[] (size_t size) { .... }
 * 
 * 즉, 배열할당 시 호출되는 함수라는 사실을 제외하고는 operator new 함수와 차이가 없다.
 * 마찬가지로 delete 연산자도 다음 두 가지의 형태로 오버로딩이 가능하다.
 * 
 * void operator delete (void * adr) { .... }
 * void operator delete[] (void * adr) { .... }
 * 
 * 첫 번째 함수는 앞서 설명한 것이고, 두 번째 함수는 delete 연산자를 이용한 배열소멸 시 호출되는 함수이다.
 * 즉, 다음의 문장을 만나면,
 * 
 * delete []arr;
 * 
 * 컴파일러는 소멸자를 호출한 이후에 arr에 저장된 주소 값을 전달하면서 다음 함수를 호출한다.
 * 
 * void operator delete[] (void * adr) { .... }
 * 
 * 이렇듯, 이 함수 역시도 배열소멸 시 호출되는 함수라는 사실을 제외하면, operator delete 함수와 차이가 없다.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0) : xpos(x), ypos(y){}
        friend ostream& operator<<(ostream& os, const Point &pos);

        void * operator new (size_t size){
            cout<<"operator new : "<<size<<endl;
            void * adr = new char[size];
            return adr;
        }
        void * operator new[] (size_t size){
            cout<<"operator new[] : "<<size<<endl;
            void * adr = new char[size];
            return adr;
        }
        void operator delete (void * adr){
            cout<<"operator delete()"<<endl;
            delete []adr;
        }
        void operator delete[] (void * adr){
            cout<<"operator delete[] ()"<<endl;
            delete []adr;
        }
};

ostream& operator<<(ostream& os, const Point &pos){
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

int main(void){
    Point * ptr = new Point(3, 4);
    Point * arr = new Point[3];
    delete ptr;
    delete []arr;
    return (0);
}