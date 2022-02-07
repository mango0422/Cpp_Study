#include "Adder.h"
#include <iostream>
#include <cstring>

extern int accNum;
extern Account accArr[];

void DepositMoney(void){
    cout<<"[입   금]"<<endl;
    int ID, balance;
    cout<<"계좌ID: "; cin>>ID;
    for(int i = 0; i < accNum; i++){
        if(accArr[i].accID == ID){
            cout<<"입금액 : "; cin>>balance;
            accArr[i].balance += balance;
            cout<<"입금완료"<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID입니다."<<endl;
}