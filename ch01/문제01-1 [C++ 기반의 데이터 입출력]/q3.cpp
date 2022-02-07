#include <iostream>

int main(void){
    int num;
    std::cout<<"숫자 하나를 입력하시오 : ";
    std::cin>>num;
    for(int i = 0; i < 9; i++){
        std::cout<<num<<" x "<<i+1<<" = "<<num * (i + 1)<<std::endl;
    }

    return (0);
    
}