#include<iostream>
#include<graphics.h>
using namespace std;
void b_circle(int x, int y ,int r){

float d;
int x1,y1;
x1=0;
y1=r;
d=3-2*r;

do{
putpixel(x+x1,y+y1,GREEN);
putpixel(x-x1,y-y1,GREEN);
putpixel(x+x1,y-y1,GREEN);
putpixel(x-x1,y+y1,GREEN);
putpixel(x+y1,y+x1,GREEN);
putpixel(x-y1,y-x1,GREEN);
putpixel(x+y1,y-x1,GREEN);
putpixel(x-y1,y+x1,GREEN);
if(d<0){
  d=d+4*x1+6;
}
else{
  d=d+4*(x1-y1)+10;
  y1--;
}
   x1++;
 delay(50);
}
while(x1<y1);
}
int main()
{
int x1,y1,r,gd,gm;
gd=DETECT;
cout<<"Enter the x1 coordinate: ";
cin>>x1;
cout<<"Enter the y1 coordinate: ";
cin>>y1;
cout<<"Enter radius: ";
cin>>r;
initgraph(&gd,&gm,NULL);
b_circle(x1,y1,r);

  getch();
  closegraph();
  return 0;
 }
