#include "Adder.h"
#include <iostream>
#include <cstring>

extern int accNum;
extern Account accArr[];

void ShowAllAccInfo(void){
    for(int i = 0; i < accNum; i++){
        cout<<"����ID : "<<accArr[i].accID<<endl;
        cout<<"�� �� : "<<accArr[i].cusName<<endl;
        cout<<"�� �� : "<<accArr[i].balance<<endl<<endl;
    }   
}