#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
    putpixel(x0 + x, y0 + y, 7);
    putpixel(x0 + y, y0 + x, 7);
    putpixel(x0 - y, y0 + x, 7);
    putpixel(x0 - x, y0 + y, 7);
    putpixel(x0 - x, y0 - y, 7);
    putpixel(x0 - y, y0 - x, 7);
    putpixel(x0 + y, y0 - x, 7);
    putpixel(x0 + x, y0 - y, 7);
 
    if (err <= 0)
    {
        y += 1;
        err += 2*y + 1;
    }
 
    if (err > 0)
    {
        x -= 1;
        err -= 2*x + 1;
    }
    }
}


void main() {
    int gdriver=DETECT,gmode,r,x,y;
     initgraph(&gdriver,&gmode,"c:/tc/bgi");
   printf("-Mid point circle Drawing-\n");
    printf("Enter radius of circle: ");
    scanf("%d", &r);
 
    printf("Enter co-ordinates of center(x and y): ");
    scanf("%d%d", &x, &y);
    drawcircle(x, y, r);
    getch();
closegraph();

}