/*
 * �Լ��� �����ε� �Ǹ�, �����ε� �� ����ŭ �پ��� ����� �����ϰ� �ȴ�.
 * �̸��� �ϳ������� ����� ���� ������ �Ǵ� ���̴�.
 * ���������� �������� �����ε��� ���ؼ�, ������ �����ϴ� �������� �⺻ ��� �̿ܿ� �ٸ� ����� �߰��� �� �ִ�.
 */
#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){}
        void ShowPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
        Point operator+(const Point &ref){   // operator+��� �̸��� �Լ�
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
};

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3=pos1.operator+(pos2); // pos1+pos2�� pos1.operator+(pos2)�� �ٸ� ǥ���ϰž�
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return (0);
}

/*
 * c++�� ��ü�� �⺻ �ڷ��� ����ó�� ����,����, Ȥ�� ������ ���� ������� �����ϰ� �Ϸ� ��.
 * 'operator' Ű����� '������' �� ��� �Լ��� �̸��� �����ϸ�, �Լ��� �̸��� �̿��� �Լ��� ȣ��Ӹ� �ƴ϶�, �����ڸ� �̿��� �Լ��� ȣ�⵵ ���.
 * pos1 + pos2��� ������ ������, pos1�� ��ü�ΰ��, pos1.operator+(pos2)��� �������� �ؼ�.
 * ��, ��ü�� �ǿ����ڷ� ����� �������� �̸� �տ�  operator��� �̸��� �ٿ��� �ϼ��Ǵ� �̸��� �Լ��� ȣ����.
 * ����, operator-��� �Լ��� �ִ°��, pos1-pos2 ��� ������ pos1.operator-(pos2)��� �������� �ؼ��� �ȴ�.
 * 
 * �������� �����ε� ������� ����Լ��� ���� ����� �����Լ��� ���� ����� �ִ�.
 */