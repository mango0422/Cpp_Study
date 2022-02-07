#include <iostream>
#include <cstring>
using namespace std;

class Printer{
    private:
        char str[100];
    public:
        void SetString(char *strg);
        void ShowString();
};

void Printer::SetString(char *strg){
    strcpy(str, strg);
}

void Printer::ShowString(){
    cout<<str<<endl;
}

int main(void){
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return(0);
}