/*
 * new와 delete도 연산자이기 때문에 오버로딩이 가능하다.
 * 그래서 이 두 연산자의 오버로딩에 대해서 예를 보이겠다.
 * 또한 포인터 연산자를 오버로딩 하면서 개념적으로 어렵다고 이야기하는 '스마트 포인터(smart pointer)'와 '펑터(functor)'에 대해서도 간단히 설명하겠다.
 * 
 * new 연산자가 오버로딩 되어 있다면, new 연산자의 다음 3가지 기능 중
 * 1. 메모리 공간의 할당
 * 2. 생성자의 호출
 * 3. 할당하고자 하는 자료형에 맞게 반환된 주소 값의 형 변환
 * 
 * 1에 해당하는 메모리 공간의 할당만 오버로딩 할 수 있다. (나머지는 C++ 연산자에 의해 진행된다.)
 * 
 * void * operator new (size_t size){ .... };
 * 
 * 반환형은 반드시 void 포인터 형이어야 하고, 매개변수형은 size_t이어야 한다.
 * 그리고 이렇게 오버로딩 된 함수는 컴파일러에 의해서 호출이 이뤄진다.
 * 컴파일러는 Point 클래스를 대상으로 new 연산자가 오버로딩 된 상태에서 다음 문장을 만나면, 먼저 필요한 메모리 공간을 계산한다.
 * Point * ptr = new Point(3, 4);
 * 그리고 그 크기가 계산되면, operator new 함수를 호출하면서 계산된 크기의 값을 인자로 전달한다.
 * 여기서 중요한 것은 크기 정보는 바이트 단위로 계산되어 전달된다는 점이다.
 * 따라서 우리는 대략 다음의 형태로 operator new 함수를 정의해야 한다.
 * void * operator new (size_t size){
 *     void & ard=new char[size]
 *     return adr;
 * }
 * 
 * 컴파일러에 의해서, 필요한 메모리 공간의 크기가 바이트 단위로 계산되어서 인자로 전달되니, 크기가 1바이트인 char 단위로 메모리 공간을 할당해서 반환하였다.
 * 물론 이것이 operator new 함수의 전부라면, 굳이 new 연산자를 오버로딩 할 필요는 없다.
 * 하지만 이는 operator new 함수가 반드시 해야 할 일이 '메모리 공간의 할당'임을 알리기 위한 것이며, 여러분은 이 이상의 일을 하도록 operator new 함수를 정의해야 한다. (new 연산자를 오버로딩 했다면 말이다.)
 * 
 * 이렇게 해서 operator new 함수가 할당한 메모리 공간의 주소 값을 반환하면, 컴파일러는 생성자를 호출해서 메모리 공간을 대상으로 초기화를 진행한다.
 * 그리고는 마지막으로, 완성된 객체의 주소 값을 Point 클래스의 포인터 형으로 형 변환해서 반환을 한다.
 * 정리하면, 다음 문장에서 new 연산자가 반환하는 값은 operator new 함수가 반환하는 값이 아니다.
 * Point * ptr = new Point(3, 4);
 * operator new 함수가 반환하는 값은, 컴파일러에 의해 적절히 형 변환이 된 값이다.
 * 또한 생성자의 호출정보는 operator new 함수와 아무런 상관이 없다.
 * 생성자의 호출은 여전히 컴파일러의 몫이기 때문에 이 정보는 컴파일러에 의해서 참조될 뿐이다. 
 */

/*
 * Point * ptr = new Point(3, 4);
 * delete ptr;
 * 컴파일러는 먼저 ptr이 가리키는 객체의 소멸자를 호출한다.
 * 그리고는 다음의 형태로 정의된 함수에 ptr에 저장된 주소 값을 전달한다.
 * 
 * void operator delete(void * adr){ .... };
 * 따라서 delete 함수는 다음의 형태로 정의해야 한다.
 * 즉, 소멸자는 오버로딩 된 함수가 호출되기 전에 호출이 되니 오버로딩 된 함수에서는 메모리 공간의 소멸을 책임져야 한다.
 * 물론, 그 이외에 필요한 내용은 얼마든지 추가로 담을 수 있다.
 * void operator delete (void * adr){
 *     delete []adr;
 * }
 * 참고로, 사용하는 컴파일러에서 void 포인터 형 대상의 delete 연산을 허용하지 않는다면, 위의 delete 문을 다음과 같이 작성하면 된다.
 * 즉, char 포인터 형으로 변환해서 delete 연산을 진행하면 된다.
 * delete []((char*)adr);
 */

#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
        friend ostream& operator<<(ostream& os, const Point& pos);
        void * operator new (size_t size){
            cout<<"operator new : "<<size<<endl;
            void * adr = new char[size];
            return adr;
        }      
        void operator delete (void * adr){
            cout<<"opeartor delete()"<<endl;
            delete []adr;
        }
};

ostream& operator<<(ostream& os, const Point& pos){
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

int main(void){
    Point * ptr = new Point(3, 4);  // 아직 객체가 완성된 상태가 아닌데 어떻게 멤버함수의 호출이 가능했을까?
    cout<<*ptr;
    delete ptr;
    return (0);
}

/*
 * operator new 함수와 operator delete 함수가 static으로 선언된 함수라면, 가능하다.
 * 사실, operator new 함수와 operator delete 함수는 static 함수이다.
 * 비록 멤버함수의 형태로 선언을 해도 이 둘은 static 함수로 간주가 된다.
 * 그래서 객체생성의 과정에서 호출이 가능했던 것이다.
 * 여기까지가 new와 delete의 연산자 오버로딩에 대한 기본적인 설명이었다.
 */