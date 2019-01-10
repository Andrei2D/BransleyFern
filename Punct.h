#ifndef PUNCT_H

#define PUNCT_H

#include <iostream>
#include <fstream>
#include <vector>

#define RIGHT_POINT_POZ -1
#define LEFT_POINT_POZ 1
#define STRAIGHT_POINT_POZ 0

using namespace std;


class Punct
{
    float x,y;
    float scale;
public:
    Punct (float xx=0,float yy=0,float scl=40)
    {x=xx;y=yy;
    scale = scl;
    }
    float getx () { return x; }
    float gety () { return y; }

    int getGhX () { return 300 + x*scale; }
    int getGhY () { return 400 - y*scale; }

    void set(float xx, float yy) {x=xx;y=yy;}

    Punct operator+ (Punct P)
    {
        Punct rez(x+P.x, y+P.y);
        return rez;
    }

    Punct operator* (float scalar)
    {
        Punct rez(x * scalar, y * scalar);
        return rez;
    }

    Punct operator- (Punct P)
    {
        Punct rez(x,y);
        rez = rez + P*(-1);
        return rez;
    }

    void setScale (float newScale)
    { scale = newScale; }

    int operator=(const Punct P)
    {
        x=P.x;
        y=P.y;
        return 1;
    }

    bool operator< (Punct P)
    {
        if(x<P.x) return 1;
        if(x==P.x && y<P.y) return 1;
        return 0;
    }

    bool operator== (Punct P)
    {
        if(x == P.x && y == P.y) return 1;
        return 0;
    }

    bool operator!= (Punct P)
    {
        return !(operator==(P));
    }


    static float Determinant(Punct P, Punct Q, Punct R)
    {
        float positive = Q.x * R.y + R.x * P.y + P.x * Q.y;
        float negative = Q.x * P.y + P.x * R.y + R.x * Q.y;
        return positive - negative;
    }

    static int Position (Punct BASE, Punct TIP, Punct POINT)
    {
        float det = Determinant(BASE, TIP, POINT);
        if (det < 0) return RIGHT_POINT_POZ;
        if (det > 0) return LEFT_POINT_POZ;
        return STRAIGHT_POINT_POZ;
    }

friend char formaGeom (int* vir, vector<Punct>& P);
friend ifstream& operator>> (ifstream& f, Punct& p);
friend ostream& operator<< (ostream& out, Punct& p);
};

ifstream& operator>> (ifstream& f, Punct& p)
{
    f>>p.x>>p.y;
    return f;
}

ostream& operator<< (ostream& out, Punct& p)
{
    out<<"("<<p.x<<" "<<p.y<<")";
    return out;
}




#endif // PUNCT_H
