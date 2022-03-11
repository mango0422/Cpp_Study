#include <iostream>
#include <cstring>
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
        friend Point operator-(const Point &pos1, const Point &pos2);
        friend Point operator+=(const Point &pos1, const Point&pos2);
        friend Point operator-=(const Point &pos1, const Point &pos2);
        friend bool operator==(const Point &pos1, const Point &pos2);
        friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2){
    Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}

Point operator-(const Point &pos1, const Point &pos2){
    Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
    return pos;
}

Point* operator+=(Point &pos1, Point &pos2){
    pos1=pos1+pos2;
    return &pos1;
}

Point* operator-=(Point &pos1, Point &pos2){
    pos1=pos1-pos2;
    return &pos1;
}

bool operator==(const Point &pos1, const Point &pos2){
    if(pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos){
        return true;
    }
    else{
        return false;
    }
}

bool operator!=(const Point &pos1, const Point &pos2){
    return !(pos1==pos2);
}

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3=pos1+pos2; // pos = pos1.operator+(pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    pos3=pos1-pos2; // pos = pos1.operator-(pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    pos1 += pos2; // pos1 = pos1.operator+=(pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    pos1 -= pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    Point pos4(4, 4);
    Point pos5(4, 4);
    Point pos6(4, 6);
    Point pos7(5, 4);
    cout<<boolalpha<<(pos4==pos5)<<endl;
    cout<<boolalpha<<(pos4==pos6)<<endl;
    cout<<boolalpha<<(pos4==pos7)<<endl;

    cout<<boolalpha<<(pos4!=pos5)<<endl;
    cout<<boolalpha<<(pos4!=pos6)<<endl;
    cout<<boolalpha<<(pos4!=pos7)<<endl;

    return (0);
}

/*
 * 오버로딩이 불가능한 연산자의 종류
 * .                멤버 접근 연산자
 * .*               멤버 포인터 연산자
 * ::               범위 지정 연산자
 * ?:               조건 연산자(3항 연산자)
 * sizeof           바이트 단위 크기 계산
 * typeid           RTTI 관련 연산자
 * static_cast      형변환 연산자
 * dynamic_cast     형변환 연산자
 * const_cast       형변환 연산자
 * reinterpret_cast 형변환 연산자
 */

/*
 * 위 연산자들의 오버로딩을 제한하는 이유는 c++의 문법규칙을 보존하기 위해서이다.
 * 만약 위의 연산자들까지 오버로딩을 허용해 버린다면, C++의 문법 규칙에 어긋나는 문장의 구성이 가능해지고, 이는 C++을 보다 혼란스러운 언어로 만들 수 있기 때문이다.
 * 참고로, 위의 연산자들을 오버로딩 해야만 하는 상황이 딱히 존재하지 않기 대문에 여러분도 필자와 마찬가지로 이들 연산자에 대해서는 오버로딩을 하고픈 생각조차 들지 않을 것이다. 그럼 이어서 멤버함수 기반으로만 오버로딩이 가능한 연산자를 소개하겠다.
 * 
 * =    대입연산자
 * ()   함수 호출 연산자
 * []   배역 접근 연산자(인덱스 연산자)
 * ->   멤버 접근을 위한 포인터 연산자
 * 
 * 이들은 객체를 대상으로 진행해야 의미가 통하는 연산자들이기 때문에, 멤버함수 기반으로만 연산자의 오버로딩을 허용한다.
 */  

/* 
 * 연산자를 오버로딩 하는데 있어서의 주의사항
 * 
 * 1.본래의 의도를 벗어난 형태의 연산자 오버로딩은 좋지 않다.
 *  - 연산자 오버로딩은 잘못 사용하면 프로그램을 복잡하고, 이해하기 어렵게 만든다는 단점이 있다.
 *      "pos1 + pos2"     (pos1과 pos2는 Point 객체다.)
 * pos1과 pos2의 멤버 별로 덧셈을 해서 그 결과로 객체를 만들어서 반환하는 연산으로 이해할 것이다.
 * 그러나 이러한 우리의 기대를 져버리고 pos1의 값을 pos2의 값만큼 증가시킨 다던지, 아니면 진짜 엉뚱하게, 연산의 결과로 pos2의 멤버변수에 저장된 값이 변경된다면, 프로그램의 코드를 상식적으로 이해할 수 없다.
 * 2.연산자의 우선순위와 결합성은 바뀌지 않는다.
 * 연산자가 갖는 연산의 기능은 오버로딩 되어도, 연산자가 지니는 우선순위와 결합성은 그대로 따르게 되어 있다. (그렇지 않으면 대혼란)
 * 3.매개변수의 디폴트 값 설정이 불가능하다.
 * 피연산자의 자료형에 따라서 연산자를 오버로딩 한 함수의 호출이 결정되므로 매개변수의 디폴트 값 설정 안됨.
 * 4.연산자의 순수 기능까지 빼앗을 수는 없다.
 *      int operator+(const int num1, const int num2){
 *          return num*num2;
 *      }
 * int형 데이터의 +연산은 이미 그 의미가 정해져 있다.
 * 연산자의 기본 기능을 변경하는 형태의 연산자 오버로딩은 허용되지 않는다.
 */