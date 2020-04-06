#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
int round(float n){
 if(n<0.5)return (int)n;
 return (int)n+1;
}

void main(){
int gdriver=DETECT,gmode;
float m;
float x0, y0,xn,yn,x,y;
initgraph(&gdriver,&gmode,"c:/tc/bgi");

printf("-DDA Line Drawing-\n");
printf("Enter the value of x0:");
    scanf("%f",&x0);
    printf("Enter the value of y0:");
    scanf("%f",&y0);
    printf("Enter the value of xn:");
    scanf("%f",&xn);
    printf("Enter the value of yn:");
    scanf("%f",&yn);
    x=x0;
    y=y0;

    m = (yn-y0)/(xn-x0);
    printf("m = %f \n ",m);

    if(m<1){
	while(x<=xn&&y<=yn){
		putpixel((int)x,(int)y,WHITE);
	    // printf("x=%d , y=%d \n",(int)x,(int)y);
	    x=x0+1;
	    y=round(y0+m);
	    x0=x;
	    y0=y0+m;
	}
    }else if(m>1){
	while(x<=xn&&y<=yn){
		putpixel((int)x,(int)y,WHITE);
	    // printf("x=%d , y=%d \n",(int)x,(int)y);
	    x=round(x0+(1/m));
	    y=y0+1;
	    x0=x0+(1/m);
	    y0=y;
	}
    }else{
	while(x<=xn&&y<=yn){
		putpixel(200+(int)x,200+(int)y,WHITE);
	    // printf("x=%d , y=%d \n",(int)x,(int)y);
	    x=x0+1;
	    y=y0+1;
	    x0=x;
	    y0=y;
	}
    }

getch();
closegraph();


}