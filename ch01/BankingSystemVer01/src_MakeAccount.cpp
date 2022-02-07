#include "Adder.h"
#include <iostream>
#include <cstring>

extern int accNum;
extern Account accArr[];

void MakeAccount(void){
    int ID;
    char name[NAME_LEN];
    int balance;
    
    cout<<accNum<<endl;

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: "; cin>>ID;
    for(int i = 0; i < accNum; i++){
        if(accArr[i].accID == ID){
            cout<<"이미 있는 계좌ID입니다. 다시 입력하시오."<<endl;
            cout<<"계좌ID: "; cin>>ID;
        }
    }
    cout<<"이름: "; cin>>name;
    cout<<"입금액: "; cin>>balance;
    accArr[accNum].accID = ID;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;

    cout<<accNum<<endl;
}