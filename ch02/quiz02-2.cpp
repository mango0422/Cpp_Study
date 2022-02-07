// #include <iostream>
// using namespace std;

// int Adder(const int &num1, const int &num2){
//     return num1 + num2;
// }

// int main(void){
//     const int &ref = 30;
//     cout<<&ref<<endl;
//     cout<<Adder(3, 4)<<endl;
//     return (0);
// }

#include <iostream>
using namespace std;

int main(void){
    const int num = 12;
    const int *ptr = &num;
    const int **dptr = &ptr;
    cout<<*ptr<<endl;
    cout<<**dptr<<endl;

    return(0);
}