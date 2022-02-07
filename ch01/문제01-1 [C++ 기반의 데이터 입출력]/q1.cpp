#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void){
    int num[5], sum = 0;
    for(int i = 0; i<5; i++){
        std::cout<<i+1<<"번째 정수 입력: ";
        std::cin>>num[i];
        sum += num[i];
    }
    std::cout<<"합계: "<<sum<<std::endl;
    system("gcc -o q1.exe q1.cpp");
}