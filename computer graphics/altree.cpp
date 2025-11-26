#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);
putpixel(50,40,RED);
line(150,100,240,100);
line(150,100,200,50);
line(200,50,240,100);

line(130,160,260,160);
line(130,160,200,100);
line(200,100,260,160);

line(110,220,280,220);
line(110,220,200,160);
line(200,160,280,220);

line(185,220,185,280);
line(205,220,205,280);
line(185,280,205,280);
getch();
closegraph();
}

