#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray{
    private:
        int * arr;
        int arrlen;
        BoundCheckIntArray(const BoundCheckIntArray& arr){}
        BoundCheckIntArray& operator=(const BoundCheckIntArray& arr){}
    public:
        BoundCheckIntArray(int len) : arrlen(len){
            arr=new int[len];
        }
        int& operator[] (int idx){
            if(idx < 0 || idx>=arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int& operator[] (int idx) const {
            if(idx < 0 || idx>=arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int GetArrLen() const{
            return arrlen;
        }
        ~BoundCheckIntArray(){
            delete []arr;
       }
};

void ShowAllData(const BoundCheckIntArray& ref){
    int len = ref.GetArrLen();
    for(int idx = 0; idx < len; idx++){
        cout<<ref[idx]<<endl;
    }
}

int main(void){
    BoundCheckIntArray arr(5);
    for(int i=0; i<5; i++){
        arr[i]=(i+1)*11;
    }
    ShowAllData(arr);
    return (0);
}

/*
 * 22행: const 멤버함수가 추가되었다. 이 함수는 15행에 정의된 함수와 오버로딩의 관계를 자기며, 참조값이 아닌, 배열요소의 값을 단순히 반환하는 형태로 정의되었다.
 * 40행: const 참조자를 이용한 연산이니, 22행에 정의된 const 함수가 호출된다.
 * 49행: const로 선언되지 않은 arr을 이용한 연산이니, 15행에 정의된 함수가 호출된다.
 * const 기반의함수 오버로딩이 유용하게 사용될 수 있음을 보여주는 예제로 기억하자.
 */