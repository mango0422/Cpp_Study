#include "CLASS.h"

int main(void){
    SalesWorker seller("Hong", 1000, 0.1);
    cout<<seller.GetPay()<<endl;
    seller.ShowSalaryInfo();
}