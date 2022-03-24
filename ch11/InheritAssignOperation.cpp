#include <iostream>
using namespace std;

class First{
    private:
        int num1, num2;
    public:
        First(int n1=0, int n2=0) : num1(n1), num2(n2){}
        void ShowData(){
            cout<<num1<<", "<<num2<<endl;
        }
        First& operator=(const First &ref){
            cout<<"First& operator=()"<<endl;
            num1=ref.num1;
            num2=ref.num2;
            return *this;
        }
};

class Second : public First{
    private:
        int num3, num4;
    public:
        Second(int n1, int n2, int n3, int n4) : First(n1, n2), num3(n3), num4(n4){}
        void ShowData(){
            First::ShowData();
            cout<<num3<<", "<<num4<<endl;
        }
        
        /*
        Second& operator=(const Second& ref){
            cout<<"Second& operator=()"<<endl;
            num3=ref.num3;
            num4=ref.num4;
            return *this;
        }
        */
        
};

int main(void){
    Second ssrc(111, 222, 333, 444);
    Second scpy(0, 0, 0, 0);
    scpy = ssrc;
    scpy.ShowData();
    return (0);
}

/*
 * 31~36행의 주석을 풀었을때 결과값이 다르다.
 * "유도 클래스의 대입 연산자 정의에서, 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입하지 않으면,
 *  기초 클래스의 대입 연산자는 호출되지 않아서, 기초 클래스의 멤버변수는 멤버 대 멤버의 복사 대상에서 제외된다.""
 * 때문에 유도 클래스의 대입 연산자를 정의해야 하는 상황에 놓이게 되면, 기초 클래스의 대입 연산자를 명시적으로 호출해야 한다.
 * 
 * First::operator=(ref);   // 기초 클래스의 대입 연산자 호출을 명령!
 * 
 * 그런데 상속을 공부한지가 제법 시간이 지났다면, 기초 클래스의 대입 연산자 호출문을 보면서 다음과 같이 질문할 수도 있겠다.
 * "ref는 Second형 참조자인데, 이를 First형 참조자로 매개변수를 선언한 operator= 함수의 인자로 전달이 가능한가요?"
 * 실제로 이러한 내용이 궁금하다면, 이는 상속과 관련해서 복습을 할 때가 되었다는 의미가 된다.
 * "C++에서, AAA형 참조자는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다."
 */