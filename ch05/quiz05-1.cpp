#include <iostream>
#include <cstring>
using namespace std;

class NameCard{
    private:
        char * name;
        char * code;
        char * number;
        int class_num;
    public:
        NameCard(char * myname, char * mycode, char * mynumber, int myclass_num) : class_num(myclass_num){
            name = new char(strlen(myname) + 1);
            strcpy(name, myname);
            code = new char(strlen(mycode) + 1);
            strcpy(code, mycode);
            number = new char(strlen(mynumber) + 1);
            strcpy(number, mynumber);
        }
        NameCard(NameCard &copy) : class_num(copy.class_num){
            name = new char(strlen(copy.name) + 1);
            strcpy(name, copy.name);
            code = new char(strlen(copy.code) + 1);
            strcpy(code, copy.code);
            number = new char(strlen(copy.number) + 1);
            strcpy(number, copy.number);
        }
        void ShowNameCardInfo() const{
            cout<<"Name: "<<name<<endl;
            cout<<"Code: "<<code<<endl;
            cout<<"Phone number: "<<number<<endl;
            char * classname;
            switch(class_num){
                case 1:
                    classname = new char(strlen("Clerk") + 1);
                    strcpy(classname, "Clerk");
                    cout<<"Current Class: "<<classname<<endl<<endl;
                    break;
                case 2:
                    classname = new char(strlen("Senior") + 1 );
                    strcpy(classname, "Senior");
                    cout<<"Current Class: "<<classname<<endl<<endl;
                    break;
                default:
                    cout<<"class_num is wrong"<<endl<<endl;
                    break;
            }
        }
        ~NameCard(){
            delete []name;
            delete []code;
            delete []number;
            cout<<"delete constructor!"<<endl;
        }
};

enum COMP_POS{ CLERK = 1, SENIOR = 2 };

int main(void){
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return (0);
}