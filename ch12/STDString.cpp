#include <iostream>
#include <string>
using namespace std;

int main(void){
    string str1="I like ";
    string str2="string class";
    string str3=str1+str2;  // 8행 : string 객체간 덧셈연산 가능.

    cout<<str1<<endl;   // 10~12행 : string 클래스가 << 연산자에 대해서도 오버로딩 되어 있음 확인 가능.
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1+=str2; // 14~20행 : 14goddml += 연산의 결과로 문자열 str1의 끝에 문자열 str2가 덧붙여 졌음을 "동일 문자열!"이라는 문자열의 출력을 통해서 알 수 있다.
    if(str1==str3){
        cout<<"동일 문자열!"<<endl;
    }
    else{
        cout<<"동일하지 않은 문자열!"<<endl;
    }
    string str4;
    cout<<"문자열 입력: ";
    cin>>str4;
    cout<<"입력한 문자열: "<<str4<<endl;    // String 클래스는 >> 연산자에 대해서도 오버로딩이 되어 있다. 따라서 이러한 형태로 string 객체를 통해서 문자열을 입력 받는 것이 가능하다.
    return (0);
}

/*
 * 실제로 string 클래스는 위 예제에서 보여주는 것 이상의 기능을 지니고 있다. 그러나 우리의 목적은 이와 유사한 성격의 클래스를 직접 정의하는 것이므로, 이 정도로 마무리하고자 한다.
 */