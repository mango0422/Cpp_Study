#include <iostream>
using namespace std;

class CountryArea{
    public:
        const static int RUSSIA     = 1707540;
        const static int CANADA     = 998467;
        const static int CHINA      = 957290;
        const static int SOUTH_KOREA    = 9922; 
};

int main(void){
    cout<<"러시아 면적: "<<CountryArea::RUSSIA<<"㎢"<<endl; // 6~9행에 정의된 상수에 접근하기 위해 굳이 객체 생성 필요x. 이렇게 접근하는게 편하고, 접근하는 대상에 대한 정보 쉽게 노출하는 방법
    cout<<"캐나다 면적: "<<CountryArea::CANADA<<"㎢"<<endl; // 6~9행에 정의된 상수에 접근하기 위해 굳이 객체 생성 필요x. 이렇게 접근하는게 편하고, 접근하는 대상에 대한 정보 쉽게 노출하는 방법
    cout<<"중국 면적: "<<CountryArea::CHINA<<"㎢"<<endl; // 6~9행에 정의된 상수에 접근하기 위해 굳이 객체 생성 필요x. 이렇게 접근하는게 편하고, 접근하는 대상에 대한 정보 쉽게 노출하는 방법
    cout<<"한국 면적: "<<CountryArea::SOUTH_KOREA<<"㎢"<<endl; // 6~9행에 정의된 상수에 접근하기 위해 굳이 객체 생성 필요x. 이렇게 접근하는게 편하고, 접근하는 대상에 대한 정보 쉽게 노출하는 방법
    return (0);
}