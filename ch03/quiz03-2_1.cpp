#include <iostream>
using namespace std;

class Calculator{
    private:
        int Add_num;
        int Min_num;
        int Mul_num;
        int Div_num;
    public:
        void Init();
        float Add(float num1, float num2);
        float Min(float num1, float num2);
        float Mul(float num1, float num2);
        float Div(float num1, float num2);
        void ShowOpCount();
};

void Calculator::Init(){
    Add_num = 0;
    Min_num = 0;
    Mul_num = 0;
    Div_num = 0;
}

float Calculator::Add(float num1, float num2){
    Add_num++;
    return num1 + num2;
}

float Calculator::Min(float num1, float num2){
    Min_num++;
    return num1 - num2;
}

float Calculator::Mul(float num1, float num2){
    Mul_num++;
    return num1 * num2;
}

float Calculator::Div(float num1, float num2){
    Div_num++;
    return num1 / num2;
}

void Calculator::ShowOpCount(){
    cout<<"µ¡¼À : "<<Calculator::Add_num;
    cout<<"»¬¼À : "<<Calculator::Min_num;
    cout<<"°ö¼À : "<<Calculator::Mul_num;
    cout<<"³ª´°¼À : "<<Calculator::Div_num<<endl;
}

int main(void){
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();

    return (0);
}