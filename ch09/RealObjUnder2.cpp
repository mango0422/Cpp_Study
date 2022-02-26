#include <iostream>
using namespace std;

// 클래스 Data를 흉내 낸 영역
typedef struct Data{
    int data;
    void (*ShowData)(Data*);
    void (*Add)(Data*, int);
} Data;

void ShowData(Data* THIS) {
    cout<<"Data: "<<THIS->data<<endl;
}
void Add(Data *THIS, int num) {
    THIS->data+=num;
}

// 적절히 변경된 main 함수
int main(void){
    Data obj1 = {15, ShowData, Add}; // obj1과 obj2를 객체라 할 때, 이 두 객체는 ShowData 함수와 Add 함수를 공유하는 셈이 된다.
    Data obj2 = {7, ShowData, Add}; // 이 두 함수를 이용해서 멤버인 함수 포인터 변수를 초기화했으니 말이다.

    obj1.Add(&obj1, 17); // obj1과 obj2에 존재하는 멤버함수 Add를 호출하는 것처럼 보이지 않는가?
    obj2.Add(&obj2, 9);
    obj1.ShowData(&obj1); // 마찬가지로 멤버함수 ShowData를 호출하는 것처럼 보인다.
    obj2.ShowData(&obj2);

    return (0);
}

// Data 클래스를 흉내 낸 것일 뿐, Data 클래스 자체가 될 순 없다.
// 함수 포인터에 대한 지식이 있어야 한다.