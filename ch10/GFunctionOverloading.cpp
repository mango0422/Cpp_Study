/* 
 * �����ڸ� �����ε� �ϴ� ������� ���� �� ������ �ִ�.
 * 
 * ����Լ��� ���� ������ �����ε�
 * �����Լ��� ���� ������ �����ε�
 * 
 * �ռ� ���� ���������� + �����ڸ� ����Լ��� �̿��ؼ� �����ε� �Ͽ���. ������ pos1+pos2�� ������ ���� �ؼ��� �Ǿ���.
 * 
 * pos1.operator+(pos2);
 * 
 * �׷��� + �����ڴ� �����Լ��� �̿��ؼ��� �����ε��� �����ϴ�.
 * �׸��� �̷��� �����Լ��� �̿��ؼ� �����ε��� �ϸ� pos1+pos2�� ������ ���� �ؼ��� �ȴ�.
 * 
 * operator+(pos1, pos2)
 * 
 * ��, ��� �����ε��� �ߴ��Ŀ� ���� �ؼ��ϴ� ����� ������ ���� �� ������ ������ �ȴ�.
 * pos1+pos2; -> pos1.operator+(pos2); // ����Լ��� �����ε� �� ���
 *            -> operator+(pos1, pos2); // �����Լ��� �����ε� �� ���
 * 
 * ������ �ڷ����� ������� + �����ڸ� �����Լ� �������, �׸��� ����Լ� ������� ���ÿ� �����ε� �� ���, ����Լ� ������� �����ε� �� �Լ��� �����Լ� ������� �����ε� �� �Լ����� �켱�� �Ǿ� ȣ��ȴ�.
 * ��, �Ϻ� ������ �����Ϸ��� �̷��� ��Ȳ���� ������ ������ �߻���Ű�⵵ �ϴ�, �̷��� ��Ȳ�� ������ ������ �ʴ� ��  ����.
 * ��! �׷� ������ ���ؼ� + �����ڸ� �����Լ� ������� �����ε� �غ��ڴ�.
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
        friend Point operator+(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2){
    Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3=pos1+pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    return (0);
}