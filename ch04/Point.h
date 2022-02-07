#ifndef __POINT_H_
#define __POINT_H_

class Point{
    private:
        int x;
        int y;
    public:
        bool InitMembers(int xpos, int ypos);
        int Getx() const;
        int Gety() const;
        bool SetX(int xpos);
        bool SetY(int ypos);
};

#endif