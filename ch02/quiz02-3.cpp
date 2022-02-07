#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct __Point{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2){
    Point *p3 = new Point;
    p3 -> xpos = p1.xpos + p2.xpos;
    p3 -> ypos = p1.ypos + p2.ypos;
    return *p3;
}

Point& Subtracter(const Point &p1, const Point &p2){
    Point *p3 = new Point;
    p3 -> xpos = p1.xpos - p2.xpos;
    p3 -> ypos = p1.ypos - p2.ypos;
    return *p3;
}

int main(void){
    Point *p1 = new Point;
    Point *p2 = new Point;
    *p1 = {10, 10};
    *p2 = {20, 20};
    Point *p3 = new Point;
    *p3 = PntAdder(*p1, *p2);
    cout<<p3 -> xpos<<endl;
    cout<<p3 -> ypos<<endl;

    return (0);
}