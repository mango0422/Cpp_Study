#include <iostream>
using namespace std;

struct Point{
    int xpos;
    int ypos;

    void MovePos(int x, int y){
        xpos += x;
        ypos += y;
        return;
    }

    void AddPoint(const Point &pos){
        xpos += pos.xpos;
        ypos += pos.ypos;
        return;
    }

    void ShowPosition(){
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
        return;
    }
};

int main(void){
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7,10);
    pos1.ShowPosition();

    pos2.AddPoint(pos1);
    pos2.ShowPosition();
    return(0);
}