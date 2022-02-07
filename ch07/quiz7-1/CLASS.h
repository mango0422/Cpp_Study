#ifndef _CLASS_H_
#define _CLASS_H_

#include <iostream>
#include <cstring>
using namespace std;

class Car{
    private:
        int gasolineGauge;
    public:
        Car(){}
        Car(int n):gasolineGauge(n){}
        int GetGasGauge(){
            return gasolineGauge;
        }
};

class HybridCar : public Car{
    private:
        int electricGauge;
    public:
        HybridCar(){}
        HybridCar(int n):electricGauge(n){}
        HybridCar(int n1, int n2):electricGauge(n1), Car(n2){}
        int GetElecGauge(){
            return electricGauge;
        }
};

class HybridWaterCar : public HybridCar{
    private:
        int waterGauge;
    public:
        HybridWaterCar(){}
        HybridWaterCar(int n):waterGauge(n){}
        HybridWaterCar(int n1, int n2):waterGauge(n1), HybridCar(n2){}
        HybridWaterCar(int n1, int n2, int n3):waterGauge(n1), HybridCar(n2, n3){}
        void ShowCurrentGauge(){
            cout<<"ÀÜ¿© °¡¼Ö¸°: "<<GetGasGauge()<<endl;
            cout<<"ÀÜ¿© Àü±â·®: "<<GetElecGauge()<<endl;
            cout<<"ÀÜ¿© ¿öÅÍ·®: "<<waterGauge<<endl<<endl;
        }
};

#endif