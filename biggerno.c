#include<stdio.h>
#define BIGGER(x,y) (x>y)
int main()
{
int x,y;
printf("Enter two numbers : ");
scanf("%d,%d",&x,&y);
if (BIGGER(x,y))
 printf("first number is bigger");
else
printf("second number is bigger");
return 0;
}
