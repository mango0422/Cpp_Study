#include <iostream>

int main(void){
    int sell;
    
    for(int i = 0; i<3; i--){
        std::cout<<"�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
        std::cin>>sell;
        if(sell == -1){
            return (0);
        }
        else{
            std::cout<<"�̹� �� �޿� : "<<50 + (sell*0.12)<<std::endl;
        }
    }
}