#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(char * ID, int fuel){
    strcpy(Car::gamerID, ID);
    Car::fuelGauge = fuel;
    Car::curSpeed = 0;
}

void Car::Accel(){
    if(Car::fuelGauge <= CAR_CONST::FUEL_STEP){
        return;
    }
    else{
        Car::fuelGauge -= CAR_CONST::FUEL_STEP;
    }
    if(Car::curSpeed >= CAR_CONST::MAX_SPD){
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

void Car::ShowCarState(){
    cout<<"운전자ID : ["<<Car::gamerID<<"]"<<endl;
    cout<<"연료량: "<<Car::fuelGauge<<"%"<<endl;
    cout<<"현재 속도: "<<Car::curSpeed<<"km/s"<<endl;
}