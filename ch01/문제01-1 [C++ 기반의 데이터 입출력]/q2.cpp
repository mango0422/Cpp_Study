#include <iostream>

int main(void){
    char phone[15];
    char name[100];
    std::cout<<"전화번호 : "<<std::endl;
    std::cin>>phone;
    std::cout<<"이름 : "<<std::endl;
    std::cin>>name;
    std::cout<<"전화번호 : "<<phone<<std::endl;
    std::cout<<"이름 : "<<name<<std::endl;
    return (0);
}