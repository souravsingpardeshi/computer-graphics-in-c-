#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>

typedef unsigned char BYTE;

BYTE pointcheck(int x, int y);
BYTE bit1check(int p);
BYTE bit2check(int p);
BYTE bit3check(int p);
BYTE bit4check(int p);
int endprog(void);

void main()
{
	    int gd=VGA,gm=VGAHI;
	    float x,y,xmin,ymin,xmax,ymax,xn1,xn2,yn1,yn2,x1,y1,x2,y2, m;
	    int bit1,bit2,bit3,bit4, p1,p2, pointcount = 0;
	    initgraph(&gd, &gm, "c:\\tc\\bgi");
	    xmax = 540; ymax = 380; xmin = 100; ymin = 100;
	    printf("Enter start point :");
	    scanf("%f %f",&x1, &y1);
	    printf("Enter end point :");
	    scanf("%f %f",&x2, &y2);
	    setcolor(1);
	    rectangle(xmin,ymin,xmax,ymax);
	    setcolor(2);
	    line(x1,y1,x2,y2);
	    m = (y2-y1)/(x2-x1);
	    p1 = pointcheck(x1,y1);
	    p2 = pointcheck(x2,y2);
	    bit1=bit1check(p1);
	    bit2=bit2check(p1);
	    bit3=bit3check(p1);
	    bit4=bit4check(p1);
	    printf("Point p1 is %d = %d%d%d%d",p1,bit4,bit3,bit2,bit1);
	    bit1=bit1check(p2);
	    bit2=bit2check(p2);
	    bit3=bit3check(p2);
	    bit4=bit4check(p2);
	    printf("\nPoint p2 is %d = %d%d%d%d",p2,bit4,bit3,bit2,bit1);
	    if (bit1check(p1)&bit1check(p2)==1) endprog();
	    if (bit2check(p1)&bit2check(p2)==1) endprog();
	    if (bit3check(p1)&bit3check(p2)==1) endprog();
	    if (bit4check(p1)&bit4check(p2)==1) endprog();
	    if(p1 == 0 & p2 == 0)
	    {
			printf("\nLine lies within the window");
			getch();
			return 0;
	    }
	    else
			printf("\nClipping......");
	    if (pointcheck(x1,y1)==0)
	    {
			xn1 = x1; yn1 = y1;
			pointcount = pointcount + 1;
			p1 = p2;
	    }
	    if (bit1check(p1) == 1)
	    {
			x = xmin;
			y = y1 + m * (xmin - x1);
			putpixel(x,y,3);
			setcolor(3);
			circle(x,y,4);
			if (pointcount > 0){
				    xn2 = x; yn2 = y;
			}
			else
			{
				    xn1 = x; yn1 = y;
				    pointcount = pointcount +1;
			}
			p1 = p2;
	    }
	    if (bit2check(p1) == 1)
	    {
			x = xmax;
			y = y1 + m * (xmax - x1);
			putpixel(x,y,3);
			setcolor(3);
			circle(x,y,4);
			if (pointcount > 0){
				    xn2 = x; yn2 = y;
			}
			else
			{
				    xn1 = x; yn1 = y;
				    pointcount = pointcount + 1;
			}
			p1 = p2;
	    }
	    if (bit3check(p1) == 1) //it crosses ymin
	    {
			y = ymin;
			x = x1 + (ymin - y1)/m;
			putpixel(x,y,3);
			setcolor(3);
			circle(x,y,4);
			if (pointcount > 0){
				    xn2 = x; yn2 = y;
			}
			else
			{
				    xn1 = x; yn1 = y;
				    pointcount = pointcount + 1;
			}
			p1 = p2;
	    }
	    if (bit4check(p1) == 1) //it crosses ymax
	    {
			y = ymax;
			x = x1 + (ymax - y1)/m;
			putpixel(x,y,3);
			setcolor(3);
			circle(x,y,4);
			if (pointcount > 0) {
				    xn2 = x; yn2 = y;
			}
			else
			{
				    xn1 = x; yn1 = y;
				    pointcount = pointcount + 1;
			}
	    }
	    getch();
	    setcolor(0);
	    line (x1,y1,x2,y2);
	    setcolor(4);
	    line (xn1,yn1,xn2,yn2);
	    getch();
	    closegraph();
}
int endprog(void)
{
	    printf("\nLine lies outside the window");
	    getch();
	    closegraph();
	    return 0;
}
BYTE pointcheck(int x, int y)
{
	    int val=0x00;
	    if ((x - 100) < 0) val = val|0x01;            //make bit 1 --> 1
	    if ((540 - x) < 0) val = val|0x02;            //make bit 2 --> 1
	    if ((y - 100) < 0) val = val|0x04;            //make bit 3 --> 1
	    if ((380 - y) < 0) val = val|0x08;      //make bit 4 --> 1
	    return val;
}
BYTE bit1check(int a)
{
	    a = a & 1;        //AND operation with 0001, making 2,3,4 bit 0
	    return a;
}
BYTE bit2check(int b)
{
	    b = b & 2;        //AND with 0010 i.e making 1,3,4 bit 0
	    b = b >> 1;     //Right shift by 1 bit i.e cutting last digit
	    return b;
}
BYTE bit3check(int c)
{
	    c = c & 4;        //AND with 0100 i.e making 1,2,4 bit 0
	    c = c >> 2;       //Right shift 2 dights i.e cutting last two digit
	    return c;
}
BYTE bit4check(int d)
{
	    d = d >> 3;      //Right shift 3 dights i.e cutting last three digit
	    return d;
}