#ifndef __ACOUNT_H__
#define __ACOUNT_H__

class Account{
    private:
        int accID;
        int balance;
        char * cusName;
    public:
        Account(int ID, int money, char * name);
        Account(const Account & ref);

        int GetAccID() const;
        virtual void Deposit(int money);
        int withdraw(int money);
        void ShowAccInfo() const;
        ~Account();
};

#endif