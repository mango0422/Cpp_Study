/*
 * 파일이름 : Account.h
 * 작성자 : 서용준
 * 업데이트 정보 : [2020. 04.25] 파일버전 0.8
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account{
    private:
        int accID;
        int balance;
        char * cusName;
    public:
        Account(int ID, int money, char * name);
        Account(const Account& ref);
        Account& operator=(const Account& ref); // 추가된 문장

        int GetAccID() const;
        virtual void Deposit(int money);
        int Withdraw(int money);
        void ShowAccInfo() const;
        ~Account();
};

#endif