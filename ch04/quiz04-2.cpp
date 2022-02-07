#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    public:
        void Init(int x, int y){
            xpos = x;
            ypos = y;
        }
        void ShowPointInfo() const{
            cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
        }
};

class Ring{
    private:
        Point Rpoint1;
        Point Rpoint2;
        int radius1;
        int radius2;
    public:
        void Init(int x1, int y1, int r1, int x2, int y2, int r2){
            Rpoint1.Init(x1, y1);
            Rpoint2.Init(x2, y2);
            radius1 = r1;
            radius2 = r2;
        }

        void ShowRingInfo() const{
            cout<<"Inner Circle Info..."<<endl;
            cout<<"radius : "<<radius1<<endl;
            Rpoint1.ShowPointInfo();
            cout<<"Outter Circle Info..."<<endl;
            cout<<"radius : "<<radius2<<endl;
            Rpoint2.ShowPointInfo();
        }
};

int main(void){
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();

    return (0);
}