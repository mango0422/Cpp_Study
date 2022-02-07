#include <iostream>
#include <cstring>
using namespace std;

class Girl;     // Girl이라는 이름이 클래스의 이름임을 알림

class Boy{
    private:
        int height;
        friend class Girl;
    public:
        Boy (int len) : height(len){};
        void ShowYourFriendInfo(Girl &frn);     // Girl 클래스에 대한 Boy 선언
};

class Girl{
    private:
        char phNum[20];
    public:
        Girl(char *num){
            strcpy(phNum, num);
        }
        void ShowYourFriendInfo(Boy &frn);     // Boy 클래스에 대한 Girl 선언
        friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn){
    cout<<"Her phone number: "<<frn.phNum<<endl;
}

void Girl::ShowYourFriendInfo(Boy &frn){
    cout<<"His height: "<<frn.height<<endl;
}

int main(void){
    Boy boy(170);
    Girl girl("010-1234-5678");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
    return (0);
}