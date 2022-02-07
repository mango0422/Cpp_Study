#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Temporary{
    private:
        int num;
    public:
        Temporary(int n) : num(n){      // 클래스 생성자
            cout<<"create obj :"<<num<<endl;
        }
        ~Temporary(){       // 클래스 소멸자
            cout<<"destroy obj: "<<num<<endl;
        }
        void ShowTempInfo(){
            cout<<"My num is "<<num<<endl;
        }
};

int main(void){
    Temporary(100);             // 이것이 임시객체 직접 생성하는 방법. 이문장에 의해서 100으로 초기화된 Temporary 임시객체 생성됨.
    cout<<"********* after make!"<<endl<<endl;
    
    Temporary(200).ShowTempInfo();          // 임시객체 생성, 이어서 객체 대상으로 ShowTempInfo 함수 호출. 객체 생성 및 반환시,
                                            // 생성 및 반환된 위치에 객체를 참조할 수 잇는 참조 값이 반환되기 때문에 이러한 문장 구성 가능.
    cout<<"********* after make!"<<endl<<endl;

    const Temporary &ref = Temporary(300);      // 앞에서 생성한 다른 두 객체와 달리 여기서는 참조자 ref로 임시객체를 참조함.   
    cout<<"********* end of main!"<<endl<<endl;
    return (0);
}

/* 
 * Temporary(200).ShowTempInfo();
 * 클래스 외부에서 객체의 멤버함수를 호출하기 위해 필요한 것은 다음 세 가지 중 하나이다.
 * ● 객체에 붙여진 이름
 * ● 객체의 참조 값(객체 참조에 사용되는 정보)
 * ● 객체의 주소 값
 * (임시객체의 참조 값).ShowTempInfo();  // 임시객체가 생성된 위치에는 임시객체의 참조 값이 반환됨. 위 문장의 경우 먼저 임시객체가 생성되면서 다음의 형태가 됨.
 * const Temporary &ref = Temporary(300);       // 이 경우는 임시객체 생성시 반환되는 '참조 값'이 참조자 ref에 전달되어, ref가 임시객체를 참조하게 됨.
 * SimpleFuncObj(obj).AddNum(30).ShowData(); // 이와 같은 구성이 가능한 이유도, 실제로는 임시객체가 통째로 반환되어서가 아니라, 임시객체는 메모리에 저장되고, 그 객체의 참조 값이 반환되었기 때문.
 * 
 */