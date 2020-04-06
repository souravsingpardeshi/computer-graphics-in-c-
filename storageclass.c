#include<stdio.h>
void display();
int p;
int main()
{
	display();
	display();
	display();
	return 0;
}
void display()
{
	static int k=10;
	auto int i=1;
	register int j=1;

	printf("\n\n static value of i is %d",i);
	printf("\n auto value of j is %d",j);
	printf("\n register value of k is %d",k);
	p=p+1;
	printf("\n value of p is %d",p);
	i--;
	j++;
	k++;
}
