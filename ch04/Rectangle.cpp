#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr){
    if(ul.Getx() > lr.Getx()){
        cout<<"잘못된 위치정보 전달"<<endl;
        return false;
    }
    upLeft = ul;
    lowRight = lr;
    return false;
}

void Rectangle::ShowRecInfo() const{
    cout<<"좌 상단 : "<<'['<<upLeft.Getx()<<','<<upLeft.Gety()<<']'<<endl;
    cout<<"우 하단 : "<<'['<<lowRight.Getx()<<','<<lowRight.Gety()<<']'<<endl<<endl;
}