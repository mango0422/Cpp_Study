#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class SoSimple{
    private:
        int num;
    public:
        SoSimple(int n) : num(n){
            cout<<"New Object: "<<this<<endl;
        }
        SoSimple(const SoSimple& copy):num(copy.num){
            cout<<"New Copy Object: "<<this<<endl;
        }
        ~SoSimple(){
            cout<<"Destroy obj "<<this<<endl;
        }
};

SoSimple SimpleFuncObj(SoSimple ob){        // Ŭ���� ��ü ��ȯ�ϴ� �Լ�.
    cout<<"Parm ADR: "<<&ob<<endl;
    return ob;
}

int main(void){
    SoSimple obj(7); // obj ����
    SimpleFuncObj(obj); // �Ű����� ob ����, SimpleFuncObj ����, �ӽð�ü ����(����� �ν�), ���� �Ű�����ob, �ӽð�ü ������ �Ҹ�

    cout<<endl;
    SoSimple tmepRef = SimpleFuncObj(obj);
    cout<<"Return Obj"<<&tmepRef<<endl;
    return (0);
}