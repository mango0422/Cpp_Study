/*
 * 1. 계좌개설
 * 2. 입금
 * 3. 출금
 * 4. 계좌정보 전체 출력
 * 5. 프로그램 종료
*/

#include <iostream>
#include <cstring>
#include "Adder.h"

Account accArr[100];    // Account 저장을 위한 배열
int accNum = 0;

int main(void){
    int choice;

    while(1){
        ShowMenu();
        cout<<"선택: ";
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