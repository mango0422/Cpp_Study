// �Լ� ȣ������� ��ȣ���� �ٸ� ��Ȳ������ �߻��� �� �ִ�.
// �� ��Ȳ�� ���� ������ ���� �Ұ��ϰ����� (���Ҿ� �ذ�����), ������ ��ȣ���� �������� �����غ���.

#include <iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Base Constructor"<<endl;
        }
        void SimpleFunc(){
            cout<<"BaseOne"<<endl;
        }
};

class MiddleDerivedOne : virtual public Base{
    public:
        MiddleDerivedOne() : Base(){
            cout<<"MiddleDerivedOne Constructor"<<endl;
        }
        void MiddleFuncOne(){
            SimpleFunc();
            cout<<"MiddleDerivedOne"<<endl;
        }
};

class MiddleDerivedTwo : virtual public Base{
    public:
        MiddleDerivedTwo() : Base(){
            cout<<"MiddleDerivedTwo Constructor"<<endl;
        }
        void MiddleFuncTwo(){
            SimpleFunc();
            cout<<"MiddleDerivedTwo"<<endl;
        }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo{ // Base Ŭ������ ���������� �ι� �����.
    public:
        LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo(){
            cout<<"LastDerived Constructor"<<endl;
        }
        void ComplexFunc(){
            MiddleFuncOne();
            MiddleFuncTwo();
            SimpleFunc();
        }
};

int main(void){
    cout<<"��ü���� �� ..... "<<endl;
    LastDerived ldr;
    cout<<"��ü���� �� ..... "<<endl;
    ldr.ComplexFunc();
    return (0);
}

/*
 * MiddleDerivedOne Ŭ������ MiddleDerivedTwo Ŭ������ virtual ������ ���� ���� ä�� Base Ŭ������ ����ϰ� ��ü�� �����ȴٸ�,
 * ��� Ŭ������ ���� ���� ����� Base Ŭ������ ����Լ��� ȣ���� �������� ����ؾ� �Ѵ�.
 * 
 * MiddleDerivedOne::SimpleFunc(); // MiddleDerivedOne Ŭ������ ����� Base Ŭ������ SimpleFunc �Լ�ȣ���� ���!
 * MiddleDerivedTwo::SimpleFunc(); // MiddleDerivedTwo Ŭ������ ����� Base Ŭ������ SimpleFunc �Լ�ȣ���� ���!
 * 
 * �׷��� �̷��� ��Ȳ����, Base Ŭ������ ����� LastDerived ��ü�� �ϳ����� �����ϴ� ���� Ÿ���� ��찡 ��κ��̴�.
 * ��, Base Ŭ������ �� �ѹ��� ����ϰԲ� �ϴ� ���� �� �������� �ذ�å�� �� �� �ִ�.
 * �׸��� �̸� ���� ������ �ٷ� '���� ���'�̴�.
 * �������� ����� �ϴ� ����� �� �������� ���̰�
 */