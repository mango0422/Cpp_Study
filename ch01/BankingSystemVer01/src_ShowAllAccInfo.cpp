#include "Adder.h"
#include <iostream>
#include <cstring>

extern int accNum;
extern Account accArr[];

void ShowAllAccInfo(void){
    for(int i = 0; i < accNum; i++){
        cout<<"°èÁÂID : "<<accArr[i].accID<<endl;
        cout<<"ÀÌ ¸§ : "<<accArr[i].cusName<<endl;
        cout<<"ÀÜ ¾× : "<<accArr[i].balance<<endl<<endl;
    }   
}