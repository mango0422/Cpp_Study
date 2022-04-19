#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray{
    private:
        int *arr;
        int arrlen;

        explicit BoundCheckIntArray(const BoundCheckIntArray& ref){}
        BoundCheckIntArray& operator=(const BoundCheckIntArray& ref){}
    public:
        explicit BoundCheckIntArray(int len) : arrlen(len){
            arr = new int[len];
        }
        ~BoundCheckIntArray(){
            delete[] arr;
        }
        int& operator[](const int idx){
            if(idx < 0 || idx >= arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int& operator[](const int idx) const{
            if(idx < 0 || idx >= arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2DIntArray{
    private:
        int row, col;
        BoundCheckIntArrayPtr * arr;

        explicit BoundCheck2DIntArray(const BoundCheck2DIntArray& ref){}
        BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& ref){}
    public:
        explicit BoundCheck2DIntArray(const int row, const int col) : row(row), col(col){
            arr = new BoundCheckIntArrayPtr[row];
            for(int i = 0; i<row; i++){
                arr[i] = new BoundCheckIntArray(col);
            }
        }
        ~BoundCheck2DIntArray(){
            delete []arr;
        }
        BoundCheckIntArray& operator[](const int idx){
            if(idx<0 || idx > row){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return *(arr[idx]);
        }
};

int main(void){
    BoundCheck2DIntArray arr2d(3,4);
    for(int n=0; n<3; n++){
        for(int m=0; m<4; m++){
            arr2d[n][m]=n+m;
        }
    }
    for(int n=0; n<3; n++){
        for(int m=0; m<4; m++){
            cout<<arr2d[n][m]<<' ';
        }
        cout<<endl;
    }
}