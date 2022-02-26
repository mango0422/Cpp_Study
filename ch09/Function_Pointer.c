// 함수 포인터란?
// C언어의 문법 중, 변수가 아닌 함수를 가리키는 포인터.
// int 자료형을 가리키는 int*, char 자료형을 가리키는 char* 포인터와 같이, 함수를 가리키는 포인터도 존재할 수 있다.

// 함수 포인터를 왜 쓰나?
// 함수 포인터는 콜백(callback) 매커니즘을 구현할 때 함수를 또 다른 함수의 인자(argument)로 넘겨주기 위해 주로 사용.
// 또한, 여러 개의 함수를 배열로 관리하고자 할 때 사용할 수도 있음.

// 함수 포인터의 특징
// 함수 포인터도 포인터이기 때문에, 일반적인 포인터와 마찬가지로 메모리 주소를 가리킴.
// 하지만 일반적인 포인터와 달리, 함수 포인터는 데이터가 아닌 코드의 위치를 가리킴.
// 마치 배열을 가리키는 포인터가 배열의 시작부분을 가리키는 것과 같이, 함수 포인터도 코드를 가리킬 때 코드의 시작부분을 가리킴.
// 또한 함수 포인터를 통해 메모리 할당 및 회수 불가능.
// 따라서 함수 포인터를 대상으로 malloc(), free() 함수 사용 불가.

#include <stdio.h>

void fun(int num){
    printf("%d\n", num);
}

int main(){
    void (*fun_ptr)(int);
    fun_ptr = &fun;

    (*fun_ptr)(3);

    printf("%p\n", fun_ptr); // (메모리 주소 출력)

        // void function_1(int _arg){
    //     // 작업 수행
    // }

    // int argument = 10;

    // function_1(argument);

    int x = 1;
    int y = 200;
    int z = 20220221;
    // double w = 1.0;

    // printf("Size of x: %lu bytes \n", sizeof(x)); // Size of x: 4 bytes
    // printf("Size of y: %lu bytes \n", sizeof(y)); // Size of y: 4 bytes
    // printf("Size of z: %lu bytes \n", sizeof(z)); // Size of z: 4 bytes
    // printf("Size of w: %lu bytes \n", sizeof(w)); // Size of w: 4 bytes

    // int *p1 = &x;
    // printf("p1 Points %d now. \n", *p1); // p1 Points 1 now;
    // x++;
    // printf("p1 Points %d now. \n", *p1); // p1 Points 2 now;

    // // 포인터에 정수값을 더하면 자료형의 크기 곱하기 그 값만큼 오른쪽으로 이동하게 됨.

    // p1++;
    // printf("p1 Points %d now. \n", *p1); // 변수들은 프로그래머들이 지정한 대로 예측가능한 곳에 나란히 배열되지 않음.
    // p1--;
    // printf("p1 Points %d now. \n", *p1);

    // 포인터 값들이 나란히 연속으로 배열되는 경우는 언제일까? 배열을 사용할 경우
    int numbers[] = {1, 5, 4, 3, 9, 7, 8, 2};
    int *p2 = &numbers[0];
    
    printf("p2 Points %d now. \n", *p2);
    p2++;
    printf("p2 Points %d now. \n", *p2);
    p2++;
    printf("p2 Points %d now. \n", *p2);
    p2 += 5;
    printf("p2 Points %d now. \n", *p2);
    return 0;

    // 특정 변수나 객체의 값을 그대로 함수에 복사해주는게 아니라 그 위치만 넘겨주는걸 (정확히는 코드와 다름) reference, 참조에 의한 호출이라고 함.
    // managed 언어에서는 자동으로 진행됨.
    // 포인터의 또 다른 수많은 효융 중 하나를 알 수 있는 예제로 Linkes List가 있음.
    // C의 배열은 지정된 자료형에 따라 여러 값을 담을 수 있지만 그 전체 크기가 정해져 있다는 한계가 있음.
    // C로 짠 Linked list의 요소는, 자신의 값 그리고 다음 요소를 가리키는 next란 포인터를 가진 struct
    // Doubly linked list, Circulat Linked list도 있음.
}