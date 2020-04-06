#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void main(){
int gdriver=DETECT,gmode;

    int x0,y0,xn,yn,xp,yp,p0,pk,x,y,itr=0;
    initgraph(&gdriver,&gmode,"c:/tc/bgi");
   printf("-Bresenham Line Drawing-\n");
    printf("Enter x0:");
    scanf("%d",&x0);
    printf("Enter y0:");
    scanf("%d",&y0);

    printf("Enter xn:");
    scanf("%d",&xn);
    printf("Enter yn:");
    scanf("%d",&yn);

    //calculate intial decision parameter

    p0 = 2*(yn-y0) - (xn-x0);
    printf("\nSolution:\np0 = %d",p0);

    x=x0;
    y=y0;
    pk=p0;

  //  printf("\nitr\tx\ty\tpk\n");
    while(x!=xn||y!=yn){
	if(pk<0){
	    pk = p0 + (2*(yn-y0));
	    x=x+1;
	    putpixel(x,y,WHITE);
    //	     printf("%d\t%d\t%d\t%d\n",++itr,x,y,p0);
	    p0=pk;
	}else if(pk>0){
	    pk = p0 + ((2*(yn-y0))-(2*(xn-x0)));
	    x=x+1;
	    y=y+1;
	    putpixel(x,y,WHITE);
      //	     printf("%d\t%d\t%d\t%d\n",++itr,x,y,p0);
	    p0=pk;
	}
    }
getch();
closegraph();
}