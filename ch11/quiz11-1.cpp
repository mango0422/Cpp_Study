#include <iostream>
#include <cstring>
using namespace std;

class Gun{
    private:
        int bullet;
    public:
        Gun(int bnum) : bullet(bnum){}
        void Shot(){
            cout<<"BBANG!"<<endl;
            bullet--;
        }
};

class Police{
    private:
        int handcuffs;
        Gun * pistol;
    public:
        Police(int bnum, int bcuff) : handcuffs(bcuff){
            if(bnum>0){
                pistol=new Gun(bnum);
            }
            else{
                pistol=NULL;
            }
        }
        void PutHandcuff(){
            cout<<"SNAP!"<<endl;
            handcuffs--;
        }
        void Shot(){
            if(pistol==NULL){
                cout<<"Hut BBANG!"<<endl;
            }
            else{
                pistol->Shot();
            }
        }
        ~Police(){
            if(pistol!=NULL){
                delete pistol;
            }
        }
        Police(const Police& ref) : handcuffs(ref.handcuffs){
            if(ref.pistol!=NULL){
                pistol=new Gun(*(ref.pistol));
            }
            else{
                pistol=NULL;
            }
        }
        Police& operator=(const Police& ref){
            if(pistol!=NULL){
                delete pistol;
            }
            if(ref.pistol!=NULL){
                pistol=new Gun(*(ref.pistol));
            }
            else{
                pistol=NULL;
            }
            handcuffs=ref.handcuffs;
            return *this;
        }
};

int main(void){
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();
    Police pman2 = pman1;
    pman2.Shot();
    pman2.PutHandcuff();

    // Police pman2(0, 3);
    // pman2.Shot();
    // pman2.PutHandcuff();

    Police pman3(0, 0);
    pman3 = pman1;
    pman3.Shot();
    pman3.PutHandcuff();
    return (0);
}

/*
 * quiz11-1의 핵심
 * 1. 피상속 클래스는 기본 복사생성자를 사용한다.
 * 2. 상속 클래스는 피상속 클래스 멤버값의 기본 복사생성자를 이용한다.
 */