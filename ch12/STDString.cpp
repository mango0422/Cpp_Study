#include <iostream>
#include <string>
using namespace std;

int main(void){
    string str1="I like ";
    string str2="string class";
    string str3=str1+str2;  // 8�� : string ��ü�� �������� ����.

    cout<<str1<<endl;   // 10~12�� : string Ŭ������ << �����ڿ� ���ؼ��� �����ε� �Ǿ� ���� Ȯ�� ����.
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1+=str2; // 14~20�� : 14goddml += ������ ����� ���ڿ� str1�� ���� ���ڿ� str2�� ���ٿ� ������ "���� ���ڿ�!"�̶�� ���ڿ��� ����� ���ؼ� �� �� �ִ�.
    if(str1==str3){
        cout<<"���� ���ڿ�!"<<endl;
    }
    else{
        cout<<"�������� ���� ���ڿ�!"<<endl;
    }
    string str4;
    cout<<"���ڿ� �Է�: ";
    cin>>str4;
    cout<<"�Է��� ���ڿ�: "<<str4<<endl;    // String Ŭ������ >> �����ڿ� ���ؼ��� �����ε��� �Ǿ� �ִ�. ���� �̷��� ���·� string ��ü�� ���ؼ� ���ڿ��� �Է� �޴� ���� �����ϴ�.
    return (0);
}

/*
 * ������ string Ŭ������ �� �������� �����ִ� �� �̻��� ����� ���ϰ� �ִ�. �׷��� �츮�� ������ �̿� ������ ������ Ŭ������ ���� �����ϴ� ���̹Ƿ�, �� ������ �������ϰ��� �Ѵ�.
 */