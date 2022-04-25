#include <iostream>
using namespace std;

class Number{
    private:
        int num;
    public:
        Number(int n=0) : num(n){
            cout<<"Number(int n=0)"<<endl;
        }
        Number& operator=(const Number& ref){
            cout<<"operator=()"<<endl;
            num=ref.num;
            return *this;
        }
        operator int (){    // 형 변환 연산자의 오버로딩
            return num;
        }
        void ShowNumber(){
            cout<<num<<endl;
        }
};

int main(void){
    Number num1;
    num1 = 30;
    Number num2 = num1+20;
    num2.ShowNumber();
    
    return (0);
}

/*
 * 위 예제에서 정의한 형 변환 연산자는 다음과 같다.
 * operator int (){
 *     return num;
 * }
 * 이렇듯 형 변환 연산자는 반환형을 명시하지 않는다.
 * 하지만 return문에 의한 값의 반환은 얼마든지 가능하다.
 * 그리고 오버로딩 된 연산자의 이름이 operator+ 이면, + 연산자가 등장했을 때 호출되는 것과 유사하게 operator int는 다음의 의미로 이해하면 된다.
 * (물론 int 대신에 다른 자료형의 이름이 올 수 있다.)
 * "int형으로 변환해야 하는 상황에서 호출되는 함수이다."
 * 
 * 즉, int형으로 형 변환되어야 하는 상황에서 호출이 되며, 이 때 return문에 의해 반환되는 값이 int형으로의 형 변환 결과가 되는 것이다.
 * 그래서 다음 문장의 실행과정에서
 * Number num2 = num1 + 20;
 * num1 객체의 operator int 함수가 호출되어, 이 때 반환되는 값 30과 20의 덧셈연산이 진행되며, 이 연산의 결과로 num2 객체가 생성된 것이다.
 * 이로써 길고 길었던 연산자 오버로딩에 대한 이론적인 설명을 마치고 다음 Chapter에서는 이를 이용해서 String 클래스를 직접 정의해 보겠다.
 */
