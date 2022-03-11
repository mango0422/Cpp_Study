#include <iostream>
#include <cstring>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y){}
        void ShowPosition() const{
            cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
        }
        friend Point operator+(const Point &pos1, const Point &pos2);
        friend Point operator-(const Point &pos1, const Point &pos2);
        friend Point operator+=(const Point &pos1, const Point&pos2);
        friend Point operator-=(const Point &pos1, const Point &pos2);
        friend bool operator==(const Point &pos1, const Point &pos2);
        friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2){
    Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}

Point operator-(const Point &pos1, const Point &pos2){
    Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
    return pos;
}

Point* operator+=(Point &pos1, Point &pos2){
    pos1=pos1+pos2;
    return &pos1;
}

Point* operator-=(Point &pos1, Point &pos2){
    pos1=pos1-pos2;
    return &pos1;
}

bool operator==(const Point &pos1, const Point &pos2){
    if(pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos){
        return true;
    }
    else{
        return false;
    }
}

bool operator!=(const Point &pos1, const Point &pos2){
    return !(pos1==pos2);
}

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3=pos1+pos2; // pos = pos1.operator+(pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    pos3=pos1-pos2; // pos = pos1.operator-(pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    pos1 += pos2; // pos1 = pos1.operator+=(pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    pos1 -= pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    Point pos4(4, 4);
    Point pos5(4, 4);
    Point pos6(4, 6);
    Point pos7(5, 4);
    cout<<boolalpha<<(pos4==pos5)<<endl;
    cout<<boolalpha<<(pos4==pos6)<<endl;
    cout<<boolalpha<<(pos4==pos7)<<endl;

    cout<<boolalpha<<(pos4!=pos5)<<endl;
    cout<<boolalpha<<(pos4!=pos6)<<endl;
    cout<<boolalpha<<(pos4!=pos7)<<endl;

    return (0);
}

/*
 * �����ε��� �Ұ����� �������� ����
 * .                ��� ���� ������
 * .*               ��� ������ ������
 * ::               ���� ���� ������
 * ?:               ���� ������(3�� ������)
 * sizeof           ����Ʈ ���� ũ�� ���
 * typeid           RTTI ���� ������
 * static_cast      ����ȯ ������
 * dynamic_cast     ����ȯ ������
 * const_cast       ����ȯ ������
 * reinterpret_cast ����ȯ ������
 */

/*
 * �� �����ڵ��� �����ε��� �����ϴ� ������ c++�� ������Ģ�� �����ϱ� ���ؼ��̴�.
 * ���� ���� �����ڵ���� �����ε��� ����� �����ٸ�, C++�� ���� ��Ģ�� ��߳��� ������ ������ ����������, �̴� C++�� ���� ȥ�������� ���� ���� �� �ֱ� �����̴�.
 * �����, ���� �����ڵ��� �����ε� �ؾ߸� �ϴ� ��Ȳ�� ���� �������� �ʱ� �빮�� �����е� ���ڿ� ���������� �̵� �����ڿ� ���ؼ��� �����ε��� �ϰ��� �������� ���� ���� ���̴�. �׷� �̾ ����Լ� ������θ� �����ε��� ������ �����ڸ� �Ұ��ϰڴ�.
 * 
 * =    ���Կ�����
 * ()   �Լ� ȣ�� ������
 * []   �迪 ���� ������(�ε��� ������)
 * ->   ��� ������ ���� ������ ������
 * 
 * �̵��� ��ü�� ������� �����ؾ� �ǹ̰� ���ϴ� �����ڵ��̱� ������, ����Լ� ������θ� �������� �����ε��� ����Ѵ�.
 */  

/* 
 * �����ڸ� �����ε� �ϴµ� �־�� ���ǻ���
 * 
 * 1.������ �ǵ��� ��� ������ ������ �����ε��� ���� �ʴ�.
 *  - ������ �����ε��� �߸� ����ϸ� ���α׷��� �����ϰ�, �����ϱ� ��ư� ����ٴ� ������ �ִ�.
 *      "pos1 + pos2"     (pos1�� pos2�� Point ��ü��.)
 * pos1�� pos2�� ��� ���� ������ �ؼ� �� ����� ��ü�� ���� ��ȯ�ϴ� �������� ������ ���̴�.
 * �׷��� �̷��� �츮�� ��븦 �������� pos1�� ���� pos2�� ����ŭ ������Ų �ٴ���, �ƴϸ� ��¥ �����ϰ�, ������ ����� pos2�� ��������� ����� ���� ����ȴٸ�, ���α׷��� �ڵ带 ��������� ������ �� ����.
 * 2.�������� �켱������ ���ռ��� �ٲ��� �ʴ´�.
 * �����ڰ� ���� ������ ����� �����ε� �Ǿ, �����ڰ� ���ϴ� �켱������ ���ռ��� �״�� ������ �Ǿ� �ִ�. (�׷��� ������ ��ȥ��)
 * 3.�Ű������� ����Ʈ �� ������ �Ұ����ϴ�.
 * �ǿ������� �ڷ����� ���� �����ڸ� �����ε� �� �Լ��� ȣ���� �����ǹǷ� �Ű������� ����Ʈ �� ���� �ȵ�.
 * 4.�������� ���� ��ɱ��� ������ ���� ����.
 *      int operator+(const int num1, const int num2){
 *          return num*num2;
 *      }
 * int�� �������� +������ �̹� �� �ǹ̰� ������ �ִ�.
 * �������� �⺻ ����� �����ϴ� ������ ������ �����ε��� ������ �ʴ´�.
 */