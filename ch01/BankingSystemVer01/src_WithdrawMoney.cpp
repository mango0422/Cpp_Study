#include "Adder.h"
#include <iostream>
#include <cstring>

extern Account accArr[];    // Account ������ ���� �迭
extern int accNum;

void WithdrawMoney(void){
    cout<<"[��   ��]"<<endl;
    int ID, balance;
    cout<<"����ID: "; cin>>ID;
    for(int i = 0; i < accNum; i++){
        if(accArr[i].accID == ID){
            cout<<"��ݾ� : "; cin>>balance;
            accArr[i].balance -= balance;
            cout<<"��ݿϷ�"<<endl;
            return;
        }
    }
    cout<<"��ȿ���� ���� ID�Դϴ�."<<endl;
}