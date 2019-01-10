#include <iostream>
#include <graphics.h>
#include "Punct.h"
#include "GraphicsFunctions.h"
#include "Auxiliar.h"
using namespace std;

Punct fun1(Punct P)
{
    float x = 0;
    float y = 0.16 * y;

    Punct rez(x,y);
    //cout<<"1) "<<P<<" -> "<<rez<<"\n";
    return rez;
}

Punct fun2(Punct P)
{
    float x = 0.85 * P.getx() + 0.04 * P.gety();
    float y = -0.04 * P.getx() + 0.85 * P.gety() + 1.6;

    Punct rez(x,y);
    //cout<<"2) "<<P<<" -> "<<rez<<"\n";
    return rez;
}

Punct fun3(Punct P)
{
    float x = 0.2 * P.getx() - 0.26 * P.gety();
    float y = 0.23 * P.getx() + 0.22 * P.gety() + 1.6;

    Punct rez(x,y);
    //cout<<"3) "<<P<<" -> "<<rez<<"\n";
    return rez;
}

Punct fun4(Punct P)
{
    float x = -0.15 * P.getx() + 0.28 * P.gety();
    float y = 0.26 * P.getx() + 0.24 * P.gety() + 0.44;

    Punct rez(x,y);
    //cout<<"4) "<<P<<" -> "<<rez<<"\n";

    return rez;
}

Punct randomFun (Punct P)
{
    float val = random(0,102);
    if( val <= 10 )
        return fun1(P);
    else if (val <= 86)
        return fun2(P);
    else if(val <= 93 )
        return fun3(P);
    else return fun4(P);
}

void drawScaledPoint(Punct P, unsigned int aDelay = 0, float lwrScale = -1, float upprScale = 1)
{

    float x = P.getx() * 100; ///map(P.getx(),lwrScale,upprScale,600, 700);
    float y = P.gety() * 100; ///map(P.gety(),lwrScale,upprScale,600, 700);

    Punct altu(x,y);
    drawPoint(P,aDelay);
}

int gm, gd = DETECT;

int main()
{

    initgraph(&gd,&gm,"c:\\turboC3\\bgi");

    Punct P(1,1);

    while (true)
    {
        P = randomFun(P);
        drawScaledPoint(P,1,-2,3);

    }
    getch();
    cleardevice();


    return 0;
}
