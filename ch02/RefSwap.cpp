#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2){
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(void){
    int val1 = 10;
    int val2 = 20;
    cout<<"Before change..."<<endl<<"val1 : "<<val1<<endl<<"val2 : "<<val2<<endl;
    
    SwapByRef2(val1, val2);
    cout<<"After change..."<<endl<<"val1 : "<<val1<<endl<<"val2 : "<<val2<<endl;
    return (0);
}