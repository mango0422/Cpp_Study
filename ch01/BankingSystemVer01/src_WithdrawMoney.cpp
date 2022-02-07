#include "Adder.h"
#include <iostream>
#include <cstring>

extern Account accArr[];    // Account 저장을 위한 배열
extern int accNum;

void WithdrawMoney(void){
    cout<<"[출   금]"<<endl;
    int ID, balance;
    cout<<"계좌ID: "; cin>>ID;
    for(int i = 0; i < accNum; i++){
        if(accArr[i].accID == ID){
            cout<<"출금액 : "; cin>>balance;
            accArr[i].balance -= balance;
            cout<<"출금완료"<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID입니다."<<endl;
}