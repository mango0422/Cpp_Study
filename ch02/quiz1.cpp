#include <iostream>
using namespace std;

void ChangeSign(int & num1){
    num1 *= -1;
    cout<<num1<<endl;
}

void PlusOne(int & num1){
    num1 += 1;
    cout<<num1<<endl;
}

int main(void){
    int num1 = 1995;
    int num2 = 1999;
    cout<<"num1 : "<<endl;
    ChangeSign(num1);
    cout<<"num1 : "<<endl;
    PlusOne(num1);
    cout<<"num2 : "<<endl;
    ChangeSign(num2);
    cout<<"num2 : "<<endl;
    PlusOne(num2);
}