#include <iostream>
using namespace std;

class AAA{
    private:
        int num;
    public:
        AAA(int n=0) : num(n){
            cout<<"AAA(int n=0)"<<endl;
        }
        AAA(const AAA& ref) : num(ref.num){
            cout<<"AAA(const AAA& ref)"<<endl;
        }
        AAA operator=(const AAA& ref){
            num = ref.num;
            cout<<"operator=(const AAA& ref)"<<endl;
            return *this;
        }
};

class BBB{  // 이니셜라이저 이용한 멤버 초기화
    private:
        AAA mem;
    public:
        BBB(const AAA& ref) : mem(ref){}
};

class CCC{  // 대입연산을 이용해서 멤버를 초기화하고 있다.
    private:
        AAA mem;
    public:
        CCC(const AAA& ref) {
            mem = ref;
        }
};

int main(void){
    AAA obj1(12);
    cout<<"******************************"<<endl;
    BBB obj2(obj1);
    cout<<"******************************"<<endl;
    CCC obj3(obj1);
    return (0);
}

/*
 * "이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성된다."
 * AAA mem = ref;
 * "생성자의 몸체부분에서 대입연산을 통한 초기화를 진행하면, 선언과 초기화를 각각 별도의 문장에서 진행하는 형태로 바이너리 코드가 생성된다."
 * CCC(const AAA& ref) { mem=ref; }
 */