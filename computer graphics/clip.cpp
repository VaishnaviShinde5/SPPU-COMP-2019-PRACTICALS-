#include <iostream>
#include <graphics.h>
using namespace std;

int Left=1,Right=2,Bottom=4,Top=8,xl,yl,xh,yh;
int getcode(int x,int y)
{
	int code = 0;
	if(y<yh) code |=Top;
	if(y>yl) code |=Bottom;
	if(x<xl) code |= Left;
	if(x>xh) code |=Right;
	return code;
}

int main()
{
	int gd = DETECT,gm;
	setcolor(WHITE);
	cout<<"Enter the bottom left and top of right co-ordinates of window=";
	initgraph(&gd,&gm,NULL);
	cin>>xl>>yl>>xh>>yh;
	rectangle(xl,yl,xh,yh);
	int x1,y1,x2,y2;
	cout<<"Enter the endpoints of the line= ";
	cin>>x1>>y1>>x2>>y2;
	line(x1,y1,x2,y2);
	//getch();
	int outcode1=getcode(x1,y1),outcode2=getcode(x2,y2);
	int accept = 0;
	while(1)
	{
		float m =(float)(y2-y1)/(x2-x1);
		if(outcode1==0&&outcode2==0)
		{
		accept = 1;
		break;
		}
		else if((outcode1 & outcode2)!=0)
		{
		break;
		}
		else
		{
			int x,y;
			int temp;
			if(outcode1==0)
			{
				temp = outcode2;
			}
			else
			{
			temp = outcode1;
			}
			if(temp & Top)
			{
				x = x1+(yh-y1)/m;
				y = yh;
			}
			else if(temp & Bottom)
			{
				x = x1+(yl-y1)/m;
				y = yl;
			}
			else if(temp & Left)
			{
				x = xl;
				y = y1+ m*(xl-x1);
			}
			else if(temp & Right)
			{
				x = xh;
				y = y1+ m*(xh-x1);

			}
			if(temp == outcode1)
			{
				x1 = x;
				y1 = y;
				outcode1 = getcode(x1,y1);
			}
			else
			{
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2,y2);
			}
		}
	}
	setcolor(BLUE);
	cout<<"After clipping";
	if(accept)
	line(x1,y1,x2,y2);
	getch();
	closegraph();
}
