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
    // RefSwap(23, 45); // 안되는 이유 - RefSwap함수는 주소를 이용하여 참조하는 함수인데, 단순 정수이므로 참조할 주소가 없음.
}