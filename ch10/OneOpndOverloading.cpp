/* 
 * ����, ���� �������� �����ε�
 * ��ǥ���� ���� ������ 2���� :
 * 1 ���� ������ ++
 * 1 ���� ������ --
 * 
 * ++pos;       // pos�� Point ��ü! Point Ŭ������ ++ �����ڰ� �����ε� �Ǿ��ִٰ� ����.
 * "ȣ��Ǵ� �Լ��� �̸��� ++�����ڿ� Ű���� operator�� �����ؼ� �ϼ��ǹǷ�, operator++�Դϴ�."
 * 
 * pos.operator++(); // ����Լ��� ���¶��, pos�� ����Լ��� ȣ��Ǵ� �����̴�, �̿� ���� �ؼ��Ǿ�� �Ѵ�.
 * 
 * operator++(pos); // �����Լ��� ���� �ǿ����ڰ� ��� ���ڷ� ���޵ǹǷ�, �̿� ���� ���·� �ؼ��� �ȴ�.
 * 
 * ���� ���������� ���� �����ڿ� ���� �����ڸ� �����ε� �Ѵ�.
 * �� �� �ϳ��� ����Լ��� �������, �ٸ� �ϳ��� �����Լ��� ������� �����ڸ� �����ε� �Ͽ���.
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
        Point& operator++(){    // ++ �����ڰ� ����Լ� ���·� �����ε� �Ǿ���.
            xpos+=1;
            ypos+=1;
            return *this;
        }
        friend Point& operator--(Point &ref);   // 37�࿡ ���ǵ� �����Լ��� ���� friend �����ϰ� �ִ�.
};

Point& operator--(Point &ref){  // -- �����ڰ� ����Լ� ���·� �����ε� �Ǿ���.
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

int main(void){
    Point pos(1, 2);
    ++pos;  // pos.operator++();�� �ؼ���.
    pos.ShowPosition();
    --pos;  // operator--(pos); �� �ؼ���.
    pos.ShowPosition();

    ++(++pos);  // ++(pos.operator++()); -> (pos�� ���� ��).operator++();
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();
    return (0);
}