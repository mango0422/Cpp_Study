#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void){
    int seed1 = time(NULL), seed2 = 0;
    srand(seed1);
    int num1  = rand() % 99 + 1;
    int num2  = rand() % 99 + 1;
    int num3  = rand() % 99 + 1;
    int num4  = rand() % 99 + 1;
    int num5  = rand() % 99 + 1;
    cout<<"num1 : "<<num1<<endl;
    cout<<"num2 : "<<num2<<endl;
    cout<<"num3 : "<<num3<<endl;
    cout<<"num4 : "<<num4<<endl;
    cout<<"num5 : "<<num5<<endl;
    cout<<endl<<endl<<"The Seed Number was : "<<seed1<<endl;
    return (0);
}