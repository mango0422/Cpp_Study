#include <iostream>
using namespace std;

class A{
    public:
        int num;
        explicit A(int n) : num(n){};   // explicit 앞에 추가 시 컴파일러가 알아서 형변환 하는거 방지.
};

void printA(A a){
    cout<<a.num<<endl;  
}

int main(void){
    int n = 26;
    printA(A(n));   // 대신 여기서 수동으로 형변환 해주어야 함.
    return (0);
}