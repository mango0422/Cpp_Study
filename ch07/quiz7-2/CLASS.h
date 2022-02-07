#ifndef _CLASS_H_
#define _CLASS_H_

#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo{
    private:
        char * name;
        int age;
    public:
        MyFriendInfo(){}
        MyFriendInfo(const char * myname, const int myage) : age(myage){
            name = new char[strlen(myname) + 1];
            strcpy(name, myname);
        }
        void ShowMyFriendInfo() const{
            cout<<"이름: "<<name<<endl;
            cout<<"나이: "<<age<<endl;
        }
        ~MyFriendInfo() {
            delete []name;
            cout<<"------name deleted------"<<endl;
        }
};

class MyFriendDetailInfo : public MyFriendInfo{
    private:
        char * addr;
        char * phone;
    public:
        MyFriendDetailInfo(){}
        MyFriendDetailInfo(const char * myname, const int myage) : MyFriendInfo(myname, myage){}
        MyFriendDetailInfo(const char * myname, const int myage, const char * myaddr, const char * myphone)
        : MyFriendInfo(myname, myage){
            addr = new char[strlen(myaddr) + 1];
            strcpy(addr, myaddr);
            phone = new char[strlen(myphone) + 1];
            strcpy(phone, myphone);
        }
        void ShowMyFriendDetailInfo() const{
            ShowMyFriendInfo();
            cout<<"주소: "<<addr<<endl;
            cout<<"전화번호: "<<phone<<endl<<endl;
        }
        ~MyFriendDetailInfo(){
            delete []addr;
            delete []phone;
            cout<<"------addr/phone deleted-------"<<endl;
        }
};

#endif