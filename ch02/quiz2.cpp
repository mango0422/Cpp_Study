#include <iostream>

void RefSwap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(void){
    int num1 = 30;
    int num2 = 10;

    RefSwap(num1, num2);
    // RefSwap(23, 45); // �ȵǴ� ���� - RefSwap�Լ��� �ּҸ� �̿��Ͽ� �����ϴ� �Լ��ε�, �ܼ� �����̹Ƿ� ������ �ּҰ� ����.
}