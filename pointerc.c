#include<stdio.h>
int main()
{
	int i,*j;
	j=&i;
	printf("Enter any value for i : ");
	scanf("%d",&i);
	printf("Value of i is %d",i);
	printf("\nvalue of i is %d",*(&i));
	printf("\nvalue of i is %d",*j);
	printf("\naddress of i is %d",j);
	printf("\n\n");
	return 0;

}
