#include <iostream>
#include <string.h>
using namespace std;

char *MakeStrAdr(int len){
    // char *str = (char*)malloc(sizeof(char)*len); // calloc도 사용가능 - 사용 방식이 다름(malloc은 할당된 공간의 값을 바꾸지 않는다.)
    // char *str = (char*)calloc(len, sizeof(char)); // (calloc은 할당된 공간의 값을 모두 0으로 바꾼다.)
    char *str = new char[len];
    return str;
}

int main(void){
    char * str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout<<str<<endl;
    // free(str);
    delete []str;

    return(0);
}