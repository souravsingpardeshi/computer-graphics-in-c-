#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
 
void boundaryfill(int x,int y,int f_color,int b_color)
{
    if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
    {
        putpixel(x,y,f_color);
        boundaryfill(x+1,y,f_color,b_color);
        boundaryfill(x,y+1,f_color,b_color);
        boundaryfill(x-1,y,f_color,b_color);
        boundaryfill(x,y-1,f_color,b_color);
    }
}
//getpixel(x,y) gives the color of specified pixel 
 
int main()
{
    int gm,gd=DETECT,radius;
    int x,y;
    initgraph(&gd,&gm,"c:/tc/bgi");
    
    printf("Enter x and y positions for circle\n");
    scanf("%d%d",&x,&y);
    printf("Enter radius of circle\n");
    scanf("%d",&radius);
    circle(300+x,300+y,radius);
    boundaryfill(300+x,300+y,4,15);
    delay(5000);
    closegraph();
    
    return 0;
}