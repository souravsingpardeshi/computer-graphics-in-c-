#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
 int i, gm,gd;
 int x1, x2, y1, y2, xmin, xmax, ymin, ymax, xx1, xx2, yy1, yy2;
 float t1, t2, p[4], q[4], temp;
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"C:/tc/bgi/");
 xmin=150;
 xmax=450;
 ymin=100;
 ymax=400;
 rectangle(xmin,ymin,xmax,ymax);

 printf("Enter the starting point: ");
 scanf("%d%d",&x1,&y1);
 printf("Enter the ending point: ");
 scanf("%d%d",&x2,&y2);
 printf("Line before clipping:");
 line(x1,y1,x2,y2);
 getch();
 clrscr();

 printf("Line after clipping:");
 rectangle(xmin,ymin,xmax,ymax);

 p[0]=-(x2-x1);
 p[1]=(x2-x1);
 p[2]=-(y2-y1);
 p[3]=(y2-y1);
 q[0]=(x1-xmin);
 q[1]=(xmax-x1);
 q[2]=(y1-ymin);
 q[3]=(ymax-y1);








 for(i=0;i<4;i++)
 {
            if(p[i]==0)
            {
                        printf("\nLine is parallel to one of the clipping boundary");
                        if(q[i]>=0)
                        {
                                    if(i<2)
                                    {
                                         if(y1<ymin)
                                         {
                                                y1=ymin;
                                         }
                                         if(y2>ymax)
                                         {
                                                y2=ymax;
                                         }
                                         line(x1,y1,x2,y2);
                                    }
                                    if(i>1)
                                    {
                                         if(x1<xmin)
                                         {
                                                x1=xmin;
                                         }
                                         if(x2>xmax)
                                         {
                                                x2=xmax;
                                         }
                                         line(x1,y1,x2,y2);
                                    }
                        }
                        getch();
			closegraph();
             }
 }
 }