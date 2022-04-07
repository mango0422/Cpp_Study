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
 * 이 경우, 30행의 const 선언으로 인해 33행이 원인이 되어 컴파일 에러가 발생한다.
 * 33행의 인덱스 연산은 ref.operator[ ] (idx);  와 같이 해석되며, 이때 호출되는 operator[] 함수는 const 함수가 아니기 때문이다.
 * const의 선언 유무도 함수 오버로딩의 조건에 해당하므로, operator[] 함수를 오버로딩 해야 한다.
 */