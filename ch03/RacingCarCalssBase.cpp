#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST{
    enum{ ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2, ACC_STEP = 10, BRK_STEP = 10 };
}

class Car{
    private:
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;
    public:
        void InitMembers(char * ID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
};

void Car::InitMembers(char * ID, int fuel){
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}
void Car::ShowCarState(){
    cout<<"������ID : "<<Car::gamerID<<endl;
    cout<<"���ᷮ: "<<Car::fuelGauge<<"%"<<endl;
    cout<<"����ӵ�: "<<Car::curSpeed<<"km/s"<<endl;
}
void Car::Accel(){
    if(Car::fuelGauge<CAR_CONST::FUEL_STEP){
        return;
    }
    else{
        Car::fuelGauge -= CAR_CONST::FUEL_STEP;
    }
    if(Car::curSpeed>=CAR_CONST::MAX_SPD){
        return;
    }
    else{
        Car::curSpeed += CAR_CONST::ACC_STEP;
    }
}
void Car::Break(){
    if(Car::curSpeed<=0){
        return;
    }
    else{
        Car::curSpeed -= CAR_CONST::BRK_STEP;
    }
}

int main(void){
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return(0);
}