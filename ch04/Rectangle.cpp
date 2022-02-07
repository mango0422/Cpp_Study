#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr){
    if(ul.Getx() > lr.Getx()){
        cout<<"�߸��� ��ġ���� ����"<<endl;
        return false;
    }
    upLeft = ul;
    lowRight = lr;
    return false;
}

void Rectangle::ShowRecInfo() const{
    cout<<"�� ��� : "<<'['<<upLeft.Getx()<<','<<upLeft.Gety()<<']'<<endl;
    cout<<"�� �ϴ� : "<<'['<<lowRight.Getx()<<','<<lowRight.Gety()<<']'<<endl<<endl;
}