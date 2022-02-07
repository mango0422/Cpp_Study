#include <iostream>

int main(void){
    int sell;
    
    for(int i = 0; i<3; i--){
        std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin>>sell;
        if(sell == -1){
            return (0);
        }
        else{
            std::cout<<"이번 달 급여 : "<<50 + (sell*0.12)<<std::endl;
        }
    }
}