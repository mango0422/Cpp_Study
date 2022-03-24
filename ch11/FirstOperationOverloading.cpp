/*
 * 객체간 대입연산의 비밀: 디폴트 대입 연산자
 * 이전에 설명한 복사 생성자의 대표적인 특성:
 *  - 정의하지 않으면 디폴트 복사 생성자가 삽입된다.
 *  - 디폴트 복사 생성자는 멤버 대 멤버의 복사(얕은 복사)를 진행한다.
 * 생성자 내에서 동적 할당을 한다면, 그리고 깊은 복사가 필요하다면 직접 정의해야 한다.
 */

/*
 * 이어서 설명할 대입 연산자의 대표적인 특성:
 * 정의하지 않으면 디폴트 대입 연산자가 삽입된다.
 * 디폴트 대입 연산자는 멤버 대 멤버의 복사(얕은 복사)를 진행한다.
 * 연산자 내에서 동적 할당을 한다면, 그리고 깊은 복사가 필요하다면 직접 정의해야 한다.
 */

#include <iostream>
using namespace std;
#define _DEBUG

 class First{
	private:
		int num1, num2;
	public:
		First(int n1=0, int n2=0) : num1(n1), num2(n2) {}
		void ShowData(){
			cout<<num1<<", "<<num2<<endl;
		}
};

class Second{
	private:
		int num3, num4;
	public:
		Second(int n3=0, int n4=0) : num3(n3), num4(n4){}
		void ShowData(){
			cout<<"num3"<<", "<<num4<<endl;
		}
		Second& operator=(const Second& ref){
			cout<<"Second* operator=()"<<endl;	// 대입 연산자의 호출을 확인하기 위한 문자열 출력이다.
			num3=ref.num3;
			num4=ref.num4;
			return *this;
		}
};

int main(void){
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;	// fcpy.operator=(fsrc)로 해석된다. 이로 인해서 디폴트로 삽입된 대입 연산자가 호출된다.
	scpy = ssrc;	// scpy.operator=(ssrc)로 해석된다. 이로 인해서 38행에 정의된 대입 연산자가 호출된다.
	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;
	fob1=fob2=fsrc;	// 대입 연산자는 오른쪽에서 왼쪽으로 진행된다(결합방향에 의해). 따라서 이 문장이 실행된다는 사실을 통해서 디폴트 대입 연산자의 반환형을 유추할 수 있다.
	sob1=sob2=ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return (0);
}