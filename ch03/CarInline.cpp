#include <cstring>
#include "CarInline.h"
using namespace std;

void Car::InitMembers(char * gamerID, int fuel){
    strcpy(Car::gamerID, gamerID);
    Car::fuelGauge = fuel;
    Car::curSpeed = 0;
}

void Car::Accel(){
    if(Car::fuelGauge <= CAR_CONST::Fuel_STEP){
        return;
    }
    else{
        Car::fuelGauge -= CAR_CONST::Fuel_STEP;
    }
    if(Car::curSpeed >= CAR_CONST::MAX_SPD){
        return;
    }
    else{
        Car::curSpeed += CAR_CONST::ACC_STEP;
    }
}