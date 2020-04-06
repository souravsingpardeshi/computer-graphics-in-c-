#include<stdio.h>
int main()
{
	int i,*j,**k;
	i=100;
	j=&i;
	k=&j;
	printf("\nAddress of i is %u ",&i);
	printf("\nAddress of i is %u ",j);
	printf("\naddress of j is %u ",k);
	printf("\nAddress of j is %u ",*(&k));
	printf("\nAddress of j is %u ",&j);
	printf("\nAddress of k is %u \n\n",&k);
return 0;
}
