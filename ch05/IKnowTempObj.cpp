#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Temporary{
    private:
        int num;
    public:
        Temporary(int n) : num(n){      // Ŭ���� ������
            cout<<"create obj :"<<num<<endl;
        }
        ~Temporary(){       // Ŭ���� �Ҹ���
            cout<<"destroy obj: "<<num<<endl;
        }
        void ShowTempInfo(){
            cout<<"My num is "<<num<<endl;
        }
};

int main(void){
    Temporary(100);             // �̰��� �ӽð�ü ���� �����ϴ� ���. �̹��忡 ���ؼ� 100���� �ʱ�ȭ�� Temporary �ӽð�ü ������.
    cout<<"********* after make!"<<endl<<endl;
    
    Temporary(200).ShowTempInfo();          // �ӽð�ü ����, �̾ ��ü ������� ShowTempInfo �Լ� ȣ��. ��ü ���� �� ��ȯ��,
                                            // ���� �� ��ȯ�� ��ġ�� ��ü�� ������ �� �մ� ���� ���� ��ȯ�Ǳ� ������ �̷��� ���� ���� ����.
    cout<<"********* after make!"<<endl<<endl;

    const Temporary &ref = Temporary(300);      // �տ��� ������ �ٸ� �� ��ü�� �޸� ���⼭�� ������ ref�� �ӽð�ü�� ������.   
    cout<<"********* end of main!"<<endl<<endl;
    return (0);
}

/* 
 * Temporary(200).ShowTempInfo();
 * Ŭ���� �ܺο��� ��ü�� ����Լ��� ȣ���ϱ� ���� �ʿ��� ���� ���� �� ���� �� �ϳ��̴�.
 * �� ��ü�� �ٿ��� �̸�
 * �� ��ü�� ���� ��(��ü ������ ���Ǵ� ����)
 * �� ��ü�� �ּ� ��
 * (�ӽð�ü�� ���� ��).ShowTempInfo();  // �ӽð�ü�� ������ ��ġ���� �ӽð�ü�� ���� ���� ��ȯ��. �� ������ ��� ���� �ӽð�ü�� �����Ǹ鼭 ������ ���°� ��.
 * const Temporary &ref = Temporary(300);       // �� ���� �ӽð�ü ������ ��ȯ�Ǵ� '���� ��'�� ������ ref�� ���޵Ǿ�, ref�� �ӽð�ü�� �����ϰ� ��.
 * SimpleFuncObj(obj).AddNum(30).ShowData(); // �̿� ���� ������ ������ ������, �����δ� �ӽð�ü�� ��°�� ��ȯ�Ǿ�� �ƴ϶�, �ӽð�ü�� �޸𸮿� ����ǰ�, �� ��ü�� ���� ���� ��ȯ�Ǿ��� ����.
 * 
 */