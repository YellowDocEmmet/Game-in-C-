#include "TXLib.h"
#include "IOCarta.h"
#include "IOPers.h"
//------------------------------------

int main()
{
    int var=0;
    txCreateWindow(750,600);
    txSetFillColor(TX_BLACK);
    Hero King;
    Map One;
    One.First();
    King.Draw();
    One.Draw();
    txBegin();
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txClear();
        if(GetAsyncKeyState(VK_DOWN)&&!GetAsyncKeyState(VK_LEFT)&&!GetAsyncKeyState(VK_RIGHT))
        {
            if(One.Get_cell(King.x, King.y+King.v, King.v)<3)
                King.Down();
            if(One.Get_cell(King.x, King.y+King.v, King.v)==6)
            {
                King.x=405;
                King.y=400;
                var=1;
            }
        }
        if(GetAsyncKeyState(VK_UP)&&!GetAsyncKeyState(VK_LEFT)&&!GetAsyncKeyState(VK_RIGHT))
        {
            if(One.Get_cell(King.x, King.y-King.v, King.v)<3)
                King.Up();
            if(One.Get_cell(King.x, King.y-King.v, King.v)==6)
            {
                var=1;
                King.x=55;
                King.y=400;
            }
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            if(One.Get_cell(King.x+King.v, King.y, King.v)<3)
                King.Right();
            if(One.Get_cell(King.x+King.v, King.y, King.v)==6)
            {
                King.x=55;
                King.y=400;
                var=2;
            }
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            if(One.Get_cell(King.x-King.v, King.y, King.v)<3)
                King.Left();
            if(One.Get_cell(King.x-King.v, King.y, King.v)==6)
            {
                King.x=205;
                King.y=50;
                var=0;
            }
        }
        if(One.Get_cell(King.x, King.y, King.v)==2)
            King.hel--;
        if(One.Get_cell(King.x, King.y-King.v, King.v)==5)
            Speak();
        if(One.Get_cell(King.x, King.y-King.v, King.v)==7)
            Speak2();
        if(One.Get_cell(King.x, King.y-King.v, King.v)==8)
        {
            Speak3();
            txSleep(500);
            var=10;
        }
        if(var==0)
            One.First();
        if(var==1)
            One.Second();
         if(var==2)
            One.Third();
        One.Draw();
        King.Draw();
        Text();
        King.WATS();
        txSleep(125);
    }
        txEnd();
}
