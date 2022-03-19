/*
 * 다음은 C++의 콘솔 입출력에 사용되는 cout과 endl의 이해를 돕기 위한 예제이다.
 * 이 예제에서는 cout와 endl을 아주 조금 흉내내서 이 둘에 대한 이해를 돕고 있다.
 * 이미 앞에서 한번씩은 언급했던 내용을 기반으로 구현 된 예제이므로 여러분 스스로 이해할 수 있을 것이다.
 */

#include <iostream>
namespace mystd{  // cout과 endl을 직접 구현하기 위해 선언한 이름공간이다.
    using namespace std;    // 이 using 선언은 이름공간 mystd 내에서 지역적으로 이뤄졌으니, 이 지역 내에서만 유효한 선언이 된다.
                            // 그리고 이 선언은 c언어의 표준함수인 printf 함수의 호출을 위해서 삽입되었다.
    class ostream{
        public:
            void operator<< (char * str){
                printf("%s", str);
            }
            void operator<< (char str){
                printf("%c", str);
            }
            void operator<< (int num){
                printf("%d", num);
            }
            void operator<< (double e){
                printf("%g", e);
            }
            void operator<< (ostream& (*fp)(ostream &ostm)){
                fp(*this);
            }
    };

    ostream& endl(ostream &ostm){   // endl은 이렇듯 함수의 형태를 띈다. 그리고 34행에서 보이듯이 버퍼를 비우는 작업까지 함께 진행한다.
        ostm<<'\n';
        fflush(stdout);
        return ostm;
    }

    ostream cout;
};  
// 여기서 보이듯이 cout은 객체의 이름이며, 이 객체 내에서는 다양한 기본 자료형 데이터를 대상으로 << 연산자를 오버로딩 하고 있다.
// 특히 26행에 정의된 함수의 경우, 31행에 정의된 함수를 인자로 전달받을 수 있도록 정의되어 있다.
// 만약에 26행에 정의된 함수의 매개변수 형이 낯설다면, C언어의 함수포인터 부분을 참고하기 바란다.

int main(void){
    using mystd::cout; // 이름공간 mystd 내에 선언된 cout과 endl의 사용을 위해서 지역적으로 using 선언을 하였다.
    using mystd::endl; // 따라서 main 함수 내에서의 cout과 endl은 이름공간 mystd 내에 선언된 것을 의미하게 된다.

    cout<<"Simple String";  // cout.operator<<("Simple String");
    cout<<endl; // cout.operator<<(endl);
    cout<<3.14; // cout.operator<<(3.14);
    cout<<endl; // cout.operator<<(endl);
    cout<<123;  // cout.operator<<(123);
    endl(cout); // endl(cout) -> cout.operator<<(endl);

    return (0);
}