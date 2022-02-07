/*
 * 1. ���°���
 * 2. �Ա�
 * 3. ���
 * 4. �������� ��ü ���
 * 5. ���α׷� ����
*/

#include <iostream>
#include <cstring>
#include "Adder.h"

Account accArr[100];    // Account ������ ���� �迭
int accNum = 0;

int main(void){
    int choice;

    while(1){
        ShowMenu();
        cout<<"����: ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return (0);
            default:
                cout<<"Illegal selection.."<<endl;
        }
    }
    
    return (0);
}