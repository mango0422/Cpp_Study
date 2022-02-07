#include <iostream>
using namespace std;

int main(void){
    int num = 12;
    // cout<<"num: "<<num<<endl;
    int *ptr = &num;
    // cout<<"ptr: "<<ptr<<endl;
    // cout<<"*ptr: "<<*ptr<<endl;
    // cout<<"&num: "<<&num<<endl;

    int **dptr = &ptr;
    // cout<<"dptr: "<<dptr<<endl;
    // cout<<"*dptr: "<<*dptr<<endl;
    // cout<<"**dptr: "<<**dptr<<endl;
    // cout<<"&ptr: "<<&ptr<<endl;

    int &ref = num;
    // cout<<"ref: "<<ref<<endl;
    // ref = 30;
    // cout<<"ref: "<<ref<<endl;
    // cout<<"num: "<<num<<endl;
    // num = 500;
    // cout<<"ref: "<<ref<<endl;
    // cout<<"num: "<<num<<endl;
    // cout<<"&ref: "<<&ref<<endl;
    int *(&pref) = ptr;
    // cout<<"pref: "<<pref<<endl;
    // cout<<"&pref: "<<&pref<<endl;
    // cout<<"*(&pref): "<<*(&pref)<<endl;
    int **(&dpref) = dptr;
    // cout<<"dpref: "<<dpref<<endl;
    // cout<<"&dpref: "<<&dpref<<endl;
    // cout<<"*(&dpref): "<<*(&dpref)<<endl;
    // cout<<"**(&dpref): "<<**(&dpref)<<endl;

    cout<<ref<<endl;
    cout<<*pref<<endl;
    cout<<**dpref<<endl;

    return (0);
}

// 12	    num	    *ptr	**dptr	ref			
// 0x61fe04	&num	ptr 	*dptr	&ref	pref	*(&pref)	**(&dpref)
// 0x61fdf8		    &ptr	dptr		    &pref	            dpref == *(&dpref)
// 0x61fdf0							                            &dpref