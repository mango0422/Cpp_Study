#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void){
    char str1[50] = {};
    char str2[50] = {};
    
    cout<<"str1's length : "<<strlen(str1)<<endl;
    cout<<"str2's length : "<<strlen(str2)<<endl;

    strcat(str1, "Block");
    cout<<"strcmp: "<<strcmp(str1, str2)<<endl;

    cout<<endl<<"str1 : "<<str1<<endl;
    cout<<endl<<"str2 : "<<str2<<endl;
    
    strcpy(str2, str1);
    cout<<"strcmp: "<<strcmp(str1, str2)<<endl;

    strcat(str1, "DMask");
    cout<<endl<<"str1 : "<<str1<<endl;
    cout<<"strcmp: "<<strcmp(str1, str2)<<endl;
    
    strcat(str2, "Fmask");
    cout<<endl<<"str2 : "<<str2<<endl;
    cout<<"strcmp: "<<strcmp(str1, str2)<<endl;

    cout<<"str1 : "<<str1<<endl;
    cout<<"str2 : "<<str2<<endl;
    
    return(0);
}