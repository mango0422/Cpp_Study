#include "Adder.h"
#include <iostream>
#include <cstring>

extern int accNum;
extern Account accArr[];

void DepositMoney(void){
    cout<<"[��   ��]"<<endl;
    int ID, balance;
    cout<<"����ID: "; cin>>ID;
    for(int i = 0; i < accNum; i++){
        if(accArr[i].accID == ID){
            cout<<"�Աݾ� : "; cin>>balance;
            accArr[i].balance += balance;
            cout<<"�ԱݿϷ�"<<endl;
            return;
        }
    }
    cout<<"��ȿ���� ���� ID�Դϴ�."<<endl;
}