/*
 * C++에서는 객체간의 대입연산을 허용한다.
class Number{
    private:
        int num;
    public:
        Number(int n=0) : num(n){}
        void ShowNumber(){
            cout<<num<<endl;
        }
};

int main(void){
    Number num1(100);
    Number num2(0);
    num2=num1;          // 동일 자료형의 객체간 대입연산
    num2.ShowNumber();  // 100이 출력된다!
    return (0);
}

 * 물론 두 객체의 자료형이 일치할 때에만 대입연산이 가능하다.
 * 이는 오버로딩 된 대입 연산자를 통해서 충분히 설명한 내용이므로 더 이상 설명하지 않겠다.
 * 그렇다면 객체와 정수간의 대입연산도 가능할까?
 * 즉, 위의 Number 클래스를 대상으로 다음과 같이 main 함수를 구성해도 컴파일 및 실행이 가능할까?
 int main(void){
     Number num;
     num = 30;
     num.ShowNumber();
     return (0);
 }
 * 코드만 놓고 보면 안될 것 같지만, 이 역시 컴파일 및 실행에 무리가 없다.
 * 그럼 어떠한 과정을 거쳐서 위의 대입연산이 완료되는지 확인할 수 있는 예제를 하나 제시하겠다.
 */

#include <iostream>
using namespace std;

class Number{
    private:
        int num;
    public:
        Number(int n=0) : num(n){
            cout<<"Number(int n=0)"<<endl;
        }
        Number& operator=(const Number& ref){   // 굳이 대입연산자를 오버로딩 할 필요가 없는 상황이지만, 대입 연산자의 호출을 확인하기 위해서 오버로딩 함. 문자열을 출력하는 것 말고는 디폴트 대입 연산자와 차이가 없음.
            cout<<"operator=()"<<endl;
            num=ref.num;
            return *this;
        }
        void ShowNumber(){
            cout<<num<<endl;
        }
};

int main(void){
    Number num;
    num = 30;   // 서로 다른 두 자료형의 피연산자를 대상으로 대입연산을 진행함. 출력되는 문자열을 보면 이 연산이 어떻게 진행되는지 알 수 있음.
    num.ShowNumber();
    return (0);
}

/*
 * num=Number(30);  // 1단계. 임시객체의 생성
 * num.operator=(Number(30));   // 2단계. 임시객체를 대상으로 하는 대입 연산자의 호출
 * "A형 객체가 와야 할 위치에 B형 데이터(또는 객체)가 왔을 경우, B형 데이터를 인자로 전달받는 A형 클래스의 생성자 호출을 통해서 A형 임시객체를 생성한다."
 * 때문에 위의 예제에서는 'Number형 객체가 와야 할 위치에 int형 데이터가 와서, int형 데이터를 인자로 전달받는 Number 클래스의 생성자 호출을 통해서 Number형 임시객체를 생성한 것'이다.
 * 그리고 나서 두 Number 객체를 대상으로 대입연산을 진행하였다.
 * 이렇듯, 기본 자료형 데이터를 객체로 형 변환하는 것은 적절한 생성자의 정의를 통해서 얼마든지 가능하다.
 * 반대로, 객체를 기본 자료형 데이터로 형 변환하는 것도 가능하다.
 */