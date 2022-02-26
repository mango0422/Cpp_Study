// 모델이 되는 예제
#include <iostream>
#include <cstring>
using namespace std;

class Data{
    private:
        int data;
    public:
        Data(int num) : data(num){}
        void ShowData(){
            cout<<"Data: "<<data<<endl;
        }
        void Add(int num){
            data+=num;
        }
};

int main(void){
    Data obj(15);
    obj.Add(17);
    obj.ShowData();
    return (0);
}