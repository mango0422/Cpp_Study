/*
 * 펑터는 함수 또는 객체의 동작방식에 유연함을 제공할 때 주로 사용된다.
 * 그럼 예제를 통해 펑터가 어떻게 사용될 수 있는지 보이도록 하겠다.
 * 참고로 이 예제에서는 '버블정렬(bubble sort)'이라는 정령 알고리즘이 사용된다.
 */

#include <iostream>
using namespace std;

class SortRule{
    public:
        virtual bool operator()(int num1, int num2) const =0;
};

class AscendingSort : public SortRule{
    public:
        bool operator()(int num1, int num2) const{
            if(num1>num2){
                return true;
            }
            else{
                return false;
            }
        }
};

class DescendingSort : public SortRule{
    public:
        bool operator()(int num1, int num2) const{
            if(num1<num2){
                return true;
            }
            else{
                return false;
            }
        }
};

class DataStorage{
    private:
        int * arr;
        int idx;
        const int MAX_LEN;
    public:
        DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen){
            arr=new int[MAX_LEN];
        }
        void AddData(int num){
            if(MAX_LEN<=idx){
                cout<<"더 이상 저장이 불가능합니다."<<endl;
                return;
            }
            arr[idx++]=num;
        }
        void ShowAllData(){
            for(int i=0; i<idx; i++){
                cout<<arr[i]<<' ';
            }
            cout<<endl;
        }
        void SortData(const SortRule& functor){
            for(int i=0; i<(idx-1); i++){
                for(int j=0; j<(idx-1); j++){
                    if(functor(arr[j], arr[j+1])){
                        int temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                }
            }
        }
};

int main(void){
    DataStorage storage(5);
    storage.AddData(40);
    storage.AddData(30);
    storage.AddData(50);
    storage.AddData(20);
    storage.AddData(10);

    storage.SortData(AscendingSort());
    storage.ShowAllData();

    storage.SortData(DescendingSort());
    storage.ShowAllData();

    return (0);
}

/*
 * 61행에 정의된 멤버함수는 다음의 형태를 띈다.
 * 
 * void SortData(const SortRule& functor){
 *  ....
 *     if(functor(arr[j], arr[j+1])){
 *         ....
 *     }
 * }
 * 매개변수형이 SortRule의 참조형이므로, SortRule 클래스를 상속하는 AscendingSort 클래스와 DescendingSort 클래스의 객체는 인자로 전달 가능하다.
 * 그리고 SortRule의 operator() 함수는 virtual로 선언되었으니, 유도 클래스의 operator() 함수가 대신 호출된다.
 * 때문에 펑터로 무엇이 전달되느냐에 따라서 정렬의 기준이 바뀌게 된다.
 * 그리고 이것어 펑터를 정의하는 이유이다.
 */