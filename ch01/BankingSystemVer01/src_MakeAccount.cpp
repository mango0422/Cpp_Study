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

    cout<<"[���°���]"<<endl;
    cout<<"����ID: "; cin>>ID;
    for(int i = 0; i < accNum; i++){
        if(accArr[i].accID == ID){
            cout<<"�̹� �ִ� ����ID�Դϴ�. �ٽ� �Է��Ͻÿ�."<<endl;
            cout<<"����ID: "; cin>>ID;
        }
    }
    cout<<"�̸�: "; cin>>name;
    cout<<"�Աݾ�: "; cin>>balance;
    accArr[accNum].accID = ID;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;

    cout<<accNum<<endl;
}