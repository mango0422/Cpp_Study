/*
 * 헤더파일  main 함수를 제외한 나머지 두 함수의 선언을 삽입한다.
 * 소스파일1 main 함수를 제외한 나머지 두 함수의 정의를 삽입한다.
 * 소스파일2 main 함수만 삽입한다.
*/

#include <iostream>
#include "Quiz_04_1_header.h"

int main(void){
    BestComImpl::SimpleFunc();  
    ProgComImpl::SimpleFunc();
    return (0);
}