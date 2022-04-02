/*
 * 이번에는 배열요소에 접근할 때 사용하는 [] 연산자를 오버로딩 하고자 한다.
 * 이는 다른 연산자들과 달리 피연산자가 연산자 기호 안으로 들어가기 때문에 다소 어색하거나 생소하게 느낄 수 있다.
 * 또한 앞서 Chapter 10에서도 언급했듯이, 이 연산자는 연산의 기본 특성상 멤버함수 기반으로만 오버로딩 하도록 제한되어 있다.
 */

/*
 * C, C++의 기본 배열은 "경계검사를 하지 않는다"는 단점을 지닌다.
 * 때문에 다음과 같은 엉뚱한 코드가 만들어 질 수도 있다. 컴파일도 되고, 실행도 무리 없이 진행되기 때문이다.
 * 
 * int main(void){
 *     int arr[3]=(1, 2, 3);
 *     cout<<arr[-1]<<endl;     // 'arr의 주소 + sizeof(int) x -1'의 위치에 접근
 *     cout<<arr[-2]<<endl;     // 'arr의 주소 + sizeof(int) x -2'의 위치에 접근
 *     cout<<arr[3]<<endl;     // 'arr의 주소 + sizeof(int) x 3'의 위치에 접근
 *     cout<<arr[4]<<endl;     // 'arr의 주소 + sizeof(int) x 4'의 위치에 접근
 *     ....
 * }
 * 
 * 물론 이러한 특성이 유용하게 활용될 수도 있지만, 지금은 이러한 특성의 부정적 측면만을 고려해서 이야기를 전개하고자 한다.
 * 그리고 이러한 단점의 해결을 위해서 '배열 클래스' 라는 것을 디자인해 볼 텐데, 여기서 말하는 배열 클래스라는 것은 '배열의 역할을 하는 클래스'를 뜻하는 것이다.
 * 그런데 이에 앞서 배열요소의 접근에 사용되는 [] 연산자의 오버로딩에 대해서 조금 정리할 필요가 있다.
 * 
 * arrObject[2];
 * 
 * 여기서 arrObject가 객체의 이름이라고 가정할 때, 이 문장은 어떻게 해석이 되겠는가?
 * 1. 객체 arrObject의 멤버함수 호출로 이어진다.
 * 2. 연산자가 []이므로 멤버함수의 이름은 'operator[]'이다.
 * 3. 함수호출 시 전달되는 인자의 값은 정수 2이다.
 * 
 * int operator[] (int idx){....}
 * 따라서 arrObject는 arrObject.operator[](2); 와 같이 해석이 됨을 알 수 있다.
 * 
 * 그럼 먼저 배열 클래스를 정의해서 제시하겠다.
 * 배열 클래스는 지금까지 공부한 내용만으로도 충분히 정의가 가능하다.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray{
    private:
        int * arr;
        int arrlen;
    public:
        BoundCheckIntArray(int len) : arrlen(len){
            arr=new int[len];
        }
        int& operator[] (int idx){
            if(idx<0 || idx>=arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        ~BoundCheckIntArray(){
            delete []arr;
        }
};

int main(void){
    BoundCheckIntArray arr(5);
    for(int i=0; i<5; i++){
        arr[i]=(i+1)*11;
    }
    for(int i=0; i<6; i++){
        cout<<arr[i]<<endl;
    }
    return (0);
}