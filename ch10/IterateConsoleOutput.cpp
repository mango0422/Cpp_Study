#include <iostream>

namespace mystd{
    using namespace std;
    
    class ostream{
        public:
            ostream& operator<< (char *str){    // cout 객체의 참조값을 반환하는 형태로 확장하였다.
                printf("%s", str);
                return *this;
            }
            ostream& operator<< (char str){
                printf("%c", str);
                return *this;
            }
            ostream& operator<< (int num){
                printf("%d", num);
                return *this;
            }
            ostream& operator<< (double a){
                printf("%g", a);
                return *this;
            }                                   // cout 객체의 참조값을 반환하는 형태로 확장하였다.
            ostream& operator<< (ostream& (*fp)(ostream &ostm)){
                return fp(*this);
            }
    };
    ostream& endl(ostream &ostm){   // endl 함수는 인자로 전달된 객체의 참조값을 반환하므로, 반환된 값을 재 반환하는 형태로 연산자를 오버로딩 하였다.
        ostm<<'\n';
        fflush(stdout);
        return ostm;                // endl 함수는 인자로 전달된 객체의 참조값을 반환하므로, 반환된 값을 재 반환하는 형태로 연산자를 오버로딩 하였다.
    }
    ostream cout;
};

int main(void){
    using mystd::cout;
    using mystd::endl;
    cout<<3.14<<endl<<123<<endl;
    return (0);
}