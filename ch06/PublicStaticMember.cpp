#include <iostream>
using namespace std;

class SoSimple{
    public:
        static int simObjCnt;
    public:
        SoSimple(){
            simObjCnt++;
        }
};
int SoSimple::simObjCnt=0;

int main(void){
    cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체"<<endl;
    // 현재 SoSimple 객체 생성 하나도 안한 상태. 클래스 이름만 이용해서 simObjCnt에 접근. -> static 멤버변수가 객체 내에 존재하지 않음을 증명== 어디서든 접근 가능
    SoSimple sim1;
    SoSimple sim2;

    cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체"<<endl;
    cout<<sim1.simObjCnt<<"번째 SoSimple 객체"<<endl;       // 추천x. 멤버변수에 접근하는 것과 같은 오해를 불러일으키기 때문.
    cout<<sim2.simObjCnt<<"번째 SoSimple 객체"<<endl;       // 추천x. 멤버변수에 접근하는 것과 같은 오해를 불러일으키기 때문.
    // 20~22행은 모두 동일한 변수에 접근해서 동일한 출력을 보이게 됨.
    return (0);
}