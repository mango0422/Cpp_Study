#ifndef __CARINLINE_H__
#define __CARINLINE_H__

#include <iostream>
using namespace std;

namespace CAR_CONST{
    enum{
        MAX_SPD = 200, BRK_STEP = 10, ACC_STEP = 10, Fuel_STEP = 2, ID_LEN = 20
    };
}

class Car{
    private:
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;
    public:
        void InitMembers(char * gamerID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
};

inline void Car::ShowCarState(){
    cout<<"소유자ID : "<<Car::gamerID<<endl;
    cout<<"연료량 : "<<Car::fuelGauge<<endl;
    cout<<"현재속도 : "<<Car::curSpeed<<endl;
}

inline void Car::Break(){
    if(Car::curSpeed <= 0){
        return;
    }
    else{
        Car::curSpeed -= CAR_CONST::BRK_STEP;
    }
}

#endif