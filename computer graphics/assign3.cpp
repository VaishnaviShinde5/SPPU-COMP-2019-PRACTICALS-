#include<iostream>
#include<graphics.h>
using namespace std;


class dda_line
{
	float x, y, dx, dy, i, length;
	public:
	void draw_line(int x1, int y1, int x2, int y2);
	void draw_circle(int x, int y, int r);
};
void dda_line :: draw_circle(int x, int y, int r)
{
	int x1,y1;
	x1=0;
	y1=r;
	int d=3-2*r;
	do{
		putpixel(x+x1,y+y1,WHITE);
		putpixel(x-x1,y-y1,WHITE);
		putpixel(x+x1,y-y1,WHITE);
		putpixel(x-x1,y+y1,WHITE);
		putpixel(x+y1,y+x1,WHITE);
		putpixel(x-y1,y-x1,WHITE);
		putpixel(x+y1,y-x1,WHITE);
		putpixel(x-y1,y+x1,WHITE);
		if(d<0)
			d=d+4*x1+6;
		else
		{
			d=d+4*(x1-y1)+10;
			y1--;
		}
		x1++;
		delay(20);
	}while(x1<y1);
}						
void dda_line :: draw_line(int x1, int y1, int x2, int y2)
{
	dx = x2-x1;
	dy = y2-y1;
	if(abs(dx)>=abs(dy))
	{
		length = abs(dx);
	}
	else
	{
		length = abs(dy);
	}
	
	dx = (x2-x1)/length;
	dy = (y2-y1)/length;
	x = x1+0.5*dx;
	y = y1+0.5*dy;
	i = 0;
	
	while(i < length)
	{
		x=x+dx;
		y=y+dy;
		putpixel(x,y,WHITE);
		i=i+1;
		delay(20);
	}
}
int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	dda_line draw;
	draw.draw_circle(100,100,80);
	draw.draw_circle(100,100,40);
    draw.draw_line(170,140,30,140);
	draw.draw_line(30,140,100,20);
	draw.draw_line(170,140,100,20);
	getch();
	closegraph();
	return 0;
}
